//
//  main.m
//  xcproject
//
//  Created by Brian K Garrett on 11/1/13.
//  Copyright (c) 2013 BinaryAge. All rights reserved.
//

#import "GBSettings+XCProject.h"

XCProjectKeys keys;

bool isString(id object) { if (!object) return false; return [object isKindOfClass:[NSString class]]; }
bool isNumber(id object) { if (!object) return false; return [object isKindOfClass:[NSNumber class]]; }

PBXProject* projectWithSettings(GBSettings* settings) {
  if (!settings) return nil;
  NSString* projectArg = [settings objectForKey:keys.project];
  if (!projectArg) {
    return nil;
  }

  if (![projectClass() isProjectWrapperExtension:projectArg.pathExtension]) {
    return nil;
  }

  NSFileManager* FM = [NSFileManager defaultManager];
  NSString* path = nil;

  if (!projectArg.isAbsolutePath) {
    path = [FM.currentDirectoryPath stringByAppendingPathComponent:projectArg].stringByStandardizingPath;
  } else {
    path = projectArg.stringByStandardizingPath;
  }

  if (![FM fileExistsAtPath:path]) {
    return nil;
  }

  ScopedStdErrRedirect redirect;

  return [projectClass() projectWithFile:path];
}

PBXTarget* targetWithProjectAndSettings(PBXProject* project, GBSettings* settings) {
  if (!project || !settings) return nil;
  if (![settings objectForKey:keys.target]) {
    return nil;
  }

  PBXTarget* target = [project targetNamed:[settings objectForKey:keys.target]];

  if (!target) {
    for (PBXTarget* _target in [project allTargetsInDependencyOrder]) {
      if ([_target.name isEqualToString:[settings objectForKey:keys.target]]) {
        target = _target;
      }
    }
  }

  return target;
}

NSString* normalizeColonSeparatedList(NSString* list) {
  if (!list || !stringContainsStringLike(list, @":")) return list;
  NSMutableCharacterSet* characters = [NSMutableCharacterSet whitespaceAndNewlineCharacterSet];
  [characters addCharactersInString:@":"];
  return [list stringByTrimmingCharactersInSet:characters];
}

StringVector splitStringList(NSString* list) {
  list = normalizeColonSeparatedList(list);
  StringVector strings;

  while (list.length) {
    NSRange range = [list rangeOfString:@":"];
    if (range.location == NSNotFound || range.length == 0) {
      strings.push_back(list);
      list = @"";
    } else {
      NSString* str = [list substringToIndex:range.location];
      strings.push_back(str);
      if (list.length >= range.location + range.length) {
        list = [list substringFromIndex:range.location + range.length];
      } else {
        list = @"";
      }
    }
  }

  return strings;
}

// Search the project structure for group(s)
PBXGroup* findGroup(PBXGroup* root, StringVector& groups) {
  if (!root || groups.empty()) return nil;
  if ([root.name isEqualToString:groups.front()]) return root;

  PBXGroup* group = nil;
  for (PBXGroup* _group in [root groups]) {
    if ([_group.name isEqualToString:groups.front()]) {
      group = _group;
      break;
    }
  }

  if (group) {
    groups.erase(groups.cbegin());
    if (groups.size()) {
      PBXGroup* _group = findGroup(group, groups);
      if (_group) group = _group;
    }
  }

  return group ? group : root;
}

// Search for group(s); adding groups if they are missing
PBXGroup* getOrCreateGroup(PBXGroup* root, StringVector& groups) {
  PBXGroup* group = findGroup(root, groups);
  if (!group) return nil;

  if (groups.size()) {
    for (StringVector::iterator i = groups.begin(); i != groups.end(); i++) {
      PBXGroup* _g = [group createNewGroupAtIndex:0];
      if (!_g) return nil;
      [_g setName:*i];
      group = _g;
    }

    groups.clear();
  }

  return group;
}

void standardizePaths(StringVector& paths) {
  if (paths.empty()) return;

  for (size_t i = 0; i < paths.size(); i++) {
    StringRef& file = paths[i];
    StringRef file2;

    if (![file isAbsolutePath]) {
      file2 = [[NSFileManager defaultManager].currentDirectoryPath stringByAppendingPathComponent:file].stringByStandardizingPath;
    } else {
      file2 = [file stringByStandardizingPath];
    }

    if (file != file2) paths[i] = file2;
  }
}

void listConfiguration(XCBuildConfiguration* config, GBSettings* settings) {
  if (!config || !settings) return;

  if ([settings boolForKey:keys.xcconfig]) {
    // print base config file
    PBXFileReference* baseConfig = [config baseConfigurationReference];
    std::cout << baseConfig.absolutePath << std::endl;
  } else if (isString(settings[keys.configuration])) {
    // print settings values
    std::cout << config.flattenedBuildSettings << std::endl;
  } else if (isNumber(settings[keys.configuration]) && [settings boolForKey:keys.configuration]) {
    // print configuration name
    std::cout << config.name << std::endl;
  }
}

void listConfigurationList(XCConfigurationList* configList, GBSettings* settings) {
  if (!configList || !settings) return;
  id configurationSettings = settings[keys.configuration];
  if (isNumber(configurationSettings) && [configurationSettings boolValue]) {
    // List all configs
    for (XCBuildConfiguration* config in [configList buildConfigurations]) {
      listConfiguration(config, settings);
    }
  } else if (isString(configurationSettings)) {
    // List config with name
    if (![configList buildConfigurationExistsForName:configurationSettings]) return;
    listConfiguration([configList buildConfigurationForName:configurationSettings], settings);
  }
}

void listTarget(PBXTarget* target, GBSettings* settings) {
  if (!target || !settings) return;
  // print target info
  if (settings[keys.configuration]) {
    listConfigurationList([target buildConfigurationList], settings);
  } else {
    std::cout << target.name << std::endl;
    if ([settings boolForKey:keys.verbose]) {
      // Print more info about target
    }
  }
}

void listGroup(PBXGroup* group, GBSettings* settings) {
  if (!group || !settings) return;
  std::cout << group.name << std::endl;
  if ([settings boolForKey:keys.files]) {
    NSArray* allrefs = [group fileReferences];
    for (PBXFileReference* ref in allrefs) {
      std::cout << ref.name << " (" << ref.absolutePath << ")" << std::endl;
    }
  }
}

int main(int argc, const char * argv[]) {
  @autoreleasepool {
    
    CommanderAutoRunner autorunner;

    
#pragma mark - list

    OptionDefinitionVector listOpts = {
      { 'f', keys.files,            @"List files",                              GBValueNone },
      { 'x', keys.xcconfig,         @"List base xcconfig files",                GBValueNone },
      { 'd', keys.dependencies,     @"List all dependent targets",              GBValueNone },

      { 0,	 nil,                   @"Project specifiers",                      GBOptionSeparator },
      { 'p', keys.project,          @"Specify the project",                     GBValueRequired },
      { 'c', keys.configuration,    @"Specify or list configurations",          GBValueOptional },
      { 't', keys.target,           @"Specify or list targets",                 GBValueOptional },
      { 'g', keys.group,            @"Specify or list groups",                  GBValueOptional }
    };

    Command& list = commander.addCommand({"list", "List the contents of the specified project", listOpts});
    list.addGlobalOption({ 'v', keys.verbose, @"Print more information", GBValueNone});
    list.setRunBlock(^int(StringVector args, GBSettings *settings, Command &command) {
      PBXProject* project = projectWithSettings(settings);
      if (!project) return 2;

      id configurationSetting = settings[keys.configuration];
      id targetSetting = settings[keys.target];
      id groupSetting = settings[keys.group];

      if (configurationSetting && (!targetSetting)) {
        listConfigurationList([project buildConfigurationList], settings);
      }

      if (isString(targetSetting)) {
        listTarget(targetWithProjectAndSettings(project, settings), settings);
      } else if ([settings boolForKey:keys.target]) {
        for (PBXTarget* target in [project targets]) {
          listTarget(target, settings);
        }
      }

      if (isString(groupSetting)) {
        // List group info
        //  if settings[@"files"] -> List all files within group
        StringVector groups = splitStringList(groupSetting);
        listGroup(findGroup([project rootGroup], groups), settings);
      } else if ([settings boolForKey:keys.group]) {
        for (PBXGroup* group in [[project rootGroup] groups]) {
          listGroup(group, settings);
        }
      }

      return 0;
    });

    
#pragma mark - add

    OptionDefinitionVector addOpts = {
      { 'n', keys.dry,              @"Only show what the results would be",                                     GBValueNone },
      { 'v', keys.verbose,          @"Print status",                                                            GBValueNone },

      { 'c', keys.copy,             @"Copy files into project directory",                                       GBValueNone },
      { 'T', keys.type,             @"Specify the type of item to add",                                         GBValueRequired },

      { 0,	 nil,                   @"Project specifiers",                                                      GBOptionSeparator },
      { 'p', keys.project,          @"Specify the project",                                                     GBValueRequired },
      { 't', keys.target,           @"Specify a target",                                                        GBValueRequired },
      { 'g', keys.group,            @"Specify a group/colon separated list of groups",                          GBValueRequired }
    };
    
    Command& add = commander.addCommand({"add", "Add a project item", addOpts});
    add.setRunBlock(^int(StringVector args, GBSettings *settings, Command &command) {
      if (args.empty()) return 2;
      NSString* type = [settings objectForKey:keys.type];

      if (!stringContainsStringLike(type, keys.group)) standardizePaths(args);

      PBXProject* project = projectWithSettings(settings);
      if (!project) return 2;

      if ([settings objectForKey:keys.target]) {
        PBXTarget* target = targetWithProjectAndSettings(project, settings);
        project = [target project];
      }

      PBXGroup* group = nil;
      NSString* groupName = [settings objectForKey:keys.group];
      StringVector groups = splitStringList(groupName);
      if (groups.size()) group = findGroup([project rootGroup], groups);
      if (!group) return 2;

      if (stringContainsStringLike(type, keys.group)) {
        for (auto const& arg:args) {
          groups.push_back(arg);
        }

        PBXGroup* _group = getOrCreateGroup(group, groups);
        if (!_group) return 2;

        return ![_group.name isEqualToString:groupName];
      } else {
        NSArray* refs = [group addFiles:[NSArray stringsFromStringVector:&args] copy:[settings boolForKey:keys.copy] createGroupsRecursively:YES];
        if (settings.verbose) {
          for (PBXFileReference* ref in refs) {
            std::cout << "Added " << ref.name << " (" << ref.path << ") to " << group.name << std::endl;
          }
        }

        return refs.count == 0;
      }

      return 0;
    });


#pragma mark - remove

    OptionDefinitionVector removeOpts = {
      { 'n', keys.dry,              @"Only show what the results would be",                                     GBValueNone },
      { 'v', keys.verbose,          @"Print status",                                                            GBValueNone },
      { 'd', keys.trash,            @"Also move items to trash",                                                GBValueNone },

      { 0,	 nil,                   @"Project specifiers",                                                      GBOptionSeparator },
      { 'p', keys.project,          @"Specify the project",                                                     GBValueRequired }
    };

    Command& remove = commander.addCommand({"remove", "Remove a project item", removeOpts});
    remove.addSyntax("remove [-nvd] -p <project> PATH [...]");
    remove.setRunBlock(^int(bg::StringVector args, GBSettings *settings, bg::Command &command) {
      if (args.empty()) return 2;

      PBXProject* project = projectWithSettings(settings);
      if (!project) return 2;

      for (auto const& arg:args) {
        PBXReference* ref = [project relativeFileReferenceForPath:arg];
        if (!ref) continue;
        if (![settings boolForKey:keys.dry]) {
          [ref deleteFromProjectAndDisk:[settings boolForKey:keys.trash]];
        }
      }

      return 0;
    });


#pragma mark - set-config

    OptionDefinitionVector setConfigOpts = {
      { 'a', keys.add,              @"Add any missing items to project",                                        GBValueNone },
      { 'd', keys.dry,              @"Only show what the results would be",                                     GBValueNone },
      { 'r', keys.replace,          @"Replace an existing xcconfig",                                            GBValueNone },
      { 'v', keys.verbose,          @"Print status",                                                            GBValueNone },
      { 'C', keys.copy,             @"Copy files into project directory",                                       GBValueNone },
      
      { 0,   nil,                   @"Project specifiers",                                                      GBOptionSeparator },
      { 'p', keys.project,          @"Specify the project",                                                     GBValueRequired },
      { 'c', keys.configuration,    @"Specify a configuration",                                                 GBValueRequired },
      { 't', keys.target,           @"Specify a target",                                                        GBValueRequired },
      { 'g', keys.group,            @"Specify a group/colon separated list of groups",                          GBValueRequired }
    };

    Command& setConfig = commander.addCommand({"set-config", "Set the base configuration of target to an xcconfig", setConfigOpts});
    setConfig.addSyntax("set-config -adrv -p <project> -c <configuration> [-t <target>] [-g <group>] FILE");
    setConfig.setRunBlock(^int(StringVector args, GBSettings *settings, Command &command) {
      if (args.size() != 1) return 2;

      StringRef& newConfigFile = args[0];
      NSString* configPath = nil;

      if (![newConfigFile isAbsolutePath]) {
        configPath = [[[[NSFileManager defaultManager] currentDirectoryPath] stringByAppendingPathComponent:newConfigFile] stringByStandardizingPath];
      } else {
        configPath = [newConfigFile stringByStandardizingPath];
      }

      PBXProject* project = projectWithSettings(settings);
      if (!project) return 2;

      XCConfigurationList* configList = nil;

      if ([settings objectForKey:keys.target]) {
        PBXTarget* target = targetWithProjectAndSettings(project, settings);
        project = [target project];
        configList = [target buildConfigurationList];
      } else {
        configList = [project buildConfigurationList];
      }

      if (!configList) return 2;

      NSString* configName = [settings objectForKey:keys.configuration];
      if (!configName) return 2;

      if (![configList buildConfigurationExistsForName:configName]) {
        if (![settings boolForKey:keys.add]) return 2;
        [configList addBuildConfiguration:[[buildConfigurationClass() alloc] initWithName:configName]];
      }

      XCBuildConfiguration* config = [configList buildConfigurationForName:configName];
      if (!config) return 2;

      PBXFileReference* baseConfigRef = [config baseConfigurationReference];

      if (baseConfigRef && [baseConfigRef.absolutePath isEqualToString:configPath]) return 0;
      if (baseConfigRef && ![settings boolForKey:keys.replace]) return 2;

      // Look for file in project
      PBXFileReference* configRef = [project fileReferenceForPath:configPath];

      if (!configRef) {
        StringVector groups = splitStringList(settings[keys.group]);
        PBXGroup* group = getOrCreateGroup([project rootGroup], groups);
        if (!group) group = [project rootGroup];
        if (!group) return 2;

        NSArray* refs = [group addFiles:@[configPath] copy:[settings boolForKey:keys.copy] createGroupsRecursively:NO];
        if (refs && refs.count) {
          configRef = refs[0];
        }
      }

      if (!configRef) return 2;

      [config setBaseConfigurationReference:configRef];

      if (settings.dry) {
        std::cout << "Successfully set configuration" << std::endl;
      } else {
        return ![project writeToFileSystemProjectFile:YES userFile:NO checkNeedsRevert:NO];
      }

      return 0;
    });
  }
  return 0;
}

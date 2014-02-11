//
//  main.m
//  xcproject
//
//  Created by Brian K Garrett on 11/1/13.
//  Copyright (c) 2013 BinaryAge. All rights reserved.
//

#import "GBSettings+XCProject.h"

XCProjectKeys keys;

bool isArray(id object) { if (!object) return false; return [object isKindOfClass:[NSArray class]]; }
bool isString(id object) { if (!object) return false; return [object isKindOfClass:[NSString class]]; }
bool isNumber(id object) { if (!object) return false; return [object isKindOfClass:[NSNumber class]]; }

#pragma mark - Project Items

PBXProject* projectWithPath(NSString* path) {
  ScopedStdErrRedirect redirect;
  return [projectClass() projectWithFile:path];
}

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

  PBXProject* project = projectWithPath(path);
  if (!project) die(ItemNotFound, @"No project found at %@", path);

  return project;
}

PBXTarget* targetWithProjectAndName(PBXProject* project, NSString* targetName) {
  if (!project || !targetName) return nil;

  PBXTarget* target = [project targetNamed:targetName];

  if (!target) {
    for (PBXTarget* _target in [project allTargetsInDependencyOrder]) {
      if ([_target.name isEqualToString:targetName]) {
        target = _target;
      }
    }
  }

  return target;
}

PBXTarget* targetWithProjectAndSettings(PBXProject* project, GBSettings* settings) {
  return targetWithProjectAndName(project, settings[keys.target]);
}

XCBuildConfiguration* configurationForName(id object, NSString* config) {
  if ([object isKindOfClass:[PBXProject class]] || [object isKindOfClass:[PBXTarget class]]) {
    XCConfigurationList* configs = [object buildConfigurationList];
    if ([configs buildConfigurationExistsForName:config]) {
      return [configs buildConfigurationForName:config];
    }
  }

  return nil;
}

#pragma mark - Group Helpers

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
  if (!root) return nil;
  if (groups.empty()) return root;

  PBXGroup* group = nil;
  for (PBXGroup* _group in [root groups]) {
    if ([_group.name isEqualToString:groups.front()]) {
      groups.erase(groups.cbegin());
      group = findGroup(_group, groups);
      break;
    }
  }

  return group ? group : root;
}

// Search for group(s); adding groups if they are missing
PBXGroup* getOrCreateGroup(PBXGroup* root, StringVector& groups, GBSettings* settings) {
  PBXGroup* group = findGroup(root, groups);
  if (!group) return nil;

  if (groups.size()) {
    NSUInteger index = settings[keys.index] ? [settings unsignedIntegerForKey:keys.index] : 0;
    for (StringVector::iterator i = groups.begin(); i != groups.end(); i++) {
      PBXGroup* _g = [group createNewGroupAtIndex:(index<group.itemCount?index:0)];
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

#pragma mark - List Helpers

void listConfiguration(XCBuildConfiguration* config, id configSetting, GBSettings* settings) {
  if (!config || !configSetting || !settings) return;

  if ([settings boolForKey:keys.xcconfig]) {
    // print base config file
    PBXFileReference* baseConfig = [config baseConfigurationReference];
    if (baseConfig) std::cout << baseConfig.absolutePath << std::endl;
  } else if (isString(configSetting) && [config.name isEqualToString:configSetting]) {
    // print settings values
    std::cout << config.flattenedBuildSettings << std::endl;
  } else if (isNumber(configSetting) && [configSetting boolValue]) {
    // print configuration name
    std::cout << config.name << std::endl;
  }
}

void listConfigurationList(XCConfigurationList* configList, id configSetting, GBSettings* settings) {
  if (!configList || !configSetting || !settings) return;

  if (isNumber(configSetting) && [configSetting boolValue]) {
    // List all configs
    for (XCBuildConfiguration* config in [configList buildConfigurations]) {
      listConfiguration(config, configSetting, settings);
    }
  } else if (isString(configSetting)) {
    // List config with name
    if (![configList buildConfigurationExistsForName:configSetting]) return;
    listConfiguration([configList buildConfigurationForName:configSetting], configSetting, settings);
  }
}

void listTarget(PBXTarget* target, GBSettings* settings) {
  if (!target || !settings) return;
  // print target info
  for (NSString* configSetting in settings[keys.configuration]) {
    listConfigurationList([target buildConfigurationList], configSetting, settings);
  }

  if ([settings[keys.configuration] count] == 0) {
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

    {
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

      Command& list = commander.addCommand("list", "List the contents of the specified project", listOpts);
      list.addGlobalOption({ 'V', keys.verbose, @"Print more information", GBValueNone});
      list.registerArrayForKey(keys.configuration);
      list.registerArrayForKey(keys.target);
      list.registerArrayForKey(keys.group);
      list.setRunBlock(^int(StringVector args, GBSettings *settings, Command &command) {
        PBXProject* project = projectWithSettings(settings);

        NSArray* configurationSettings = settings[keys.configuration];
        NSArray* targetSettings = settings[keys.target];
        NSArray* groupSettings = settings[keys.group];

        if ([targetSettings count] == 0) {
          for (id configSetting in configurationSettings) {
            listConfigurationList([project buildConfigurationList], configSetting, settings);
          }
        }

        for (id targetSetting in targetSettings) {
          if (isString(targetSetting)) {
            listTarget(targetWithProjectAndName(project, targetSetting), settings);
          } else if (isNumber(targetSetting) && [targetSetting boolValue]) {
            for (PBXTarget* target in [project targets]) {
              listTarget(target, settings);
            }
          }
        }

        // TODO: This either should be removed or a better definition of what to list about groups
        for (id groupSetting in groupSettings) {
          if (isString(groupSetting)) {
            // List group info
            //  if settings[@"files"] -> List all files within group
            StringVector groups = @[groupSetting].stringVector;
            listGroup(findGroup([project rootGroup], groups), settings);
          } else if (isNumber(groupSetting) && [groupSetting boolValue]) {
            for (PBXGroup* group in [[project rootGroup] groups]) {
              listGroup(group, settings);
            }
          }
        }

        return 0;
      });
    }


#pragma mark - add

    {
      OptionDefinitionVector addOpts = {
        { 'n', keys.dry,              @"Only show what the results would be",                                     GBValueNone },
        { 'v', keys.verbose,          @"Print status",                                                            GBValueNone },

        { 'c', keys.copy,             @"Copy files into project directory",                                       GBValueNone },
        { 'r', keys.recursive,        @"Create groups recursively",                                               GBValueNone },
        { 'T', keys.type,             @"Specify the type of item to add",                                         GBValueRequired },
        { 'i', keys.index,            @"Specify the index of the added item",                                     GBValueRequired },

        { 0,	 nil,                   @"Project specifiers",                                                      GBOptionSeparator },
        { 'p', keys.project,          @"Specify the project",                                                     GBValueRequired },
        { 't', keys.target,           @"Specify a target",                                                        GBValueRequired },
        { 'g', keys.group,            @"Specify a group path",                                                    GBValueRequired }
      };

      Command& add = commander.addCommand("add", "Add a project item", addOpts);
      add.setRunBlock(^int(StringVector args, GBSettings *settings, Command &command) {
        if (args.empty()) return MissingArguments;
        NSString* type = [settings objectForKey:keys.type];

        if (!stringContainsStringLike(type, keys.group)) standardizePaths(args);

        PBXProject* project = projectWithSettings(settings);

        if ([settings objectForKey:keys.target]) {
          PBXTarget* target = targetWithProjectAndSettings(project, settings);
          project = [target project];
        }

        NSString* groupName = [settings objectForKey:keys.group];
        StringVector groups = [[groupName pathComponents] stringVector];
        PBXGroup* group = findGroup([project rootGroup], groups);
        if (!group) return 2;

        if (stringContainsStringLike(type, keys.group)) {
          for (auto const& arg:args) {
            groups.push_back(arg);
          }

          group = getOrCreateGroup(group, groups, settings);
          if (!group) return 2;
        } else {
          NSUInteger index = settings[keys.index] ? [settings unsignedIntegerForKey:keys.index] : 0;
          
          NSArray* refs = [group addFiles:[NSArray stringsFromStringVector:&args]
                                  atIndex:(index<group.itemCount?index:0)
                                     copy:[settings boolForKey:keys.copy]
                  createGroupsRecursively:[settings boolForKey:keys.recursive]];
          if (!refs || refs.count == 0) {
            return 2;
          }

          if (settings.verbose) {
            for (PBXFileReference* ref in refs) {
              std::cout << "Added " << ref.name << " (" << ref.path << ") to " << group.name << std::endl;
            }
          }
        }

        if (!settings.dry) {
          return ![project writeToFileSystemProjectFile:YES userFile:NO checkNeedsRevert:NO];
        }
        
        return 0;
      });
    }


#pragma mark - remove

    {
      OptionDefinitionVector removeOpts = {
        { 'n', keys.dry,              @"Only show what the results would be",                                     GBValueNone },
        { 'v', keys.verbose,          @"Print status",                                                            GBValueNone },
        { 'd', keys.trash,            @"Also move items to trash",                                                GBValueNone },

        { 0,	 nil,                   @"Project specifiers",                                                      GBOptionSeparator },
        { 'p', keys.project,          @"Specify the project",                                                     GBValueRequired }
      };

      Command& remove = commander.addCommand("remove", "Remove a project item", removeOpts);
      remove.addSyntax("remove [-nvd] -p <project> PATH [...]");
      remove.setRunBlock(^int(bg::StringVector args, GBSettings *settings, bg::Command &command) {
        if (args.empty()) return MissingArguments;

        PBXProject* project = projectWithSettings(settings);

        for (auto const& arg:args) {
          PBXReference* ref = [project relativeFileReferenceForPath:arg];
          if (!ref) continue;
          if (![settings boolForKey:keys.dry]) {
            [ref deleteFromProjectAndDisk:[settings boolForKey:keys.trash]];
          }
        }
        
        if (!settings.dry) {
          return ![project writeToFileSystemProjectFile:YES userFile:NO checkNeedsRevert:NO];
        }

        return 0;
      });
    }


#pragma mark - set-config

    {
      OptionDefinitionVector setConfigOpts = {
        { 'a', keys.add,              @"Add any missing items to project",                                        GBValueNone },
        { 'd', keys.dry,              @"Only show what the results would be",                                     GBValueNone },
        { 'r', keys.recursive,        @"Create groups recursively",                                               GBValueNone },
        { 'f', keys.force,            @"Replace an existing xcconfig",                                            GBValueNone },
        { 'v', keys.verbose,          @"Print status",                                                            GBValueNone },
        { 'C', keys.copy,             @"Copy files into project directory",                                       GBValueNone },

        { 0,   nil,                   @"Project specifiers",                                                      GBOptionSeparator },
        { 'p', keys.project,          @"Specify the project",                                                     GBValueRequired },
        { 'c', keys.configuration,    @"Specify a configuration",                                                 GBValueRequired },
        { 't', keys.target,           @"Specify a target",                                                        GBValueRequired },
        { 'g', keys.group,            @"Specify a group path",                                                    GBValueRequired }
      };

      Command& setConfig = commander.addCommand("set-config", "Set the base configuration of target to an xcconfig", setConfigOpts);
      setConfig.addSyntax("set-config -adrv -p <project> -c <configuration> [-t <target>] [-g <group>] FILE");
      setConfig.setDefaultSettingsValueForKey(keys.recursive, @NO);
      setConfig.setRunBlock(^int(StringVector args, GBSettings *settings, Command &command) {
        if (args.size() != 1) die(InvalidArguments, @"Invalid arguments");

        StringRef& newConfigFile = args[0];
        NSString* configPath = [newConfigFile expandPath];

        PBXProject* project = projectWithSettings(settings);

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
        if (baseConfigRef && ![settings boolForKey:keys.force]) return 2;

        // Look for file in project
        PBXFileReference* configRef = [project fileReferenceForPath:configPath];

        if (!configRef) {
          StringVector groups = [[settings[keys.group] pathComponents] stringVector];
          PBXGroup* group = getOrCreateGroup([project rootGroup], groups, settings);
          if (!group) group = [project rootGroup];
          if (!group) return 2;

          NSArray* refs = [group addFiles:@[configPath] copy:[settings boolForKey:keys.copy] createGroupsRecursively:[settings boolForKey:keys.recursive]];
          if (refs && refs.count) {
            configRef = refs[0];
          }
        }

        if (!configRef) return 2;
        
        [config setBaseConfigurationReference:configRef];
        
        if (!settings.dry) {
          return ![project writeToFileSystemProjectFile:YES userFile:NO checkNeedsRevert:NO];
        }
        
        return 0;
      });
    }


#pragma mark - print-settings

    {
      OptionDefinitionVector printSettingsOpts = {
        { 'e', keys.expanded,         @"Print expanded build setting value",                                      GBValueNone },

        { 0,   nil,                   @"Project specifiers",                                                      GBOptionSeparator },
        { 'p', keys.project,          @"Specify the project",                                                     GBValueRequired },
        { 'c', keys.configuration,    @"Specify a configuration",                                                 GBValueRequired },
        { 't', keys.target,           @"Specify a target",                                                        GBValueRequired }
      };

      Command& printSettings = commander.addCommand("print-settings", "Print individual build configuration values", printSettingsOpts);
      printSettings.addSyntax("print-settings -p <project> -t <target> [-c <configuration>] [...]");
      printSettings.setDefaultSettingsValueForKey(keys.configuration, @"Debug");
      printSettings.setRunBlock(^int(StringVector args, GBSettings *settings, bg::Command &command) {
        if (args.empty()) die(MissingArguments, @"No arguments");

        PBXProject* project = projectWithSettings(settings);

        PBXTarget* target = targetWithProjectAndSettings(project, settings);
        if (!target) die(ItemNotFound, @"No target named `%@` in %@", [settings objectForKey:keys.target], [settings objectForKey:keys.project]);

        id value = nil;

        if ([settings boolForKey:keys.expanded]) {
          for (auto const& settingName:args) {
            value = [target expandedCurrentValueForBuildSetting:settingName forConfigurationName:settings[keys.configuration]];
            if (value) std::cout << value << std::endl;
          }
          return 0;
        }

        XCBuildConfiguration* config = [[target buildConfigurationList] buildConfigurationForName:settings[keys.configuration]];
        if (!config) die(ItemNotFound, @"Failed to get build configuration");

        PBXBuildSettingsDictionary* build_settings = [config flattenedBuildSettings];
        if (!build_settings) die(ItemNotFound, @"Failed to get flattened build settings");

        for (auto const& settingName:args) {
          value = [build_settings buildSettingForKeyPath:settingName];
          if (value) std::cout << value << std::endl;
        }
        
        return 0;
      });
    }

    
  }
  return 0;
}

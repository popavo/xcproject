//
//  main.m
//  xcproject
//
//  Created by Brian K Garrett on 11/1/13.
//  Copyright (c) 2013 BinaryAge. All rights reserved.
//

#import "main.h"

int listf(BGStringVector args, GBSettings* options, BGCommand& command) {
  std::cout << __PRETTY_FUNCTION__ << std::endl << args << std::endl;
  return 0;
}

int addf(BGStringVector args, GBSettings* options, BGCommand& command) {
  std::cout << __PRETTY_FUNCTION__ << std::endl << args << std::endl;
  return 0;
}

int setConfigf(BGStringVector args, GBSettings* options, BGCommand& command) {
  std::cout << __PRETTY_FUNCTION__ << std::endl << args << std::endl;
  return 0;
}


int main(int argc, const char * argv[]) {
  @autoreleasepool {
    CommanderAutoRunner autorunner;

    BGOptionDefinitionVector listOpts = {
      { 0,	 nil,                 @"Project specifiers",                      GBOptionSeparator },
      { 'w', @"workspace",        @"Specify the workspace to read",           GBValueRequired },
      { 's', @"scheme",           @"Specify a scheme or list schemes",        GBValueOptional },
      { 'p', @"project",          @"Specify the project or list projects",    GBValueOptional },

      { 0,	 nil,                 @"Project Contents",                        GBOptionSeparator },
      { 'c', @"configuration",    @"Specify or list configurations",          GBValueOptional },
      { 't', @"target",           @"Specify or list targets",                 GBValueOptional },
      { 'g', @"group",            @"Specify or list groups",                  GBValueOptional },
      { 'f', @"files",            @"List files",                              GBValueNone },
      { 'x', @"xcconfigs",        @"List base xcconfig files",                GBValueNone }
    };

    BGCommand list("list", "List the contents of the specified workspace or project", listOpts);
    list.setRunFunction(listf);

    BGOptionDefinitionVector addOpts = {
      { 0,	 nil,                 @"Global add options",                      GBOptionSeparator },
      { 'd', @"dry",              @"Only show what the results would be",     GBValueNone },
      { 'o', @"overwrite",        @"Overwrite any existing item",             GBValueNone },
      { 'v', @"verbose",          @"Print status",                            GBValueNone },

      { 0,	 nil,                 @"Project specifiers",                      GBOptionSeparator },
      { 'w', @"workspace",        @"Specify the workspace to read",           GBValueRequired },
      { 's', @"scheme",           @"Specify a scheme",                        GBValueRequired },
      { 'p', @"project",          @"Specify the project",                     GBValueRequired },
      { 'c', @"configuration",    @"Specify a configuration",                 GBValueRequired },
      { 't', @"target",           @"Specify a target",                        GBValueRequired },
      { 'g', @"group",            @"Specify a group",                         GBValueRequired }
    };
    
    BGCommand add("add", "Add a project item", addOpts);
    add.setRunFunction(addf);

    BGOptionDefinitionVector setConfigOpts = {
      { 0,	 nil,                 @"Global add options",                      GBOptionSeparator },
      { 'd', @"dry",              @"Only show what the results would be",     GBValueNone },
      { 'v', @"verbose",          @"Print status",                            GBValueNone },
      { 'r', @"replace",          @"Replace an existing xcconfig",            GBValueNone },

      { 0,	 nil,                 @"Project specifiers",                      GBOptionSeparator },
      { 'w', @"workspace",        @"Specify the workspace to read",           GBValueRequired },
      { 's', @"scheme",           @"Specify a scheme",                        GBValueRequired },
      { 'p', @"project",          @"Specify the project",                     GBValueRequired },
      { 'c', @"configuration",    @"Specify a configuration",                 GBValueRequired },
      { 't', @"target",           @"Specify a target",                        GBValueRequired }
    };

    BGCommand setConfig("set-config", "Set the base configuration of target to an xcconfig", setConfigOpts);
    setConfig.setRunFunction(setConfigf);

    commander.addCommand(list);
    commander.addCommand(add);
    commander.addCommand(setConfig);
  }
  return 0;
}

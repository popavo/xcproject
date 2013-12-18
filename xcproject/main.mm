//
//  main.m
//  xcproject
//
//  Created by Brian K Garrett on 11/1/13.
//  Copyright (c) 2013 BinaryAge. All rights reserved.
//

#import "main.h"

int listf(BGStringVector args, GBSettings* options, BGCommand& command) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  command.printSettings();
  std::cout << "Args" << std::endl << args << std::endl;
  return 0;
}

int addf(BGStringVector args, GBSettings* options, BGCommand& command) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  command.printSettings();
  std::cout << "Args" << std::endl << args << std::endl;
  return 0;
}

int setConfigf(BGStringVector args, GBSettings* options, BGCommand& command) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  command.printSettings();
  std::cout << "Args" << std::endl << args << std::endl;
  return 0;
}


int main(int argc, const char * argv[]) {
  @autoreleasepool {
    CommanderAutoRunner autorunner;


#pragma mark - list

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

    BGCommand& list = commander.addCommand({"list", "List the contents of the specified workspace or project", listOpts});
    list.setRunFunction(listf);


#pragma mark - add

    BGOptionDefinitionVector addOpts = {
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
    
    BGCommand& add = commander.addCommand({"add", "Add a project item", addOpts});
    add.setRunFunction(addf);


#pragma mark - set-config

    BGOptionDefinitionVector setConfigOpts = {
      { 'd', @"dry",              @"Only show what the results would be",     GBValueNone },
      { 'r', @"replace",          @"Replace an existing xcconfig",            GBValueNone },
      { 'v', @"verbose",          @"Print status",                            GBValueNone },

      { 0,	 nil,                 @"Project specifiers",                      GBOptionSeparator },
      { 'w', @"workspace",        @"Specify the workspace to read",           GBValueRequired },
      { 's', @"scheme",           @"Specify a scheme",                        GBValueRequired },
      { 'p', @"project",          @"Specify the project",                     GBValueRequired },
      { 'c', @"configuration",    @"Specify a configuration",                 GBValueRequired },
      { 't', @"target",           @"Specify a target",                        GBValueRequired }
    };

    BGCommand& setConfig = commander.addCommand({"set-config", "Set the base configuration of target to an xcconfig", setConfigOpts});
    setConfig.setRunFunction(setConfigf);
    setConfig.addSyntax("set-config -drv -w <workspace> -s <scheme> -c <configuration> [-t <target>] FILE");
    setConfig.addSyntax("set-config -drv -p <project> -c <configuration> [-t <target>] FILE");
  }
  return 0;
}

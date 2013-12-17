//
//  main.m
//  xcproject
//
//  Created by Brian K Garrett on 11/1/13.
//  Copyright (c) 2013 BinaryAge. All rights reserved.
//

#import "main.h"

int main(int argc, const char * argv[]) {
  @autoreleasepool {
    CommanderAutoRunner autorunner;

    BGCommand list("list", "List the contents of the specified workspace or project");

    BGCommand addFile("add", "Add a file reference");

    BGCommand setConfig("set-config", "Set the base configuration of target to an xcconfig");

    commander.addCommand(list);
    commander.addCommand(addFile);
    commander.addCommand(setConfig);
  }
  return 0;
}

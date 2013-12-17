#import <dlfcn.h>
#import <mach-o/ldsyms.h>
#import <objc/runtime.h>
#import "XCProjectHelpers.h"

NSArray* getRunpathSearchPaths() {
  NSMutableArray *rpaths = [NSMutableArray array];
  NSString *rpath = nil;
  const struct mach_header_64 *header = &_mh_execute_header;
  intptr_t cursor = (intptr_t)header + sizeof(struct mach_header_64);
  struct segment_command_64 *segmentCommand = NULL;
  for (int i = 0; i < header->ncmds; i++, cursor += segmentCommand->cmdsize) {
    segmentCommand = (struct segment_command_64*)cursor;
    if (segmentCommand->cmd == LC_RPATH) {
      struct rpath_command *rpathComand = (struct rpath_command *)segmentCommand;
      rpath = [[NSString alloc] initWithUTF8String:((const char*)rpathComand + rpathComand->path.offset)];
      [rpaths addObject:rpath];
    }
  }
  return [rpaths copy];
}

void loadFrameworks(NSArray* rpaths) {
  BOOL loaded = NO;
  for (NSString *framework in @[ @"DVTFoundation.framework", @"IDEFoundation.framework", @"Xcode3Core.ideplugin" ]) {
		for (NSString *rpath in rpaths) {
			NSString *frameworkPath = [rpath stringByAppendingPathComponent:framework];
			NSBundle *frameworkBundle = [NSBundle bundleWithPath:frameworkPath];
			if (frameworkBundle) {
				NSError *loadError = nil;
				loaded = [frameworkBundle loadAndReturnError:&loadError];
				if (!loaded) die(@"The %@ %@ failed to load: %@\n", [framework stringByDeletingPathExtension], [framework pathExtension], loadError);
			}
		}
		if (!loaded) die(@"%@ not found. It probably means that you have deleted, moved or renamed the Xcode copy that compiled `xcproj`.\nSimply recompiling `xcproj` should fix this problem.\n", framework);
	}
}

typedef void (*IDEInit)(NSUInteger initializationOptions, NSError **error);

void callIDEInitialize() {
  IDEInit IDEInitialize = (IDEInit)dlsym(RTLD_DEFAULT, "IDEInitialize");
	if (IDEInitialize) {
		// Temporary redirect stderr to /dev/null in order not to print plugin loading errors
		// Adapted from http://stackoverflow.com/questions/4832603/how-could-i-temporary-redirect-stdout-to-a-file-in-a-c-program/4832902#4832902
		fflush(stderr);
		int saved_stderr = dup(STDERR_FILENO);
		int dev_null = open("/dev/null", O_WRONLY);
		dup2(dev_null, STDERR_FILENO);
		close(dev_null);
		NSError *error = nil;
		// -[Xcode3CommandLineBuildTool run] from Xcode3Core.ideplugin calls IDEInitialize(1, &error)
		IDEInitialize(1, &error);
		fflush(stderr);
		dup2(saved_stderr, STDERR_FILENO);
		close(saved_stderr);
		if (error) die(@"IDEInitialize error: %@\n", error);
  } else {
    die(@"IDEInitialize function not found.\n");
  }
}

void loadAndInitializeFrameworkBundles() {
  NSArray* rpaths = getRunpathSearchPaths();
  loadFrameworks(rpaths);
  callIDEInitialize();
}


PBXProject* loadProject(NSString* projectPath) {
  PBXProject* proj = [PBXProject projectWithFile:projectPath];

  return proj;
}
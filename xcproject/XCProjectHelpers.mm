#import <dlfcn.h>
#import <mach-o/ldsyms.h>
#import <objc/runtime.h>
#import "XCProjectHelpers.h"
#import "CommanderHelpers.h"

NSString* getXcodePath() {
  NSString* path = nil;

  if (![[NSFileManager defaultManager] fileExistsAtPath:@"/usr/bin/xcode-select"]) {
    return path;
  }

  NSTask* xcode_select = [[NSTask alloc] init];

  [xcode_select setLaunchPath:@"/usr/bin/xcode-select"];
  [xcode_select setArguments:@[@"-p"]];
  [xcode_select setStandardOutput:[NSPipe pipe]];
  [xcode_select launch];

  NSData* pathData = [[xcode_select.standardOutput fileHandleForReading] readDataToEndOfFile];

  if (pathData) {
    path = [[[[NSString alloc] initWithData:pathData encoding:NSUTF8StringEncoding] stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] stringByDeletingLastPathComponent];
  }

  return path;
}

typedef void (*IDEInit)(NSUInteger initializationOptions, NSError **error);

void callIDEInitialize() {
  IDEInit IDEInitialize = (IDEInit)dlsym(RTLD_DEFAULT, "IDEInitialize");
	if (IDEInitialize) {
    ScopedStdErrRedirect redirect;
		NSError *error = nil;
		IDEInitialize(1, &error);
		if (error) die(@"IDEInitialize error: %@\n", error);
  } else {
    die(@"IDEInitialize function not found.\n");
  }
}

void loadAndInitializeFrameworkBundles() {
  BOOL loaded = NO;

  NSArray* frameworks = @[@"Frameworks/IDEFoundation.framework", @"OtherFrameworks/DevToolsCore.framework", @"SharedFrameworks/DVTFoundation.framework"];
  NSString* xcode = getXcodePath();

  for (NSString* framework in frameworks) {
    NSString* frameworkPath = [xcode stringByAppendingPathComponent:framework];
    NSBundle* frameworkBundle = [NSBundle bundleWithPath:frameworkPath];
    if (frameworkBundle) {
      NSError *loadError = nil;
      loaded = [frameworkBundle loadAndReturnError:&loadError];
      if (!loaded) die(@"The %@ %@ failed to load: %@\n", [[framework lastPathComponent] stringByDeletingPathExtension], [framework pathExtension], loadError);
    }
  }
  
  callIDEInitialize();
}
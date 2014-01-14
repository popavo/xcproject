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

@implementation NSString (XCProjectHelpers)

-(NSString*) relativePathFrom:(NSString*)path {
  if (!self || !path) return nil;
  NSArray *anchorComponents = [path pathComponents];
  NSArray *pathComponents = [self pathComponents];

  NSInteger componentsInCommon = MIN([pathComponents count], [anchorComponents count]);
  for (NSInteger i = 0, n = componentsInCommon; i < n; i++) {
    if (![[pathComponents objectAtIndex:i] isEqualToString:[anchorComponents objectAtIndex:i]]) {
      componentsInCommon = i;
      break;
    }
  }

  NSUInteger numberOfParentComponents = [anchorComponents count] - componentsInCommon;
  NSUInteger numberOfPathComponents = [pathComponents count] - componentsInCommon;

  NSMutableArray *relativeComponents = [NSMutableArray arrayWithCapacity:numberOfParentComponents + numberOfPathComponents];
  for (NSInteger i = 0; i < numberOfParentComponents; i++) {
    [relativeComponents addObject:@".."];
  }
  [relativeComponents addObjectsFromArray:[pathComponents subarrayWithRange:NSMakeRange(componentsInCommon, numberOfPathComponents)]];
  return [NSString pathWithComponents:relativeComponents];
}

-(NSString*) expandPath {
  if (!self) return nil;
  NSString* expanded = nil;
  if (!self.isAbsolutePath) {
    expanded = [[[[NSFileManager defaultManager] currentDirectoryPath] stringByAppendingPathComponent:self] stringByStandardizingPath];
  } else {
    expanded = [self stringByStandardizingPath];
  }
  return expanded;
}

-(NSString*) dirname {
  return self.stringByDeletingLastPathComponent;
}

@end
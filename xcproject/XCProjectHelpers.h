void loadAndInitializeFrameworkBundles();

// Temporary redirect stderr to /dev/null in order not to print plugin loading errors
// Adapted from http://stackoverflow.com/questions/4832603/how-could-i-temporary-redirect-stdout-to-a-file-in-a-c-program/4832902#4832902
class ScopedStdErrRedirect {
  int saved_stderr;
public:
  ScopedStdErrRedirect() {
    fflush(stderr);
    saved_stderr = dup(STDERR_FILENO);
    int dev_null = open("/dev/null", O_WRONLY);
    dup2(dev_null, STDERR_FILENO);
    close(dev_null);
  }

  ~ScopedStdErrRedirect() {
    fflush(stderr);
    dup2(saved_stderr, STDERR_FILENO);
    close(saved_stderr);
  }
};

struct XCProjectKeys {
  // Project specifiers
  NSString* project;
  NSString* configuration;
  NSString* target;
  NSString* group;

  // List
  NSString* files;
  NSString* xcconfig;

  // Add
  NSString* type;

  // Add/Set-config  
  NSString* dry;
  NSString* copy;

  // Set-config
  NSString* add;
  NSString* replace;

  // Global
  NSString* help;
  NSString* verbose;

  XCProjectKeys() : project(@"project"),
    configuration(@"configuration"),
    target(@"target"),
    group(@"group"),
    files(@"files"),
    xcconfig(@"xcconfig"),
    dry(@"dry"),
    copy(@"copy"),
    type(@"type"),
    add(@"add"),
    replace(@"replace"),
    help(@"help"),
    verbose(@"verbose") { }
};

extern XCProjectKeys keys;

#import <iostream>

inline std::ostream& operator <<(std::ostream& OS, NSString* string) {
  OS << string.UTF8String;
  return OS;
}

inline std::ostream& operator <<(std::ostream& OS, PBXProject* project) {
  OS << [project name] << " " << [project path] << " (" << [[project globalID] hexString] << ")";
  return OS;
}

inline std::ostream& operator <<(std::ostream& OS, id object) {
  OS << [NSString stringWithFormat:@"%@", object];
  return OS;
}

FORCE_INLINE NSString* relativePathTo(NSString* self, NSString* path) {
  NSArray *anchorComponents = [self pathComponents];
  NSArray *pathComponents = [path pathComponents];

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

#define MEMOIZED_CLASS_GETTER(CLASS, GETTER) \
  typedef Class CLASS ## Class; \
  FORCE_INLINE CLASS ## Class GETTER ## Class() { \
    static CLASS ## Class res = NSClassFromString(@# CLASS); \
    return res; \
  }

MEMOIZED_CLASS_GETTER(PBXProject, project);
MEMOIZED_CLASS_GETTER(XCBuildConfiguration, buildConfiguration);
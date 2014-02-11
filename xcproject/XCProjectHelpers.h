#import <type_traits>

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
  NSString* dependencies;

  // Add
  NSString* type;
  NSString* index;

  // Remove
  NSString* trash;

  // Add/Remove/Set-config
  NSString* dry;
  NSString* copy;
  NSString* recursive;

  // Set-config
  NSString* add;
  NSString* force;

  // Print-settings
  NSString* expanded;

  // Global
  NSString* help;
  NSString* verbose;

  XCProjectKeys() : project(@"project"),
    configuration(@"configuration"),
    target(@"target"),
    group(@"group"),
    files(@"files"),
    xcconfig(@"xcconfig"),
    dependencies(@"dependencies"),
    dry(@"dry"),
    copy(@"copy"),
    recursive(@"recursive"),
    type(@"type"),
    index(@"index"),
    add(@"add"),
    force(@"force"),
    expanded(@"expanded"),
    help(@"help"),
    verbose(@"verbose") { }
};

extern XCProjectKeys keys;

#import <iostream>

inline std::ostream& operator <<(std::ostream& OS, NSString* string) {
  OS << string.UTF8String;
  return OS;
}

inline std::ostream& operator <<(std::ostream& OS, PBXGlobalID* globalID) {
  OS << globalID.hexString;
  return OS;
}

inline std::ostream& operator <<(std::ostream& OS, PBXProject* project) {
  OS << [project name] << " " << [project path] << " (" << [project globalID] << ")";
  return OS;
}

inline std::ostream& operator <<(std::ostream& OS, id object) {
  OS << [NSString stringWithFormat:@"%@", object];
  return OS;
}

@interface NSString (XCProjectHelpers)

-(NSString*)relativePathFrom:(NSString*)path;

-(NSString*)expandPath;

-(NSString*)dirname;

@end

#define MEMOIZED_CLASS_GETTER(CLASS, GETTER) \
  typedef Class CLASS ## Class; \
  FORCE_INLINE CLASS ## Class GETTER ## Class() { \
    static CLASS ## Class res = NSClassFromString(@# CLASS); \
    return res; \
  }

MEMOIZED_CLASS_GETTER(PBXProject, project);
MEMOIZED_CLASS_GETTER(PBXTarget, target);
MEMOIZED_CLASS_GETTER(XCBuildConfiguration, buildConfiguration);
#import "GBSettings.h"
#import "GBOptionsHelper.h"
#import "GBCommandLineParser.h"

@interface GBSettings (XCProject)

+(GBSettings*)projectSettingsWithName:(NSString*)name parent:(GBSettings*)parent;

#pragma mark - Paths

@property (nonatomic, strong) NSArray *inputPaths;

@end

extern const struct GBSettingKeys {
	NSString *inputPaths;

  NSString* workspace;
  NSString* project;
  NSString* scheme;
  NSString* target;
  NSString* configuration;
  NSString* group;
} GBSettingKeys;
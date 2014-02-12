#import "PBXBuildStyle.h"

@class PBXBuildSettingsDictionary, PBXFileReference, XCFileSystemNode;

@interface XCBuildConfiguration : PBXBuildStyle {
  id _owner;
  BOOL _isHidden;
  PBXFileReference* _baseConfigurationReference;
  XCBuildConfiguration* _cachedBaseConfiguration;
  XCFileSystemNode* _cachedBaseConfigurationFileNode;
  PBXBuildSettingsDictionary* _cachedBaseConfigurationProperties;
  NSMutableArray* _cachedBaseConfigurationLoadErrors;
  NSDate* _baseConfigurationLastParsedTime;
  NSSet* _watchedBaseConfigurationFiles;
}

+ (XCBuildConfiguration*)buildConfigurationWithName:(NSString*)arg1 settings:(id)arg2;

+ (BOOL)fileReference:(PBXFileReference*)arg1 isValidBaseConfigurationFile:(id*)arg2;

- (id)initWithName:(NSString*)arg1;

- (id)baseBuildConfigurationReferenceLoadErrors;
- (PBXBuildSettingsDictionary*)parseBaseBuildConfigurationReferenceReturningErrors:(id*)arg1;
- (void)setBaseConfigurationReference:(PBXFileReference*)arg1;
- (PBXFileReference*)baseConfigurationReference;
- (id)flattenedBuildSettings;
- (id)buildSettingDictionariesAndGetErrors:(id*)arg1;
- (XCBuildConfiguration*)baseBuildConfiguration;
- (BOOL)couldBeActive;
- (void)setHidden:(BOOL)arg1;
- (BOOL)isHidden;
- (id)project;
- (id)buildConfigurationType;

@end

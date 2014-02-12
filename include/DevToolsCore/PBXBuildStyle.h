#import "PBXProjectItem.h"

@class PBXBuildSettingsDictionary, PBXProject;

@interface PBXBuildStyle : PBXProjectItem

- (id)initWithName:(NSString*)arg1;

- (NSString*)name;
- (void)setName:(NSString*)arg1;
- (NSInteger)compareName:(NSString*)arg1;

- (PBXBuildSettingsDictionary*)buildSettings;
- (void)setBuildSettings:(PBXBuildSettingsDictionary*)arg1;
- (id)flattenedBuildSettings;

- (id)container;
- (void)setContainer:(id)arg1;

- (id)buildSettingForKeyPath:(NSString*)arg1;
- (void)setBuildSetting:(id)arg1 forKeyPath:(NSString*)arg2;
- (void)removeBuildSettingForKeyPath:(NSString*)arg1;

@end

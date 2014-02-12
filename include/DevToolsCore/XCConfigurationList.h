#import "PBXProjectItem.h"

@interface XCConfigurationList : PBXProjectItem {
  NSMutableArray* _buildConfigurations;
  id _owner;
  NSString* _defaultConfigurationName;
  BOOL _defaultConfigurationIsVisible;
}

+ (XCConfigurationList*)configurationListWithConfigurations:(NSArray*)arg1;

- (id)initWithConfigurations:(NSArray*)arg1;

- (void)addBuildConfiguration:(XCBuildConfiguration*)arg1;
- (void)moveBuildConfigurationsAtIndexes:(id)arg1 toIndex:(NSUInteger)arg2;
- (void)removeObjectFromBuildConfigurationsAtIndex:(NSUInteger)arg1;
- (void)insertObject:(id)arg1 inBuildConfigurationsAtIndex:(NSUInteger)arg2;
- (NSUInteger)countOfBuildConfigurations;

- (NSArray*)buildConfigurationNames;
- (XCBuildConfiguration*)buildConfigurationForName:(NSString*)arg1;
- (BOOL)buildConfigurationExistsForName:(NSString*)arg1;
- (NSArray*)buildSettingDictionariesForConfigurationName:(NSString*)arg1 errors:(id*)arg2;
- (XCBuildConfiguration*)effectiveBuildConfigurationForName:(NSString*)arg1;

- (id)baseConfigurationList;
- (NSArray*)buildConfigurations;

- (NSString*)defaultConfigurationName;
- (XCBuildConfiguration*)defaultConfiguration;
- (void)setDefaultConfigurationName:(NSString*)arg1;

@end

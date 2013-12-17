#import <DevToolsCore/PBXProjectItem.h>
#import <DevToolsCore/XCCompatibilityChecking.h>

@interface XCConfigurationList : PBXProjectItem <XCCompatibilityChecking> {
    NSMutableArray *_buildConfigurations;
    id _owner;
    NSString *_defaultConfigurationName;
    BOOL _defaultConfigurationIsVisible;
}

+(id)archivableAttributes;
+(id)archivableRelationships;
+(id)configurationListWithConfigurations:(id)arg1;

-(id)initWithConfigurations:(id)arg1;

-(void)findFeaturesInUseAndAddToSet:(id)arg1 usingPathPrefix:(id)arg2;
-(BOOL)buildSettingsDictionaryShouldExtractQuotedBuildSettingsWhenSplitting:(id)arg1;
-(void)buildSettingsDictionary:(id)arg1 didSetValue:(id)arg2 withOperation:(int)arg3 forKeyPath:(id)arg4;
-(id)buildSettingsDictionary:(id)arg1 willSetValue:(id)arg2 withOperation:(int)arg3 forKeyPath:(id)arg4;
-(id)localBuildSettingsDictionariesForAllConfigurations;
-(id)flattenedBuildSettingDictionaryForConfigurationName:(id)arg1;
-(id)buildSettingDictionariesForConfigurationName:(id)arg1 errors:(id *)arg2;
-(void)baseConfigurationReferenceChangedForConfigurationNamed:(id)arg1;
-(id)effectiveBuildConfigurationForName:(id)arg1;
-(id)buildConfigurationForName:(id)arg1;
-(BOOL)buildConfigurationExistsForName:(id)arg1;
-(void)moveBuildConfigurationsAtIndexes:(id)arg1 toIndex:(unsigned long long)arg2;
-(void)removeObjectFromBuildConfigurationsAtIndex:(unsigned long long)arg1;
-(void)addBuildConfiguration:(id)arg1;
-(void)insertObject:(id)arg1 inBuildConfigurationsAtIndex:(unsigned long long)arg2;
-(id)buildConfigurationNames;
-(unsigned long long)countOfBuildConfigurations;
-(void)referenceWillBeRemoved:(id)arg1;
-(void)invalidateCaches;
-(id)container;
-(id)gidCommentForArchive;
-(void)_setBuildConfigurations:(id)arg1;
-(id)defaultConfiguration;
-(void)setDefaultConfigurationIsVisible:(BOOL)arg1;
-(BOOL)defaultConfigurationIsVisible;
-(void)setDefaultConfigurationName:(id)arg1;
-(id)defaultConfigurationName;
-(void)_setOwner:(id)arg1;
-(id)owner;
-(id)baseConfigurationList;
-(id)buildConfigurations;
-(void)appendSpotlightDescriptionToString:(id)arg1;

@end


#import <DevToolsCore/PBXProjectItem.h>

@class PBXBuildSettingsDictionary, PBXProject;

@interface PBXBuildStyle : PBXProjectItem {
    PBXProject *_project;
    NSString *_name;
    PBXBuildSettingsDictionary *_buildSettings;
}

+(id)archivableWeakRelationshipsForPListArchiver:(id)arg1;
+(id)archivableRelationships;
+(id)archivableAttributes;

-(id)initWithName:(id)arg1;

-(long long)compareName:(id)arg1;
-(id)innerDescription;
-(void)removeBuildSettingForKeyPath:(id)arg1;
-(void)setBuildSetting:(id)arg1 forKeyPath:(id)arg2;
-(id)buildSettingForKeyPath:(id)arg1;
-(BOOL)upgradeBuildSettingsFromArchivedObjectVersion:(unsigned long long)arg1;
-(id)readFromPListUnarchiver:(id)arg1;
-(id)gidCommentForArchive;
-(void)_setBuildSettings:(id)arg1;
-(BOOL)buildSettingsDictionaryShouldExtractQuotedBuildSettingsWhenSplitting:(id)arg1;
-(void)buildSettingsDictionary:(id)arg1 didSetValue:(id)arg2 withOperation:(int)arg3 forKeyPath:(id)arg4;
-(id)buildSettingsDictionary:(id)arg1 willSetValue:(id)arg2 withOperation:(int)arg3 forKeyPath:(id)arg4;
-(void)setContainer:(id)arg1;
-(id)container;
-(id)flattenedBuildSettings;
-(void)setBuildSettings:(id)arg1;
-(id)buildSettings;
-(id)_buildSettings;
-(void)_initializeBuildSettingsDictionary;
-(void)setName:(id)arg1;
-(id)name;
-(void)removeFromAppleScriptBuildSettingsAtIndex:(unsigned long long)arg1;
-(void)insertInAppleScriptBuildSettings:(id)arg1;
-(id)valueInAppleScriptBuildSettingsWithName:(id)arg1;
-(id)appleScriptBuildSettings;
-(id)objectSpecifier;

@end


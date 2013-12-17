#import <DevToolsCore/PBXProjectItem.h>

@class PBXBuildPhase, PBXReference, XCBuildInfo;

@interface PBXBuildFile : PBXProjectItem {
    PBXBuildPhase *_buildPhase;
    PBXReference *_fileRef;
    NSMutableDictionary *_settings;
    XCBuildInfo *_buildInfo;
}

+(id)archivableWeakRelationshipsForPListArchiver:(id)arg1;
+(id)archivableRelationships;
+(id)archivableAttributes;
+(id)buildFileWithReference:(id)arg1;

-(id)initWithReference:(id)arg1;

-(void)addDependencyGraphSnapshotsForBuildPhaseSnapshot:(id)arg1 toMutableArray:(id)arg2;
-(void)addRelevantToolSpecificationsForContext:(id)arg1 toSet:(id)arg2;
-(BOOL)archiveInPlistOnSingleLine;
-(id)gidCommentForArchive;
-(id)buildFileForAbsolutePath:(id)arg1;
-(id)targetBuildContext;
-(id)displayName;
-(void)untouch;
-(void)touch;
-(long long)compiledCodeFileSize;
-(long long)numberOfAnalyzerResults;
-(long long)numberOfWarnings;
-(long long)numberOfErrors;
-(BOOL)canBeUntouched;
-(BOOL)canBeTouched;
-(BOOL)needsToBeProcessed;
-(BOOL)canBeProcessed;
-(void)removeAllBuildMessages;
-(void)addBuildMessage:(id)arg1;
-(id)analyzerResultBuildMessages;
-(id)warningBuildMessages;
-(id)errorBuildMessages;
-(id)buildMessages;
-(id)preprocessingInfoForIndexing;
-(BOOL)isPlusPlus;
-(id)programmingLanguage;
-(id)buildInfo;
-(void)setStringValueForPrimaryAttribute:(id)arg1;
-(id)stringValueForPrimaryAttribute;
-(id)primaryAttribute;
-(long long)compareType:(id)arg1;
-(long long)compareName:(id)arg1;
-(long long)compareFullPath:(id)arg1;
-(unsigned long long)hash;
-(BOOL)isEqual:(id)arg1;
-(void)processSynchronouslyWithAction:(id)arg1;
-(id)buildContext;
-(void)setValue:(id)arg1 forSettingKey:(id)arg2;
-(id)valueForSettingKey:(id)arg1;
-(void)setBoolValue:(BOOL)arg1 ofAttributeNamed:(id)arg2;
-(BOOL)boolValueOfAttributeNamed:(id)arg1;
-(void)removeValue:(id)arg1 fromSettingsArrayForKey:(id)arg2;
-(void)addValue:(id)arg1 toSettingsArrayForKey:(id)arg2;
-(BOOL)hasValue:(id)arg1 inSettingsArrayForKey:(id)arg2;
-(id)settingsArrayForKey:(id)arg1;
-(id)settingsArrayForKey:(id)arg1 create:(BOOL)arg2;
-(void)_setSettings:(id)arg1;
-(BOOL)shouldArchiveSettings;
-(id)settings;
-(void)_upgradeAfterAwakingFromUnarchiver:(id)arg1;
-(void)awakeFromPListUnarchiver:(id)arg1;
-(void)setContainer:(id)arg1;
-(int)changeMask;
-(void)willChange;
-(id)container;
-(id)target;
-(void)_setBuildPhase:(id)arg1;
-(id)buildPhase;
-(id)projectRelativePath;
-(id)resolvedAbsolutePath;
-(id)absolutePath;
-(id)path;
-(id)name;
-(id)fileReference;
-(void)_setFileRef:(id)arg1;
-(id)innerDescription;
-(void)referenceWillDealloc:(id)arg1;
-(id)valueInAppleScriptBuildMessagesAtIndex:(unsigned long long)arg1;
-(id)appleScriptBuildMessages;
-(id)objectSpecifier;
-(BOOL)_isNotObjCCompilationUnit;
-(BOOL)_isObjCCompilationUnit_alsoCheckForC:(BOOL)arg1;

@end


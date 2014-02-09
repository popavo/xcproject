#import "PBXProjectItem.h"

@class PBXBuildSettingsDictionary, PBXFileReference, PBXProject, PBXTargetBuildContext, XCBuildOperation, XCConfigurationList, XCTargetHeadermapCreationInfo;

@interface PBXTarget : PBXProjectItem {
    PBXProject *_project;
    NSString *_name;
    NSString *_productTypeIdentifier;
    PBXFileReference *_productReference;
    NSString *_productInstallPath;
    NSString *_productName;
    NSMutableArray *_dependencies;
    NSMutableArray *_buildPhases;
    PBXTarget *_parentTarget;
    PBXBuildSettingsDictionary *_buildSettings;
    XCConfigurationList *_buildConfigurationList;
    NSMutableArray *_buildRules;
    NSMutableArray *_alternateBuildRules;
    NSMutableDictionary *_productSettings;
    NSMutableArray *_executables;
    BOOL _needsToWriteProductSettings;
    NSMutableDictionary *_versionSettings;
    NSMutableDictionary *_developmentSettings;
    XCBuildOperation *_currentBuildOperation;
    PBXTargetBuildContext *_buildContext;
    NSMutableDictionary *_cachedPropExpContexts;
    NSMutableDictionary *_cachedDerivedTargetAttributes;
    NSMutableDictionary *_cachedInspectionInfoContexts;
    XCTargetHeadermapCreationInfo *_cachedHeadermapCreationInfo[2];
    BOOL _needsSnapshotPropagation;
    BOOL _hasScheduledSnapshotPropagation;
    NSUInteger _snapshotPropagationDisableCount;
    NSArray *_cachedCDialectsInUse;
    NSMapTable *_fileRefsToBuildFiles;
    NSArray *_cachedRecursiveDependencies;
    BOOL _isDiscoveringRecursiveDependencies;
    BOOL _hasRecursiveDependencyCycle;
    BOOL _needToNoteBuildSettingsDidChange;
    BOOL _isBasedOnTemplate;
    NSInteger _activeExecutableIndex;
    NSMutableDictionary *_targetExecsByPlatform;
    NSMutableDictionary *_customExecsByPlatform;
    id _productBuildLocation;
    id _productInstallLocation;
    NSDictionary *_expandedBuildVariables;
    NSMutableArray *_buildFilesWithMessages;
    NSMapTable *_buildMessagesByFile;
    NSMutableArray *_filelessBuildMessages;
}

-(id)initWithName:(NSString*)arg1;
-(id)initWithName:(NSString*)arg1 templateDictionary:(id)arg2;
-(id)initWithName:(NSString*)arg1 templateDictionary:(id)arg2 baseDirectoryPath:(NSString*)arg3;
-(id)initWithName:(NSString*)arg1 productTypeIdentifier:(id)arg2 templateDictionary:(id)arg3 baseDirectoryPath:(NSString*)arg4;


-(id)valueInBuildConfigurationsAtIndex:(NSUInteger)arg1;
-(id)buildConfigurations;
-(id)targetTypeDisplayName;
-(id)dependencies;
-(void)setParentTarget:(id)arg1;
-(id)parentTarget;
-(id)children;
-(void)setContainer:(id)arg1;
-(id)container;
-(BOOL)isLeaf;
-(void)setName:(NSString*)arg1;
-(NSString*)name;
-(id)builtProductsLocation;
-(id)builtProductsLocationForConfigurationNamed:(id)arg1;
-(id)projectRelativePathForAbsolutePath:(id)arg1;
-(id)buildConfigurationList;
-(id)buildFiles;
-(NSString*)productName;
-(NSString*)productNameForConfigurationNamed:(id)arg1;
-(id)fullProductName;
-(id)fullProductNameForConfigurationNamed:(id)arg1;
-(id)productInstallPath;
-(id)productReference;
-(id)indexedFileList;

-(id)expandedCurrentValueForBuildSetting:(NSString*)arg1;
-(id)expandedCurrentValueForBuildSetting:(NSString*)arg1 forConfigurationName:(NSString*)arg2;
-(id)absoluteExpandedPathForString:(NSString*)arg1;
-(id)absoluteExpandedPathForString:(NSString*)arg1 forBuildConfigurationNamed:(NSString*)arg2;
-(id)expandedValueForString:(NSString*)arg1;
-(id)expandedValueForString:(NSString*)arg1 forConfigurationNamed:(NSString*)arg2;


-(void)removeObject:(id)arg1;
-(void)moveObject:(id)arg1 toIndex:(NSUInteger)arg2;
-(void)addObject:(id)arg1;
-(void)replaceInDependencies:(id)arg1 atIndex:(NSUInteger)arg2;
-(void)removeFromDependenciesAtIndex:(NSUInteger)arg1;
-(void)insertInDependencies:(id)arg1;
-(void)insertInDependencies:(id)arg1 atIndex:(NSUInteger)arg2;
-(id)valueInDependenciesAtIndex:(NSUInteger)arg1;
-(void)removeFromShellScriptBuildPhasesAtIndex:(NSUInteger)arg1;
-(void)replaceInShellScriptBuildPhases:(id)arg1 atIndex:(NSUInteger)arg2;
-(void)insertInShellScriptBuildPhases:(id)arg1;
-(void)insertInShellScriptBuildPhases:(id)arg1 atIndex:(NSUInteger)arg2;
-(id)valueInShellScriptBuildPhasesAtIndex:(NSUInteger)arg1;
-(void)removeFromCopyFilesBuildPhasesAtIndex:(NSUInteger)arg1;
-(void)replaceInCopyFilesBuildPhases:(id)arg1 atIndex:(NSUInteger)arg2;
-(void)insertInCopyFilesBuildPhases:(id)arg1;
-(void)insertInCopyFilesBuildPhases:(id)arg1 atIndex:(NSUInteger)arg2;
-(id)valueInCopyFilesBuildPhasesAtIndex:(NSUInteger)arg1;
-(void)removeFromAppleScriptBuildPhasesAtIndex:(NSUInteger)arg1;
-(void)replaceInAppleScriptBuildPhases:(id)arg1 atIndex:(NSUInteger)arg2;
-(void)insertInAppleScriptBuildPhases:(id)arg1;
-(void)insertInAppleScriptBuildPhases:(id)arg1 atIndex:(NSUInteger)arg2;
-(id)valueInAppleScriptBuildPhasesAtIndex:(NSUInteger)arg1;
-(void)removeFromBuildPhasesAtIndex:(NSUInteger)arg1;
-(void)replaceInBuildPhases:(id)arg1 atIndex:(NSUInteger)arg2;
-(void)insertInBuildPhases:(id)arg1;
-(void)insertInBuildPhases:(id)arg1 atIndex:(NSUInteger)arg2;
-(id)valueInBuildPhasesAtIndex:(NSUInteger)arg1;
-(id)executable;


-(id)buildFileForReference:(id)arg1;
-(id)buildFileForReferenceIdenticalTo:(id)arg1;
-(id)buildFileForAbsolutePath:(id)arg1;
-(id)buildFileForResolvedAbsolutePath:(id)arg1;


-(BOOL)removeReference:(id)arg1;
-(BOOL)addReference:(id)arg1;
-(id)appropriateBuildPhaseForFileReference:(id)arg1;
-(id)appleScriptBuildPhases;
-(id)shellScriptBuildPhases;
-(id)copyFilesBuildPhases;
-(id)defaultRezBuildPhase;
-(id)defaultJavaArchiveBuildPhase;
-(id)defaultFrameworksBuildPhase;
-(id)defaultLinkBuildPhase;
-(id)defaultSourceCodeBuildPhase;
-(id)defaultResourceBuildPhase;
-(id)defaultHeaderBuildPhase;
-(id)buildPhasesOfClass:(Class)arg1;
-(id)buildPhaseOfClass:(Class)arg1;
-(id)buildPhaseNamed:(id)arg1;
-(void)moveBuildPhase:(id)arg1 toIndex:(NSUInteger)arg2;
-(void)moveBuildPhasesFromIndices:(NSUInteger *)arg1 numIndices:(NSUInteger)arg2 toIndex:(NSUInteger)arg3;
-(void)removeBuildPhase:(id)arg1;
-(void)addBuildPhase:(id)arg1;
-(void)insertBuildPhase:(id)arg1 atIndex:(NSUInteger)arg2;
-(BOOL)acceptsBuildPhase:(id)arg1;
-(id)buildPhases;
-(id)missingDependencies;
-(id)findDependingTargetsInProject:(id)arg1;
-(id)dependencyForTarget:(id)arg1;
-(BOOL)dependsOnTarget:(id)arg1;
-(id)directDependencies;
-(id)orderedRecursiveDependenciesIncludingSelf:(BOOL)arg1;
-(id)_uncachedOrderedRecursiveDependenciesIncludingSelf:(BOOL)arg1;
-(void)removeDependency:(id)arg1;
-(void)addDependency:(id)arg1;
-(void)insertDependencies:(id)arg1 atIndex:(NSUInteger)arg2;

@end


#import <IDEFoundation/DVTInvalidation.h>

@class DVTFilePath, DVTStackBacktrace, IDEWorkspace, IDEWorkspaceArenaInfo, IDEWorkspaceArenaSnapshot, NSString;

@interface IDEWorkspaceArena : NSObject <DVTInvalidation> {
    IDEWorkspace *_workspace;
    DVTFilePath *_cachedDerivedDataLocation;
    DVTFilePath *_cachedBuildFolderPath;
    DVTFilePath *_cachedBuildProductsFolderPath;
    DVTFilePath *_cachedBuildIntermediatesFolderPath;
    NSString *_cachedWorkspaceArenaFolderName;
    BOOL _hasWorkspaceRelativeDerivedDataLocation;
    BOOL didSetUpCachedWorkspaceArenaFolderNameObservations;
    id _derivedDataFolderForWorkspaceObservingToken;
    id _derivedDataNotificationToken;
    id _derivedDataSourceTreesNotificationToken;
    id _derivedDataOverrideNotificationToken;
    IDEWorkspaceArenaSnapshot *_cachedSnapshot;
}
@property BOOL hasWorkspaceRelativeDerivedDataLocation; // @synthesize hasWorkspaceRelativeDerivedDataLocation=_hasWorkspaceRelativeDerivedDataLocation;
@property (readonly) IDEWorkspace *workspace; // @synthesize workspace=_workspace;
@property (readonly) IDEWorkspaceArenaInfo *workspaceArenaInfo;
@property (readonly) DVTFilePath *testResultsFolderPath;
@property (readonly) DVTFilePath *logFolderPath;
@property (readonly) DVTFilePath *indexPrecompiledHeadersFolderPath;
@property (readonly) DVTFilePath *indexFolderPath;
@property (readonly) DVTFilePath *textIndexFolderPath;
@property (readonly) DVTFilePath *precompiledHeadersFolderPath;
@property (readonly) DVTFilePath *installingBuildFolderPath;
@property (readonly) DVTFilePath *archivingBuildFolderPath;
@property (readonly) DVTFilePath *buildIntermediatesFolderPath;
@property (readonly) DVTFilePath *buildProductsFolderPath;
@property (readonly) DVTFilePath *buildFolderPath;
@property (readonly) DVTFilePath *derivedDataFolderForWorkspace;
@property (readonly) DVTFilePath *derivedDataLocation;
@property (readonly) IDEWorkspaceArenaSnapshot *currentSnapshot;
@property (retain) DVTStackBacktrace *creationBacktrace;
@property (readonly) DVTStackBacktrace *invalidationBacktrace;
@property (readonly, nonatomic, getter=isValid) BOOL valid;

+(id)defaultBuildSubdirectoryName;
+(id)defaultWorkspaceRelativeDerivedDataDirLocation;
+(BOOL)shouldUniqueWorkspaceFoldersInStandardDerivedDataLocation;
+(id)standardWorkspaceDerivedDataLocationForWorkspace:(id)arg1;
+(id)_standardDerivedDataLocationPathFragment;
+(id)keyPathsForValuesAffectingWorkspaceArenaInfo;
+(id)keyPathsForValuesAffectingTestResultsFolderPath;
+(id)keyPathsForValuesAffectingLogFolderPath;
+(id)keyPathsForValuesAffectingIndexPrecompiledHeadersFolderPath;
+(id)keyPathsForValuesAffectingIndexFolderPath;
+(id)keyPathsForValuesAffectingTextIndexFolderPath;
+(id)buildIntermediatesFolderPathForSettings:(id)arg1 usingPlaceholderOfType:(int *)arg2;
+(id)buildProductsFolderPathForSettings:(id)arg1 usingPlaceholderOfType:(int *)arg2;
+(id)keyPathsForValuesAffectingPrecompiledHeadersFolderPath;
+(id)keyPathsForValuesAffectingInstallingBuildFolderPath;
+(id)keyPathsForValuesAffectingArchivingBuildFolderPath;
+(id)keyPathsForValuesAffectingBuildIntermediatesFolderPath;
+(id)keyPathsForValuesAffectingBuildProductsFolderPath;
+(void)_buildResultsPathForBuildResultsType:(int)arg1 settings:(id)arg2 workspaceArena:(id)arg3 returningFilePath:(id *)arg4 orReturningPathString:(id *)arg5 withPlaceholder:(int *)arg6;
+(id)_resolvedBuildFolderSettingsGivenSettings:(id)arg1;
+(id)keyPathsForValuesAffectingPath;
+(id)keyPathsForValuesAffectingDerivedDataFolderForWorkspace;
+(id)nameForWorkspaceArenaWithBaseName:(id)arg1 gristInput:(id)arg2;

-(id)initWithWorkspace:(IDEWorkspace*)arg1;

-(void)createWorkspaceArenaFolderIfNecessary;
-(id)buildIntermediatesFolderPathForSettings:(id)arg1;
-(id)buildProductsFolderPathForSettings:(id)arg1;
-(id)_buildResultsPathForBuildResultsType:(int)arg1 settings:(id)arg2;
-(id)_buildFolderPathForSettings:(id)arg1;
-(void)buildFolderSettingsDidChange:(id)arg1;
-(id)presumptiveBuildFolderPathWithName:(id)arg1 baseBuildFolderLocation:(id)arg2;
-(id)_derivedDataFolderPathOverride;
-(id)path;
-(BOOL)_shouldUniqueWorkspaceInDerivedDataForDerivedDataLocationStyle:(int)arg1 customDerivedDataLocation:(id)arg2;
-(id)workspaceArenaFolderName;
-(void)primitiveInvalidate;

@end


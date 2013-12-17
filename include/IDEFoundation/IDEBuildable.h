#import <IDEFoundation/DVTInvalidation.h>
#import <IDEFoundation/IDEBuildSettingsProvider.h>

@protocol IDEBuildable <IDEBuildSettingsProvider, DVTInvalidation, NSObject>

@property (readonly) NSString *legacyIdentifier;
@property (readonly) NSSet *namesOfLinkedBinaries;
@property (readonly) BOOL hasRecursiveDependencyCycle;
@property (readonly) NSString *toolTip;
@property (readonly) NSString *displayName;
@property (readonly) id <IDEBlueprint> blueprint;
@property (readonly) NSString *buildableIdentifier;

-(id)createBuilderForBuildCommand:(int)arg1 withBuildTaskQueueSet:(id)arg2 parameters:(id)arg3 buildOnlyTheseFiles:(id)arg4 restorePersistedBuildResults:(BOOL)arg5;
-(id)implicitDependenciesForBuildParameters:(id)arg1 executionEnvironment:(id)arg2 returningMessages:(id *)arg3;
-(id)directDependencies;
-(id)uncachedOrderedRecursiveDependenciesIncludingSelf:(BOOL)arg1 visitedBuildables:(id)arg2;
-(id)orderedRecursiveDependenciesIncludingSelf:(BOOL)arg1;
-(id)absolutePathByEvaluatingBuildSettingExpressionString:(id)arg1 withBuildParameters:(id)arg2;
-(id)stringByEvaluatingBuildSettingExpressionString:(id)arg1 withBuildParameters:(id)arg2;
-(id)evaluatedStringListValueForBuildSetting:(id)arg1 withBuildParameters:(id)arg2;
-(id)evaluatedStringValueForBuildSetting:(id)arg1 withBuildParameters:(id)arg2;
-(id)allBuildSettingNamesWithBuildParameters:(id)arg1;

@end

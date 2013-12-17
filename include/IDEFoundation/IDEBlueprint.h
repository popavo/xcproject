#import <IDEFoundation/IDEIntegrityLogDataSource.h>

@protocol IDEBlueprint <NSObject, IDEIntegrityLogDataSource>

@property (readonly) NSString *blueprintIdentifier;
@property (readonly) NSString *name;

-(id)entitlementsFilePathForBuildConfiguration:(id)arg1;
-(void)addFileReference:(id)arg1 toBuildablesContainingFileReference:(id)arg2;
-(BOOL)containsFilePath:(id)arg1;
-(BOOL)containsFileReference:(id)arg1;
-(id)buildableProducts;
-(id)buildables;
-(id)primaryBuildable;
-(id)buildableForIdentifier:(id)arg1;
-(id)localizedDescription;
-(id)customDataStore;
-(id)blueprintProvider;


@optional

@property (readonly, getter=isUnitTest) BOOL unitTest;
@property (retain) NSString *unitTestingBlueprintIdentifier;

-(id)additionalOverridingCompilerArgumentsForSourceCodeBuildFileReference:(id)arg1;
-(void)setOverridingAdditionalCompilerArguments:(id)arg1 forSourceCodeBuildFileReference:(id)arg2;
-(id)additionalCompilerArgumentsForSourceCodeBuildFileReference:(id)arg1;
-(void)setAdditionalCompilerArguments:(id)arg1 forSourceCodeBuildFileReference:(id)arg2;
-(id)linkedBinaries;
-(id)allProjectHeaderFiles;
-(id)allPrivateHeaderFiles;
-(id)allPublicHeaderFiles;
-(id)allBuildFileReferences;
-(id)sourceCodeBuildFileReferences;
-(void)convertToUseModernUnitTests;
-(void)convertToUseModernObjCSyntax;
-(void)convertToUseARC;
-(BOOL)canConvertToUseARC;
-(void)convertToBuild64bitOnly;
-(void)convertToUseClang;
-(id)deviceSDKFor:(id)arg1 SDKs:(id)arg2;
-(id)simulatorSDKFor:(id)arg1 SDKs:(id)arg2;
-(id)specifiedBaseSDKForBuildConfigurationName:(id)arg1;
-(id)baseSDKForBuildConfigurationName:(id)arg1;
-(id)supportedPlatformsForConfiguration:(id)arg1 workspaceArenaSnapshot:(id)arg2;
-(id)compilerSpecificationIdentifier;
-(id)availableArchitecturesForConfiguration:(id)arg1 workspaceArenaSnapshot:(id)arg2;
-(id)defaultConfigurationName;
-(id)availableConfigurationNames;

@end


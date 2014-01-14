#import "PBXContainer.h"

@class PBXBookmarkGroup, PBXBuildSettingsDictionary, PBXBuildStyle, PBXCodeSenseManager, PBXExecutable, PBXFileReference, PBXGroup, PBXLogOutputString, PBXProjectIndex, PBXTarget, XCArchiveFormat, XCBreakpointsBucket, XCBuildOperation, XCConfigurationList, XCFileSystemWatcher, XCRoots, XCSourceControlManager;

@interface PBXProject : PBXContainer


+(id)projectFilePathWithPath:(id)arg1;
+(id)projectWrapperPathForPath:(id)arg1;
+(BOOL)isProjectWrapperExtension:(id)arg1;
+(id)projectWrapperExtension;

+(PBXProject*)projectWithFile:(NSString*)arg1;
+(PBXProject*)projectWithFile:(NSString*)arg1 errorHandler:(id)arg2;
+(PBXProject*)projectWithFile:(NSString*)arg1 errorHandler:(id)arg2 readOnly:(BOOL)arg3;

-(NSString*)name;
-(NSString*)path;
-(NSString*)projectDirectory;
-(id)attributes;
-(id)projectIndex;

-(id)projectRoots;
-(NSString*)projectFilePath;
-(id)projectFileRef;
-(NSString*)projectRootPath;
-(id)projectRootPaths;
-(id)roots;

-(BOOL)canWriteToProjectFile;
-(BOOL)writeToFile:(id)arg1 projectFile:(BOOL)arg2 userFile:(BOOL)arg3 outResultNotification:(id *)arg4;
-(BOOL)writeToFileSystemProjectFile:(BOOL)arg1 userFile:(BOOL)arg2 checkNeedsRevert:(BOOL)arg3;

-(id)targetWithGlobalID:(id)arg1;
-(id)targetNamed:(id)arg1;
-(id)targets;
-(id)activeTarget;
-(id)allTargetsInDependencyOrder;
-(id)targetsForFileReference:(id)arg1 justNative:(BOOL)arg2;

-(id)projectReferenceForProject:(id)arg1;
-(id)projectReferenceForPath:(id)arg1;
-(id)projectReferences;
-(NSArray*)referencedProjects;

-(id)relativeFileReferenceForPath:(id)arg1;
-(NSString*)absoluteExpandedPathForString:(NSString*)arg1;
-(NSString*)absoluteExpandedPathForString:(NSString*)arg1 forConfigurationNamed:(NSString*)arg2;

-(id)builtProductsLocation;
-(id)builtProductsLocationForConfigurationNamed:(id)arg1;
-(id)productDirectory;
-(id)productDirectoryForConfigurationNamed:(id)arg1;
-(id)productsForProject:(id)arg1;
-(id)productsForProjectReference:(id)arg1;

-(id)buildConfigurationList;
-(id)availableBuildConfigurationNames;
-(id)buildConfigurations;
-(id)defaultConfigurationName;
-(void)setDefaultConfigurationName:(id)arg1;
-(id)expandedValueForString:(id)arg1;
-(id)expandedValueForString:(id)arg1 forConfigurationNamed:(id)arg2;

@end


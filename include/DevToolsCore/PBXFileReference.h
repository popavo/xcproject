#import <DevToolsCore/PBXReference.h>

@class PBXContainer, PBXFileType;

@interface PBXFileReference : PBXReference {
    PBXContainer *_loadedContainer;
    PBXFileType *_lastKnownFileType;
    NSDictionary *_lastKnownFileProperties;
    PBXFileType *_explicitFileType;
    NSDictionary *_explicitFileProperties;
}

+(id)archivableAttributes;
+(id)defaultExpectedFileTypeForPath:(id)arg1;
+(BOOL)allowCopyingSourceFile;
+(BOOL)canRepresentFileAtPath:(id)arg1;
+(BOOL)canRepresentFileAtPath:(id)arg1 ofType:(id)arg2;
+(id)knownWrapperExtensions;

-(id)initWithName:(id)arg1 path:(id)arg2 sourceTree:(id)arg3 fileType:(id)arg4 extraFileProperties:(id)arg5;
-(id)initWithName:(id)arg1 path:(id)arg2 sourceTree:(id)arg3;

-(unsigned long long)assignFileEncoding:(unsigned long long)arg1 onlyIfUnspecified:(BOOL)arg2;
-(BOOL)hasUnspecifiedFileEncodings;
-(void)_setExpectedFileType:(id)arg1;
-(id)_expectedFileType;
-(void)_setExplicitFileType:(id)arg1;
-(id)_explicitFileType;
-(void)_setLastKnownFileType:(id)arg1;
-(id)_lastKnownFileType;
-(BOOL)archiveInPlistOnSingleLine;
-(void)awakeFromPListUnarchiver:(id)arg1;
-(BOOL)allowsRemovalFromDisk;
-(BOOL)_isContainedInDeveloperDirectory;
-(BOOL)_isContainedInLibraryDirectory;
-(BOOL)allowsEditing;
-(BOOL)isLeaf;
-(void)validateChildren;
-(id)children;
-(void)setLoadedContainer:(id)arg1;
-(void)_setLoadedContainer:(id)arg1 andNotify:(BOOL)arg2;
-(id)loadedContainer;
-(void)scmInfoChanged;
-(id)scmInfo;
-(void)discardSCMInfo;
-(id)createSCMInfoWithSandboxEntry:(id)arg1;
-(id)sandboxEntry;
-(BOOL)_doFileSystemCopyTo:(id)arg1 deleteOriginal:(BOOL)arg2;
-(void)invalidateAbsolutePathCache;
-(id)resolvedAbsolutePath;
-(void)setPath:(id)arg1 andSourceTree:(id)arg2;
-(void)_pathForSourceTreeDidChange:(id)arg1;
-(BOOL)deleteFromProjectAndDisk:(BOOL)arg1;
-(void)setContainer:(id)arg1;
-(BOOL)hasGUI;
-(id)absolutePathToLaunchable;
-(BOOL)isExecutable;
-(BOOL)shouldArchivePlistStructureDefinitionIdentifier;
-(void)setPlistStructureDefinitionIdentifier:(id)arg1;
-(id)plistStructureDefinitionIdentifier;
-(BOOL)shouldArchiveXcLanguageSpecificationIdentifier;
-(void)setXcLanguageSpecificationIdentifier:(id)arg1;
-(id)xcLanguageSpecificationIdentifier;
-(BOOL)shouldArchiveLanguageSpecificationIdentifier;
-(void)setLanguageSpecificationIdentifier:(id)arg1;
-(id)languageSpecificationIdentifier;
-(BOOL)canSetIncludeInIndex;
-(BOOL)includeInIndex;
-(BOOL)usesTabs;
-(long long)indentWidth;
-(BOOL)isProductReference;
-(id)unexpandedAbsolutePathForWrapperPart:(int)arg1;
-(id)absolutePathForWrapperPart:(int)arg1;
-(id)resolvedAbsolutePathForWrapperPart:(int)arg1;
-(id)subpathForWrapperPart:(int)arg1;
-(void)setExplicitFileTypeIfNil:(id)arg1;
-(void)setExplicitFileType:(id)arg1;
-(void)setExplicitFileType:(id)arg1 explicitFileProperties:(id)arg2;
-(BOOL)userCanSetExplicitFileType;
-(id)fileProperties;
-(id)fileType;
-(void)_getEffectiveFileType:(id *)arg1 fileProperties:(id *)arg2;
-(void)_invalidateLastKnownFileType;
-(BOOL)shouldOpenProjectOfMismatchingVersion:(unsigned long long)arg1 atPath:(id)arg2;
-(id)topLevelSymbols;
-(id)allDependentFiles;
-(id)allImportedFiles;
-(id)dependentFiles;
-(id)importedFiles;
-(id)handleDiffScriptCommand:(id)arg1;
-(id)handleCompareScriptCommand:(id)arg1;
-(id)handleCommitScriptCommand:(id)arg1;
-(id)handleClearStickyTagsScriptCommand:(id)arg1;
-(id)handleUpdateScriptCommand:(id)arg1;
-(id)handleRefreshScriptCommand:(id)arg1;
-(id)appleScriptSCMRevisions;
-(id)asScmLocalRevision;
-(id)asScmRepositoryRevision;
-(id)asScmTag;
-(unsigned int)asScmStatus;
-(id)asFileTypeIdentifier;
-(id)objectSpecifier;
-(BOOL)isNotObjCCompilationUnitOrHeader;
-(BOOL)isObjCCompilationUnit_alsoCheckForC:(BOOL)arg1;
-(BOOL)isObjCCompilationUnitOrHeader_alsoCheckForC:(BOOL)arg1;
-(BOOL)hasSimpleFileType:(id)arg1;

@end


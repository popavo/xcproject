@class DVTFilePath;

@interface IDEWorkspaceArenaSnapshot : NSObject {
    DVTFilePath *_derivedDataFolderPath;
    DVTFilePath *_buildProductsFolderPath;
    DVTFilePath *_buildIntermediatesFolderPath;
    DVTFilePath *_precompiledHeadersFolderPath;
    DVTFilePath *_indexFolderPath;
    DVTFilePath *_indexPrecompiledHeadersFolderPath;
    DVTFilePath *_logFolderPath;
    DVTFilePath *_textIndexFolderPath;
    NSUInteger _hash;
}
@property (readonly) DVTFilePath *textIndexFolderPath; // @synthesize textIndexFolderPath=_textIndexFolderPath;
@property (readonly) DVTFilePath *logFolderPath; // @synthesize logFolderPath=_logFolderPath;
@property (readonly) DVTFilePath *indexPrecompiledHeadersFolderPath; // @synthesize indexPrecompiledHeadersFolderPath=_indexPrecompiledHeadersFolderPath;
@property (readonly) DVTFilePath *indexFolderPath; // @synthesize indexFolderPath=_indexFolderPath;
@property (readonly) DVTFilePath *precompiledHeadersFolderPath; // @synthesize precompiledHeadersFolderPath=_precompiledHeadersFolderPath;
@property (readonly) DVTFilePath *buildIntermediatesFolderPath; // @synthesize buildIntermediatesFolderPath=_buildIntermediatesFolderPath;
@property (readonly) DVTFilePath *buildProductsFolderPath; // @synthesize buildProductsFolderPath=_buildProductsFolderPath;
@property (readonly) DVTFilePath *derivedDataFolderPath; // @synthesize derivedDataFolderPath=_derivedDataFolderPath;

+(id)workspaceArenaSnapshotForWorkspaceArena:(id)arg1;

-(id)dvt_detailedDebugDescription;

@end


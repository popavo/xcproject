#import "PBXContainerItem.h"

@class PBXContainer, PBXGroup, PBXTarget, XCFileSystemNode, XCSCMInfo;

@interface PBXReference : PBXContainerItem

+ (NSArray*)allGroupsForGroup:(PBXGroup*)arg1;

- (id)initWithPath:(NSString*)arg1;
- (id)initWithName:(NSString*)arg1;
- (id)initWithName:(NSString*)arg1 path:(NSString*)arg2;
- (id)initWithName:(NSString*)arg1 path:(NSString*)arg2 sourceTree:(NSString*)arg3 fileType:(id)arg4 extraFileProperties:(NSDictionary*)arg5;
- (id)initWithName:(NSString*)arg1 path:(NSString*)arg2 sourceTree:(NSString*)arg3;
- (id)initWithName:(NSString*)arg1 path:(NSString*)arg2 referenceType:(int)arg3;

- (void)pruneReferencesBySendingBooleanSelector:(SEL)arg1 toObject:(id)arg2 withContext:(void*)arg3;
- (NSInteger)compareType:(id)arg1;
- (NSInteger)compareName:(id)arg1;

- (BOOL)isCurrentVersion;
- (BOOL)isVersion;
- (BOOL)isVersionGroup;
- (id)regionVariantName;
- (BOOL)isRegionVariant;
- (BOOL)isVariant;
- (BOOL)isVariantGroup;
- (id)destinationGroupForFilenames:(id)arg1;
- (id)destinationGroupForInsertion;
- (BOOL)isAncestorOfItem:(id)arg1;
- (BOOL)isGroup;
- (BOOL)isLeaf;
- (id)children;
- (void)setWrapsLines:(NSInteger)arg1;
- (BOOL)wrapsLines;
- (void)setUsesTabs:(NSInteger)arg1;
- (BOOL)usesTabs;
- (void)setIndentWidth:(NSInteger)arg1;
- (NSInteger)indentWidth;
- (void)setTabWidth:(NSInteger)arg1;
- (NSInteger)tabWidth;
- (void)setFileEncoding:(NSUInteger)arg1;
- (NSUInteger)fileEncoding;
- (id)fileProperties;
- (id)fileType;
- (BOOL)changeSourceTree:(id)arg1;
- (void)setSourceTree:(id)arg1;
- (BOOL)moveToNewPath:(id)arg1;
- (BOOL)copyToNewPath:(id)arg1;
- (BOOL)setPath:(id)arg1;
- (void)setPath:(id)arg1 andSourceTree:(id)arg2;
- (BOOL)fileExists;
- (id)unexpandedAbsolutePath;
- (id)absolutePathForDisplay;
- (id)developerDirRelativePath;
- (id)buildProductRelativePath;
- (id)groupRelativePath;
- (id)projectRelativePath;
- (id)resolvedAbsoluteDirectory;
- (id)absoluteDirectory;
- (id)fileSystemNode;
- (NSString*)resolvedAbsolutePath;
- (NSString*)absolutePath;
- (NSString*)absolutePathForConfigurationNamed:(id)arg1;
- (NSString*)path;
- (NSString*)sourceTree;
- (id)defaultReference;
- (id)groupTreeDisplayName;
- (BOOL)canSetName;
- (BOOL)setName:(id)arg1 syncDisk:(BOOL)arg2;
- (void)setName:(NSString*)arg1;
- (NSString*)name;
- (BOOL)isProductReference;
- (BOOL)deleteFromProjectAndDisk:(BOOL)arg1;
- (void)deleteFromDisk;
- (void)removeFromGroup;
- (void)setGroup:(id)arg1;
- (id)group;
- (void)setContainer:(id)arg1;
- (id)container;
- (id)absolutePathForExpansionContext:(id)arg1;
- (id)unexpandedFullPath;
- (id)valueInFileReferencesAtIndex:(NSUInteger)arg1;
- (id)valueInGroupsAtIndex:(NSUInteger)arg1;
- (id)fileReferences;
- (id)groups;
- (id)allFileReferencesForGroup:(id)arg1;
- (id)allReferencesForGroup:(id)arg1;

@end

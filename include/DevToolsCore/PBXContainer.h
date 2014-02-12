#import "PBXObject.h"

@class PBXGroup, PBXGroupEnumerator;

@interface PBXContainer : PBXObject

+ (id)containerForResolvedAbsolutePath:(id)arg1;

- (id)name;
- (id)absolutePath;
- (id)resolvedAbsolutePath;
- (id)path;
- (void)setPath:(id)arg1;
- (id)stringByMakingExpandedPathAbsolute:(id)arg1;
- (PBXGroup*)rootGroup;

- (void)printContainedItems;

- (BOOL)allowsEditingOfChildren;
- (BOOL)isReadOnly;
- (id)children;
- (id)references;
- (void)addReference:(id)arg1;
- (void)removeReference:(id)arg1;

- (void)addItem:(id)arg1;
- (void)removeItem:(id)arg1;

- (id)itemForGlobalIDHexString:(id)arg1;
- (id)itemForGlobalID:(id)arg1;
- (id)itemsOfFileType:(id)arg1;

- (id)fileReferenceForPartialPath:(id)arg1;
- (id)fileReferencesForPartialFileName:(id)arg1 ofTypes:(id)arg2 ignoringCase:(BOOL)arg3;
- (id)fileReferenceForFileName:(id)arg1;
- (id)fileReferenceForFileName:(id)arg1 ignoringCase:(BOOL)arg2;
- (id)fileReferenceForPath:(id)arg1;
- (id)allFileReferencesForFileName:(id)arg1;

- (id)allFileReferences;
- (id)allGroups;
- (id)allReferences;
- (id)allItemsOfClass:(Class)arg1;
- (id)allItems;

- (PBXGroupEnumerator*)groupEnumerator;
- (void)_clearGroupEnumerator;

@end

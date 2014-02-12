#import "PBXReference.h"

@interface PBXGroup : PBXReference

+ (PBXGroup*)groupWithName:(NSString*)arg1;
+ (PBXGroup*)groupWithName:(NSString*)arg1 path:(NSString*)arg2;

- (id)initWithName:(NSString*)arg1 path:(NSString*)arg2 sourceTree:(NSString*)arg3;

- (NSString*)name;
- (id)children;
- (id)objectSpecifier;
- (id)buildConfigurationList;

- (PBXGroup*)createNewGroupAtIndex:(NSUInteger)arg1;

- (void)setContainer:(id)arg1;
- (BOOL)isAncestorOfItem:(id)arg1;
- (BOOL)containsItem:(id)arg1;

- (void)addItem:(id)arg1;
- (void)addItems:(id)arg1;
- (void)insertItem:(id)arg1 atIndex:(NSUInteger)arg2;
- (void)insertItems:(id)arg1 atIndex:(NSUInteger)arg2;
- (void)moveObject:(id)arg1 toIndex:(NSUInteger)arg2;

- (NSUInteger)itemCount;
- (id)itemNamed:(id)arg1;
- (id)itemAtIndex:(NSUInteger)arg1;
- (NSUInteger)indexOfItem:(id)arg1;
- (void)removeItem:(id)arg1;
- (BOOL)deleteFromProjectAndDisk:(BOOL)arg1;
- (id)addItems:(id)arg1 copy:(BOOL)arg2 createGroupsRecursively:(BOOL)arg3;
- (id)addItems:(id)arg1 atIndex:(NSInteger)arg2 copy:(BOOL)arg3 createGroupsRecursively:(BOOL)arg4;
- (id)insertItems:(id)arg1 atIndex:(NSInteger)arg2 copy:(BOOL)arg3 createGroupsRecursively:(BOOL)arg4;
- (NSArray*)addFiles:(id)arg1 copy:(BOOL)arg2 createGroupsRecursively:(BOOL)arg3;
- (NSArray*)addFiles:(id)arg1 atIndex:(NSInteger)arg2 copy:(BOOL)arg3 createGroupsRecursively:(BOOL)arg4;
- (id)insertFiles:(id)arg1 atIndex:(NSInteger)arg2 copy:(BOOL)arg3 createGroupsRecursively:(BOOL)arg4;

@end

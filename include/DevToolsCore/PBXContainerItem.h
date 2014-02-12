#import "PBXObject.h"

@interface PBXContainerItem : PBXObject

- (BOOL)shouldArchiveUserInterfaceContext;
- (BOOL)shouldArchiveComments;
- (void)removeObjectForUserInterfaceContextKey:(id)arg1;
- (void)setObject:(id)arg1 forUserInterfaceContextKey:(id)arg2;
- (id)objectForUserInterfaceContextKey:(id)arg1;
- (void)setUserInterfaceContext:(id)arg1;
- (id)userInterfaceContext;
- (void)willChangeWithArchivePriority:(int)arg1;
- (void)willChange;
- (int)changeMask;
- (void)setContainer:(id)arg1;
- (id)container;
- (void)setProject:(id)arg1;
- (id)project;
- (id)comments;
- (void)setComments:(id)arg1;
- (void)handleMoveCommand:(id)arg1;

@end

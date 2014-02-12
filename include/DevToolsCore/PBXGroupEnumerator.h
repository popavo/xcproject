@interface PBXGroupEnumerator : NSEnumerator<NSCopying> {
  NSMutableArray* _enumeratedObjects;
  NSUInteger _nextIndex;
  NSUInteger _count;
}

+ (PBXGroupEnumerator*)enumeratorForGroup:(id)arg1 startingAtItem:(id)arg2;
+ (PBXGroupEnumerator*)enumeratorForGroup:(id)arg1;
+ (SEL)traversalSelector;

- (id)initWithRootArray:(id)arg1 nextObject:(id)arg2;
- (id)lastObject;
- (id)firstObject;
- (id)previousObject;
- (void)setNextObject:(id)arg1;
- (NSUInteger)numberOfObjects;
- (void)rewind;

@end

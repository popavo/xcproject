@class XCFileSystemVNode, XCPath;

@interface XCFileSystemNode : NSObject {
    XCPath *_path;
    unsigned long long _cacheGeneration;
    XCFileSystemVNode *_vnode;
    unsigned long long _numAssociates;
    id _associates;
}

+(XCFileSystemNode*)fileSystemNodeForPath:(XCPath*)arg1;

-(id)initWithPath:(id)arg1;

-(id)path;
-(id)parentNode;
-(id)childNodeWithName:(id)arg1;
-(id)vnode;

-(id)descriptionOfAssociates;
-(void)removeAllAssociates;
-(void)removeAssociate:(id)arg1;
-(void)removeAssociatesOfType:(unsigned int)arg1;
-(void)removeAssociate:(id)arg1 ofType:(unsigned int)arg2;
-(void)addAssociate:(id)arg1 ofType:(unsigned int)arg2;
-(id)associatesOfType:(unsigned int)arg1;
-(void)discardCachedInfo;
-(void)discardCachedInfoAndAlsoParentDirectory:(BOOL)arg1;
-(void)discardCachedInfo_NoLock;
-(void)setCachedValue:(id)arg1 forKey:(id)arg2;
-(id)cachedValueForKey:(id)arg1;
-(id)fileType;
-(id)sortedDirectoryContents;
-(double)modificationTime;
-(BOOL)isDeletable;
-(BOOL)isWritable;
-(BOOL)existsInFileSystem;

@end
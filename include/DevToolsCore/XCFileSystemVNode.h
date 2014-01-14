#import <sys/stat.h>

@interface XCFileSystemVNode : NSObject {
    unsigned short _statMode;
    unsigned int _statUid;
    unsigned int _statGid;
    NSUInteger _statFlags;
    int _deviceNumber;
    NSUInteger _inodeNumber;
    NSInteger _fileSize;
    NSInteger _modificationTime;
    NSMutableDictionary *_derivedInfoDict;
    NSHashTable *_fileSystemNodes;
}

+(id)lookupVNodeForDeviceNumber:(int)arg1 inodeNumber:(NSUInteger)arg2;

-(id)initWithStatInfo:(const struct stat*)arg1;

-(void)recordStatInfo:(const struct stat*)arg1;
-(void)addCachedEntriesFromDictionary:(id)arg1;
-(id)cachedValueForKey:(id)arg1;
-(void)removeFSNode:(id)arg1;
-(void)addFSNode:(id)arg1;
-(NSInteger)modificationTime;
-(NSInteger)fileSize;
-(NSUInteger)inodeNumber;
-(int)deviceNumber;
-(unsigned int)statFlags;
-(NSUInteger)statGid;
-(unsigned int)statUid;
-(unsigned short)statMode;
-(id)fileSystem;

@end


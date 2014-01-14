@interface XCPath : NSObject

+(id)pathWithPath:(id)arg1 relativeToPath:(id)arg2;
+(id)pathWithPathComponents:(id)arg1;
+(id)pathWithBasePath:(id)arg1 pathComponents:(id)arg2;
+(id)pathWithPrefixPath:(id)arg1 basePath:(id)arg2 pathComponents:(id)arg3;
+(id)pathWithPrefixPath:(id)arg1 basePath:(id)arg2 pathComponents:(id *)arg3 count:(NSUInteger)arg4;
+(id)pathWithString:(id)arg1;
+(id)pathWithFileSystemRepresentation:(const char *)arg1;
+(id)pathWithFileSystemRepresentation:(const char *)arg1 length:(NSUInteger)arg2;

-(id)stringRepresentation;
-(id)pathByRemovingPathSuffix;
-(id)pathSuffix;
-(id)pathByRemovingLastPathComponent;
-(id)lastPathComponent;
-(BOOL)isAbsolutePath;
-(const char*)unretainedFileSystemRepresentation;
-(NSUInteger)length;
-(BOOL)isPathSuffixEqualToFileSystemRepresentation:(const char *)arg1;
-(BOOL)isPathSuffixEqualToFileSystemRepresentation:(const char *)arg1 caseInsensitive:(BOOL)arg2;
-(BOOL)isLastPathComponentEqualToFileSystemRepresentation:(const char *)arg1;
-(BOOL)isLastPathComponentEqualToFileSystemRepresentation:(const char *)arg1 caseInsensitive:(BOOL)arg2;

@end


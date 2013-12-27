@class PBXObject;

@interface PBXGlobalID : NSObject <NSCopying> {
    unsigned char _bytes[12];
    PBXObject *_theObject;
}

+(void)setCachesHexStrings:(BOOL)arg1;

-(id)initWithHexString:(NSString*)arg1;

-(NSString*)hexString;

-(void)_cacheHexString:(NSString*)arg1;
-(NSString*)_cachedHexString;

-(void)setRepresentedObject:(id)arg1;
-(id)representedObject;

@end
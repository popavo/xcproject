#import "PBXObject.h"

@interface PBXGlobalID : NSObject<NSCopying> {
  unsigned char _bytes[12];
  PBXObject* _theObject;
}

+ (void)setCachesHexStrings:(BOOL)arg1;

- (id)init;
- (id)initWithHexString:(NSString*)arg1;

- (NSString*)hexString;
- (void)_cacheHexString:(NSString*)arg1;
- (NSString*)_cachedHexString;

- (void)setRepresentedObject:(PBXObject*)arg1;
- (PBXObject*)representedObject;

- (NSString*)description;
- (NSUInteger)hash;
- (BOOL)isEqual:(id)arg1;

@end
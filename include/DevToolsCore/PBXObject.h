@class PBXGlobalID;

@interface PBXObject : NSObject {
  PBXGlobalID* _globalID;
}

+ (NSString*)description;
+ (NSString*)longDescription;
+ (NSString*)innerDescription;
+ (NSString*)innerLongDescriptionWithIndentLevel:(NSUInteger)arg1;

- (PBXGlobalID*)globalID;
- (PBXGlobalID*)globalIDCreateIfNeeded:(BOOL)arg1;

- (NSString*)description;
- (NSString*)longDescription;
- (NSString*)innerDescription;
- (NSString*)innerLongDescriptionWithIndentLevel:(NSUInteger)arg1;

@end

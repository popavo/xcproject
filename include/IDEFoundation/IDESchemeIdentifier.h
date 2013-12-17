@interface IDESchemeIdentifier : NSObject <NSCopying> {
    NSUInteger _hashValue;
    int _sharedState;
    NSString *_schemeName;
    NSString *_containerName;
    NSString *_schemeInstanceGUID;
}
@property (readonly) NSString *schemeInstanceGUID; // @synthesize schemeInstanceGUID=_schemeInstanceGUID;
@property (readonly) NSString *containerName; // @synthesize containerName=_containerName;
@property (readonly) NSString *schemeName; // @synthesize schemeName=_schemeName;
@property (readonly) int sharedState; // @synthesize sharedState=_sharedState;

+(id)schemeIdentifierFromSchemeName:(id)arg1 containerName:(id)arg2;
+(id)schemeIdentifierFromSchemeName:(id)arg1 containerName:(id)arg2 isSharedScheme:(BOOL)arg3;
+(id)schemeIdentifierFromGUID:(id)arg1 schemeName:(id)arg2 containerName:(id)arg3;
+(id)schemeIdentifierFromGUID:(id)arg1 schemeName:(id)arg2 containerName:(id)arg3 isSharedScheme:(BOOL)arg4;

-(id)initWithGUID:(NSString*)arg1 schemeName:(NSString*)arg2 containerName:(NSString*)arg3 shared:(int)arg4;

-(BOOL)isSimilarToSchemeIdentifier:(id)arg1;

@end


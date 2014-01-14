@class XCBuildConfiguration;

@interface XCBuildConfigurationType : NSObject {
    XCBuildConfiguration *_configuration;
    BOOL _isCopy;
}

-(id)appleScriptID;
-(void)setName:(id)arg1;
-(id)name;
-(BOOL)isCopy;
-(void)setIsCopy:(BOOL)arg1;
-(id)initWithConfiguration:(id)arg1;

@end


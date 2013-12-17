@interface IDESchemeCommand : NSObject {
    BOOL _appleInternalOnly;
    NSString *_commandName;
    NSString *_commandNameGerund;
}
@property(readonly, nonatomic) NSString *commandNameGerund; // @synthesize commandNameGerund=_commandNameGerund;
@property(readonly, nonatomic) NSString *commandName; // @synthesize commandName=_commandName;
@property(readonly, nonatomic, getter=isAppleInternalOnly) BOOL appleInternalOnly; // @synthesize appleInternalOnly=_appleInternalOnly;

+(id)availablePrimitiveSchemeCommands;
+(id)allNonAppleInternalPrimitiveSchemeCommands;
+(id)allPrimitiveSchemeCommands;
+(id)availableSchemeCommands;
+(id)allNonAppleInternalSchemeCommands;
+(id)allSchemeCommands;
+(id)installSchemeCommand;
+(id)integrateSchemeCommand;
+(id)analyzeSchemeCommand;
+(id)archiveSchemeCommand;
+(id)profileSchemeCommand;
+(id)testSchemeCommand;
+(id)launchSchemeCommand;

-(id)initWithCommandName:(NSString*)arg1 gerund:(id)arg2 appleInternalOnly:(BOOL)arg3;

@end


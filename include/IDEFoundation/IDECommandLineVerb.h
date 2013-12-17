@interface IDECommandLineVerb : NSObject { }

+(int)performWithEnvironment:(id)arg1;
+(id)fallbackOptionHandlerBlockWithEnvironment:(SEL)arg1 options:(id)arg2;
+(id)optionDefinitionsWithEnvironment:(id)arg1;

@end


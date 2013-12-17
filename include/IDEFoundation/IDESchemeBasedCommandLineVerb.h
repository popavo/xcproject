#import <IDEFoundation/IDEWorkspaceBasedCommandLineVerb.h>

@interface IDESchemeBasedCommandLineVerb : IDEWorkspaceBasedCommandLineVerb { }

+(id)_schemeWithName:(id)arg1 blueprints:(id)arg2 inWorkspace:(id)arg3;
+(BOOL)requiresScheme;
+(int)performWithEnvironment:(id)arg1;
+(id)optionDefinitionsWithEnvironment:(id)arg1;

@end


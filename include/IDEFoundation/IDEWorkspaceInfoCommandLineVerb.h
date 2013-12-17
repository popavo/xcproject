#import <IDEFoundation/IDEWorkspaceBasedCommandLineVerb.h>

@interface IDEWorkspaceInfoCommandLineVerb : IDEWorkspaceBasedCommandLineVerb { }

+(void)_printBlueprintProviderInfo:(id)arg1 withEnvironment:(id)arg2 showAllProjects:(BOOL)arg3 showTargets:(BOOL)arg4 showSchemes:(BOOL)arg5 showConfigurations:(BOOL)arg6 indentationLevel:(unsigned long long)arg7;
+(void)_printSchemesForContainer:(id)arg1 withEnvironment:(id)arg2 indentationLevel:(unsigned long long)arg3;
+(void)_indentToLevel:(unsigned long long)arg1 withEnvironment:(id)arg2;
+(int)performWithEnvironment:(id)arg1;
+(id)optionDefinitionsWithEnvironment:(id)arg1;

@end


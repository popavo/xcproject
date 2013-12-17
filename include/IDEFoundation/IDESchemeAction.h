#import <IDEFoundation/DVTInvalidation.h>
#import <IDEFoundation/DVTXMLUnarchiving.h>

@class DVTStackBacktrace, IDEScheme, IDESchemeBuildableReference, NSArray, NSMutableArray, NSString;

@interface IDESchemeAction : NSObject <DVTXMLUnarchiving, DVTInvalidation> {
    BOOL _hasAwoken;
    IDEScheme *_runContext;
    NSMutableArray *_prePhaseExecutionActions;
    NSMutableArray *_postPhaseExecutionActions;
    IDESchemeBuildableReference *_buildableReferenceToUseForMacroExpansion;
}
@property (retain) IDESchemeBuildableReference *buildableReferenceToUseForMacroExpansion; // @synthesize buildableReferenceToUseForMacroExpansion=_buildableReferenceToUseForMacroExpansion;
@property IDEScheme *runContext; // @synthesize runContext=_runContext;
@property (readonly) NSArray *_postPhaseExecutionActionsProxies;
@property (readonly) NSArray *_prePhaseExecutionActionsProxies;
@property (readonly) BOOL hasAwoken;
@property (copy) NSArray *postPhaseExecutionActions; // @dynamic postPhaseExecutionActions;
@property (copy) NSArray *prePhaseExecutionActions; // @dynamic prePhaseExecutionActions;
@property (readonly) BOOL doesNonActionWork;
@property (readonly) NSString *subtitle;
@property (readonly) NSString *name;
@property (retain) DVTStackBacktrace *creationBacktrace;
@property (readonly) DVTStackBacktrace *invalidationBacktrace;
@property (readonly) NSMutableArray *mutablePostPhaseExecutionActions; // @dynamic mutablePostPhaseExecutionActions;
@property (readonly) NSMutableArray *mutablePrePhaseExecutionActions; // @dynamic mutablePrePhaseExecutionActions;
@property (readonly, nonatomic, getter=isValid) BOOL valid;

+(BOOL)shouldAllowCustomPhaseActions;

-(id)initFromXMLUnarchiver:(id)arg1 archiveVersion:(float)arg2;

-(id)updateSearchPathSettingsInEnvironment:(id)arg1 withBuildProducts:(id)arg2 runDestination:(id)arg3;
-(void)addPostActions:(id)arg1 fromXMLUnarchiver:(id)arg2;
-(void)addPreActions:(id)arg1 fromXMLUnarchiver:(id)arg2;
-(void)dvt_encodeRelationshipsWithXMLArchiver:(id)arg1 version:(id)arg2;
-(void)dvt_encodeAttributesWithXMLArchiver:(id)arg1 version:(id)arg2;
-(void)dvt_awakeFromXMLUnarchiver:(id)arg1;
-(void)replacePostPhaseExecutionActionsAtIndexes:(id)arg1 withPostPhaseExecutionActions:(id)arg2;
-(void)replaceObjectInPostPhaseExecutionActionsAtIndex:(unsigned long long)arg1 withObject:(id)arg2;
-(void)removePostPhaseExecutionActionsAtIndexes:(id)arg1;
-(void)insertPostPhaseExecutionActions:(id)arg1 atIndexes:(id)arg2;
-(void)removeObjectFromPostPhaseExecutionActionsAtIndex:(unsigned long long)arg1;
-(void)insertObject:(id)arg1 inPostPhaseExecutionActionsAtIndex:(unsigned long long)arg2;
-(void)replacePrePhaseExecutionActionsAtIndexes:(id)arg1 withObjects:(id)arg2;
-(void)replaceObjectInPrePhaseExecutionActionsAtIndex:(unsigned long long)arg1 withObject:(id)arg2;
-(void)removePrePhaseExecutionActionsAtIndexes:(id)arg1;
-(void)insertPrePhaseExecutionActions:(id)arg1 atIndexes:(id)arg2;
-(void)removeObjectFromPrePhaseExecutionActionsAtIndex:(unsigned long long)arg1;
-(void)insertObject:(id)arg1 inPrePhaseExecutionActionsAtIndex:(unsigned long long)arg2;
-(void)primitiveInvalidate;
-(id)expandMacrosInString:(id)arg1 forSchemeCommand:(id)arg2;
-(id)setUpActionDependenciesForCorePhaseOperation:(id)arg1 shouldRunPostActionsBlock:(id)arg2 prePhaseEnvironmentPopulationBlock:(void)arg3 postPhaseEnvironmentPopulationBlock:(id)arg4 buildParameters:(void)arg5 schemeActionResultOperation:(id)arg6 error:(void)arg7;

@end


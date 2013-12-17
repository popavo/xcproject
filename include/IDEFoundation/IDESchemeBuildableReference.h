#import <IDEFoundation/DVTXMLUnarchiving.h>
#import <IDEFoundation/IDEBlueprint.h>
#import <IDEFoundation/IDEBlueprintProvider.h>
#import <IDEFoundation/IDEBuildable.h>

@class DVTObservingToken, IDEContainer, IDEScheme, NSString;

@interface IDESchemeBuildableReference : NSObject <DVTXMLUnarchiving, NSCopying> {
    NSString *_buildableIdentifier;
    NSString *_blueprintIdentifier;
    NSString *_cachedBuildableName;
    NSString *_cachedBlueprintName;
    NSString *_legacyBuildableIdentifier;
    IDEContainer<IDEBlueprintProvider> *_referencedContainer;
    NSString *_lastArchivedReferencedContainerPath;
    IDEScheme *_scheme;
    DVTObservingToken *_referencedContainersObservingToken;
    DVTObservingToken *_schemeClosedToken;
    DVTObservingToken *_schemeValidToken;
    DVTObservingToken *_referencedContainerFilePathObservingToken;
    DVTObservingToken *_referencedContainerIsValidObservingToken;
    DVTObservingToken *_resolvedBuildableNameObservingToken;
    DVTObservingToken *_resolvedBlueprintNameObservingToken;
    BOOL _resolvingBlueprint;
}
@property(copy) NSString *cachedBlueprintName; // @synthesize cachedBlueprintName=_cachedBlueprintName;
@property(copy) NSString *cachedBuildableName; // @synthesize cachedBuildableName=_cachedBuildableName;
@property(retain, nonatomic) IDEContainer<IDEBlueprintProvider> *referencedContainer; // @synthesize referencedContainer=_referencedContainer;
@property(copy) NSString *buildableIdentifier; // @synthesize buildableIdentifier=_buildableIdentifier;
@property(retain, nonatomic) IDEScheme *scheme; // @synthesize scheme=_scheme;
@property(readonly) NSString *blueprintName;
@property(readonly) NSString *buildableName;
@property(readonly) id <IDEBuildable> resolvedBuildable;
@property(readonly) id <IDEBlueprint> resolvedBlueprint;
@property(copy) NSString *blueprintIdentifier; // @synthesize blueprintIdentifier=_blueprintIdentifier;

+(id)resolvedBuildableForLegacyIdentifier:(id)arg1 inContainer:(id)arg2;
+(id)keyPathsForValuesAffectingBlueprintName;
+(id)keyPathsForValuesAffectingBuildableName;
+(id)keyPathsForValuesAffectingResolvedBuildable;
+(id)keyPathsForValuesAffectingResolvedBlueprint;

-(id)initWithBuildable:(id)arg1 scheme:(id)arg2;
-(id)initFromXMLUnarchiver:(id)arg1 archiveVersion:(float)arg2;

-(void)dvt_encodeRelationshipsWithXMLArchiver:(id)arg1 version:(id)arg2;
-(void)dvt_encodeAttributesWithXMLArchiver:(id)arg1 version:(id)arg2;
-(void)setReferencedContainerFromUTF8String:(char *)arg1 fromXMLUnarchiver:(id)arg2;
-(void)setBlueprintNameFromUTF8String:(char *)arg1 fromXMLUnarchiver:(id)arg2;
-(void)setBuildableNameFromUTF8String:(char *)arg1 fromXMLUnarchiver:(id)arg2;
-(void)setBlueprintIdentifierFromUTF8String:(char *)arg1 fromXMLUnarchiver:(id)arg2;
-(void)setBuildableIdentifierFromUTF8String:(char *)arg1 fromXMLUnarchiver:(id)arg2;
-(void)setBuildableProductIdentifierFromUTF8String:(char *)arg1 fromXMLUnarchiver:(id)arg2;
-(void)loadLegacyBuildableWithResolutionContextContainer:(id)arg1;
-(void)resolveBuildableFromImport;
-(BOOL)referencesSameBuildableAsReference:(id)arg1;
-(id)currentReferencedContainerPath;
-(id)referencedContainerFromSchemeForArchivedPath:(id)arg1;
-(id)referenceResolutionContext;
-(id)containerReferenceResolver;
-(BOOL)updateCachedBuildableName;
-(BOOL)updateCachedBlueprintName;
-(void)setBlueprintIdentifierWithoutTriggeringResolvedBlueprintKVO:(id)arg1;

@end


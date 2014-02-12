@class XCSpecification_ivars;

@interface XCSpecification : NSObject

+ (BOOL)_booleanValueForValue:(id)arg1;
+ (void)loadSpecificationsWithProperty:(id)arg1;
+ (Class)specificationBaseClassForType:(id)arg1;
+ (id)specificationTypeForPathExtension:(id)arg1;
+ (id)allRegisteredSpecifications;
+ (id)registeredBaseSpecifications;
+ (id)registeredBaseSpecificationsInDomain:(id)arg1;
+ (id)_subSpecificationsOfSpecification:(id)arg1 inDomain:(id)arg2;
+ (id)registeredSpecifications;
+ (id)registeredSpecificationsInDomain:(id)arg1;
+ (id)registeredSpecificationsInDomainOrDefault:(id)arg1;
+ (id)specificationsForIdentifiers:(id)arg1;
+ (id)specificationsForIdentifiers:(id)arg1 inDomain:(id)arg2;
+ (id)specificationForIdentifier:(id)arg1;
+ (id)specificationForIdentifier:(id)arg1 inDomain:(id)arg2;
+ (void)_getDomain:(id*)arg1 identifier:(id*)arg2 fromDomainPrefixedIdentifier:(id)arg3;
+ (id)registerSpecificationProxiesFromPropertyListsInDirectory:(id)arg1 recursively:(BOOL)arg2;
+ (id)registerSpecificationProxiesFromPropertyListsInDirectory:(id)arg1 recursively:(BOOL)arg2 inDomain:(id)arg3;
+ (id)registerSpecificationProxiesFromPropertyListsInDirectory:(id)arg1 recursively:(BOOL)arg2 inDomain:(id)arg3 inBundle:(id)arg4;
+ (BOOL)_shouldRecurseIntoDirectoryNamed:(id)arg1 ofType:(id)arg2;
+ (id)_registerSpecificationProxiesOfType:(id)arg1
                    fromDictionaryOrArray:(id)arg2
                              inDirectory:(id)arg3
                                   bundle:(id)arg4
                        sourceDescription:(id)arg5
                                 inDomain:(id)arg6;
+ (id)registerSpecificationProxyFromPropertyList:(id)arg1;
+ (id)registerSpecificationProxyFromPropertyList:(id)arg1 inDomain:(id)arg2;
+ (void)registerSpecificationOrProxy:(id)arg1;
+ (void)registerSpecificationTypeBaseClass:(Class)arg1;
+ (id)_pathExensionsToTypesRegistry;
+ (id)_typesToSpecTypeBaseClassesRegistry;
+ (id)specificationRegistryForDomain:(id)arg1;
+ (id)specificationRegistryName;
+ (id)specificationTypePathExtensions;
+ (id)localizedSpecificationTypeName;
+ (id)specificationType;
+ (Class)specificationTypeBaseClass;

- (id)arrayOrStringForKey:(id)arg1;
- (BOOL)boolForKeyFromProxy:(id)arg1;
- (BOOL)boolForKey:(id)arg1;
- (double)doubleForKey:(id)arg1;
- (float)floatForKey:(id)arg1;
- (long long)longLongForKey:(id)arg1;
- (NSInteger)integerForKey:(id)arg1;
- (id)dataForKey:(id)arg1;
- (id)dictionaryForKey:(id)arg1;
- (id)arrayForKey:(id)arg1;
- (id)stringForKey:(id)arg1;
- (id)objectForKey:(id)arg1;
- (id)_objectForKeyIgnoringInheritance:(id)arg1;
- (NSInteger)nameCompare:(id)arg1;
- (NSInteger)identifierCompare:(id)arg1;
- (id)localizedDescription;
- (id)name;
- (id)domain;
- (id)bundle;
- (id)localizationDictionary;
- (id)properties;
- (id)type;
- (id)identifier;
- (BOOL)isMissingSpecificationProxy;
- (id)loadedSpecification;
- (BOOL)isNotYetLoadedSpecificationProxy;
- (BOOL)isAbstract;
- (BOOL)isKindOfSpecification:(id)arg1;
- (id)subSpecifications;
- (id)subSpecificationsInDomain:(id)arg1;
- (id)superSpecification;
- (id)initAsMissingSpecificationProxyWithIdentifier:(id)arg1 name:(id)arg2 description:(id)arg3 inDomain:(id)arg4;
- (id)initWithPropertyListDictionary:(id)arg1;
- (id)initWithPropertyListDictionary:(id)arg1 inDomain:(id)arg2;

@end

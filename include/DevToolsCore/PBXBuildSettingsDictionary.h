@interface PBXBuildSettingsDictionary : NSMutableDictionary {
    NSMutableDictionary *_buildSettings;
    NSMutableDictionary *_conditionalBuildSettings;
    NSMutableDictionary *_buildSettingToConditionSetMap;
    id _delegate;
    int _definitionLevel;
    struct {
        unsigned int delegateWantsWillSet:1;
        unsigned int delegateWantsDidSet:1;
        unsigned int delegateWantsShouldExtractQuotedBuildSettingsWhenSplitting:1;
        unsigned int RESERVED:29;
    } _bsFlags;
    NSUInteger _changeCount;
    NSUInteger _keyChangeCount;
    NSUndoManager *_undoManager;
}

+ (id)expandedBuildSettingForString:(id)arg1 withExpansionDictionaries:(id)arg2;
+ (id)baseNameForPropertyName:(id)arg1 returningConditionSet:(id *)arg2;
+ (id)baseNameForPropertyName:(id)arg1 returningConditionSet:(id *)arg2 returningLocalizedErrorString:(id *)arg3;
+ (id)dictionaryByParsingStringAsBuildSettingAssignments:(id)arg1 getLocalizedErrorString:(id *)arg2;
+ (id)buildSettingAssignmentParsedFromString:(id)arg1 getLocalizedErrorString:(id *)arg2;
+ (id)dictionaryWithDefinitionLevel:(int)arg1;
+ (id)dictionaryWithDictionary:(id)arg1 definitionLevel:(int)arg2;
+ (id)dictionaryWithDictionary:(id)arg1;
+ (id)dictionaryWithKeysAndObjects:(id)arg1;
+ (id)dictionary;

- (id)initWithDictionary:(id)arg1;
- (id)initWithDictionaryNoCopy:(id)arg1;

+ (id)_jambaseToNativeBuildSettingConversionRules;
- (id)descriptionWithLocale:(id)arg1 indent:(NSUInteger)arg2;
- (BOOL)upgradeBuildSettingsFromArchivedObjectVersion:(NSUInteger)arg1;
- (id)project;
- (void)setDelegate:(id)arg1;
- (id)delegate;
- (int)definitionLevel;
- (void)setDefinitionLevel:(int)arg1;
- (NSUInteger)keyChangeCount;
- (NSUInteger)changeCount;
- (id)undoManager;
- (void)appendStringList:(id)arg1 toStringListBuildSettingForKey:(id)arg2;
- (void)setStringListBuildSetting:(id)arg1 forKey:(id)arg2;
- (id)stringListBuildSettingForKey:(id)arg1;
- (id)conditionSetsForKeyPath:(id)arg1;
- (id)orderedConditionalDictionariesForConditionSet:(id)arg1;
- (id)conditionalDictionaryForConditionSet:(id)arg1;
- (id)conditionalDictionaries;
- (id)conditionSets;

- (id)baseNameForPropertyName:(id)arg1 returningConditionSet:(id *)arg2;
- (id)baseNameForPropertyName:(id)arg1 returningConditionSet:(id *)arg2 returningLocalizedErrorString:(id *)arg3;

- (BOOL)isConditional;

- (void)removeBuildSettingForKeyPath:(id)arg1;
- (void)setBuildSetting:(id)arg1 forKeyPath:(id)arg2;
- (void)setBuildSetting:(id)arg1 forKeyPath:(id)arg2 conditionSet:(id)arg3;
- (void)setBuildSetting:(id)arg1 operation:(int)arg2 forKeyPath:(id)arg3;

- (id)buildSettingForKeyPath:(id)arg1;
- (id)buildSettingForKeyPath:(id)arg1 conditionSet:(id)arg2;
- (id)buildSettingForKeyPath:(id)arg1 getOperation:(int *)arg2;

- (void)removeBuildSettingForKeyPath:(id)arg1 conditionSet:(id)arg2;
- (void)setBuildSetting:(id)arg1 operation:(int)arg2 forKeyPath:(id)arg3 conditionSet:(id)arg4;
- (id)buildSettingForKeyPath:(id)arg1 conditionSet:(id)arg2 getOperation:(int *)arg3;

- (BOOL)isEqualToDictionary:(id)arg1;
- (void)addEntriesFromDictionary:(id)arg1;
- (void)removeObjectForKey:(id)arg1;
- (void)setObject:(id)arg1 forKey:(id)arg2;
- (id)objectForKey:(id)arg1;
- (id)allValues;
- (id)allKeys;
- (id)keyEnumerator;
- (NSUInteger)count;
- (void)_undoRedoBuildSettingOperation:(id)arg1;
- (id)_buildSettings;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)_unarchiveArchsStandardSettingsUsingDict:(id)arg1;
- (void)_archiveArchsStandardSettingsUsingDict:(id)arg1;
- (id)_absoluteArchiveRepresentationForSDKROOTValue:(id)arg1;
- (id)_unarchivedRepresentationForSDKROOTValue:(id)arg1;
- (id)initFromArchivedDictionaryRepresentation:(id)arg1;
- (id)archivedDictionaryRepresentation;

- (void)_extractConditionalDictionaries;
- (void)_setObject:(id)arg1 forKey:(id)arg2 conditionSet:(id)arg3;
- (void)convertBuildSettingsFromJambasedToNativeForTarget:(id)arg1 withUpgradeLog:(id)arg2;

@end
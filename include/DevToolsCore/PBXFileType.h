#import "XCSpecification.h"

@interface PBXFileType : XCSpecification {
  NSArray* _extensions;
}

+ (id)fileTypeForPath:(id)arg1;
+ (id)fileTypeUsingFileAttributesAtPath:(id)arg1;
+ (id)fileTypeForPath:(id)arg1 getExtraFileProperties:(id*)arg2;
+ (id)guessFileTypeForGenericFileAtPath:(id)arg1 withFileAttributes:(id)arg2 getExtraFileProperties:(id*)arg3;
+ (id)fileTypeForFilenamePattern:(id)arg1 isFolder:(BOOL)arg2;
+ (id)fileTypeMatchingPatternsForFileName:(id)arg1;
+ (id)fileTypeForFileName:(id)arg1;
+ (id)fileTypeForFileName:(id)arg1 posixPermissions:(NSUInteger)arg2 hfsTypeCode:(unsigned int)arg3 hfsCreatorCode:(unsigned int)arg4;
+ (id)bestFileTypeForRepresentingFileAtPath:(id)arg1 withFileAttributes:(id)arg2 withLessSpecificFileType:(id)arg3 getExtraFileProperties:(id*)arg4;
+ (id)wrapperFolderType;
+ (id)genericFolderType;
+ (id)textFileType;
+ (id)genericFileType;
+ (id)_fileTypeDetectorArray;
+ (id)_fileNamePatternToFileTypeDictionary;
+ (id)_magicWordToFileTypeDictionary;
+ (id)_lowercasedExtensionToFileTypeDictionary;
+ (id)_extensionToFileTypeDictionary;
+ (void)registerSpecificationOrProxy:(id)arg1;
+ (id)specificationRegistryName;
+ (id)specificationTypePathExtensions;
+ (id)localizedSpecificationTypeName;
+ (id)specificationType;
+ (Class)specificationTypeBaseClass;

- (id)initWithPropertyListDictionary:(id)arg1 inDomain:(id)arg2;
- (id)_objectForKeyIgnoringInheritance:(id)arg1;
- (id)fileTypePartForIdentifier:(id)arg1;
- (id)subpathForWrapperPart:(int)arg1 ofPath:(id)arg2 withExtraFileProperties:(id)arg3;
- (id)extraPropertyNames;
- (BOOL)requiresHardTabs;
- (BOOL)isScannedForIncludes;
- (id)plistStructureDefinitionIdentifier;
- (id)xcLanguageSpecificationIdentifier;
- (id)languageSpecificationIdentifier;
- (BOOL)canSetIncludeInIndex;
- (BOOL)isTransparent;
- (BOOL)includeInIndex;
- (BOOL)isWrapperFolder;
- (BOOL)isNonWrapperFolder;
- (BOOL)isFolder;
- (BOOL)isDocumentation;
- (BOOL)isSourceCode;
- (BOOL)isPreprocessed;
- (BOOL)isTextFile;
- (BOOL)isPlainFile;
- (BOOL)isExecutableWithGUI;
- (BOOL)isExecutable;
- (BOOL)isTargetWrapper;
- (BOOL)isProjectWrapper;
- (BOOL)isStaticFramework;
- (BOOL)isFramework;
- (BOOL)isStaticLibrary;
- (BOOL)isDynamicLibrary;
- (BOOL)isLibrary;
- (BOOL)isApplication;
- (BOOL)isBundle;
- (id)hfsTypeCodes;
- (id)extensions;

@end

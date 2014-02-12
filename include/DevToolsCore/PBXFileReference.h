#import "PBXReference.h"

@class PBXContainer, PBXFileType;

@interface PBXFileReference : PBXReference {
  PBXContainer* _loadedContainer;
  PBXFileType* _lastKnownFileType;
  NSDictionary* _lastKnownFileProperties;
  PBXFileType* _explicitFileType;
  NSDictionary* _explicitFileProperties;
}

+ (id)defaultExpectedFileTypeForPath:(id)arg1;
+ (BOOL)canRepresentFileAtPath:(id)arg1;
+ (BOOL)canRepresentFileAtPath:(id)arg1 ofType:(id)arg2;

- (id)initWithName:(id)arg1 path:(id)arg2 sourceTree:(id)arg3;
- (id)initWithName:(id)arg1 path:(id)arg2 sourceTree:(id)arg3 fileType:(id)arg4 extraFileProperties:(id)arg5;

- (BOOL)usesTabs;
- (long long)indentWidth;
- (BOOL)isProductReference;
- (id)unexpandedAbsolutePathForWrapperPart:(int)arg1;
- (id)absolutePathForWrapperPart:(int)arg1;
- (id)resolvedAbsolutePathForWrapperPart:(int)arg1;
- (id)subpathForWrapperPart:(int)arg1;
- (void)setExplicitFileTypeIfNil:(id)arg1;
- (void)setExplicitFileType:(id)arg1;
- (void)setExplicitFileType:(id)arg1 explicitFileProperties:(id)arg2;
- (BOOL)userCanSetExplicitFileType;
- (id)fileProperties;
- (id)fileType;
- (void)setLanguageSpecificationIdentifier:(id)arg1;
- (id)languageSpecificationIdentifier;
- (void)setXcLanguageSpecificationIdentifier:(id)arg1;
- (id)xcLanguageSpecificationIdentifier;
- (BOOL)deleteFromProjectAndDisk:(BOOL)arg1;
- (void)setContainer:(id)arg1;
- (id)resolvedAbsolutePath;
- (void)setPath:(id)arg1 andSourceTree:(id)arg2;
- (id)loadedContainer;
- (id)children;
- (void)setLoadedContainer:(id)arg1;

@end

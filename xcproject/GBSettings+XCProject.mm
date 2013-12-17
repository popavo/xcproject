#import "GBSettings+XCProject.h"

@implementation GBSettings (XCProject)

+(GBSettings*) projectSettingsWithName:(NSString *)name parent:(GBSettings *)parent {
  id result = [self settingsWithName:name parent:parent];
	if (result) {
		[result registerArrayForKey:GBSettingKeys.inputPaths];
	}
	return result;
}

#pragma mark - Paths

GB_SYNTHESIZE_OBJECT(NSArray *, inputPaths, setInputPaths, GBSettingKeys.inputPaths)

@end

const struct GBSettingKeys GBSettingKeys = {
	.inputPaths = @"input",

  .workspace = @"workspace",
  .project = @"project",
  .scheme = @"scheme",
  .target = @"target",
  .configuration = @"configuration",
  .group = @"group",
};
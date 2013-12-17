@protocol IDEBuildSettingsProvider <NSObject>
-(id)absolutePathByEvaluatingBuildSettingExpressionString:(id)arg1 withBuildParameters:(id)arg2;
-(id)stringByEvaluatingBuildSettingExpressionString:(id)arg1 withBuildParameters:(id)arg2;
-(id)evaluatedStringListValueForBuildSetting:(id)arg1 withBuildParameters:(id)arg2;
-(id)evaluatedStringValueForBuildSetting:(id)arg1 withBuildParameters:(id)arg2;
-(id)allBuildSettingNamesWithBuildParameters:(id)arg1;
@end
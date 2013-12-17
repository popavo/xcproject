@class IDEActivityLogSection;

@protocol IDEIntegrityLogDataSource
@property(readonly) IDEActivityLogSection *integrityLog;
-(void)analyzeModelIntegrity;
@end


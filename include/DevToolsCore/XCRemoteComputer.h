@class XCPlatformSpecification;

@protocol XCRemoteComputer <NSObject>

@property(readonly) BOOL canRenameDevice;
@property(readonly) NSString *deviceSoftwareVersion;
@property(readonly) BOOL deviceHasUI;
@property(readonly) BOOL deviceIsBusy;
@property BOOL deviceIsIgnored;
@property(readonly) BOOL deviceIsTransient;
@property(readonly) BOOL deviceAvailable;
@property(readonly) NSString *cachePath;
@property(readonly) NSString *deviceArchitecture;
@property(readonly) NSString *deviceName;
@property(readonly) XCPlatformSpecification *platform;
@property(readonly) NSString *deviceIdentifier;
@property(readonly) NSString *platformIdentifier;
@property(readonly) NSMutableDictionary *data;

+(void)loadOrganizerCategories;
+(BOOL)handleDroppedFile:(id)arg1;
+(BOOL)shouldHandleDroppedFile:(id)arg1;

-(int)debuggerArchitectureMode;
-(void)willBeForgotten;
-(void)willExecuteCompleted;
-(void)willExecuteFailed;
-(id)setCurrentExecutable:(id)arg1;
-(id)currentRemoteExecutable;
-(void)renameDevice:(id)arg1;
-(id)debuggerAttachList;
-(void)didExecute:(id)arg1;
-(BOOL)willExecute:(id)arg1 debug:(BOOL)arg2 onPort:(long long *)arg3 performInstall:(BOOL)arg4;
-(void)willExecuteAsync:(id)arg1 shouldInstall:(BOOL)arg2;
-(BOOL)useAsyncWillExecute;
-(BOOL)preflightExecutable:(id)arg1;
-(BOOL)canExecute;
-(BOOL)shouldApplicationTerminate;
-(void)invalidate;

@optional
+(bool)archiveApplicationAtURL:(id)arg1 error:(NSError**)arg2;
@end


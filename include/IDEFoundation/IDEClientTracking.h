@protocol IDEClientTracking <NSObject>
-(void)cancelTrackedClients;
-(id)clientsNotSupportingCancellation;
-(id)clientsRequiringCancellationPrompt;
-(id)registerUncancellableClientWithName:(id)arg1;
-(id)registerClientWithName:(id)arg1 promptForCancellation:(BOOL)arg2 cancellationBlock:(id)arg3;
@end


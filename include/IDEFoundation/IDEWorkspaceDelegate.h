#import <IDEFoundation/IDEContainerDelegate.h>

@class IDEWorkspace;

@protocol IDEWorkspaceDelegate <IDEContainerDelegate>
-(void)_workspace:(IDEWorkspace*)arg1 failedToResolveContainerForProjectFile:(id)arg2;

@optional
-(void)_workspace:(IDEWorkspace*)arg1 didChangeSimpleFilesFocusedTo:(BOOL)arg2;
-(void)_workspace:(IDEWorkspace*)arg1 didChangeFinishedLoadingTo:(BOOL)arg2;
@end


@class DVTStackBacktrace;

@protocol DVTInvalidation <NSObject>
-(void)primitiveInvalidate;

@optional
@property (retain) DVTStackBacktrace *creationBacktrace;
@property (readonly) DVTStackBacktrace *invalidationBacktrace;
@property (readonly, nonatomic, getter=isValid) BOOL valid;
-(void)invalidate;
@end


//
//  Logging.h
//  xcproject
//
//  Created by Brian K Garrett on 2/6/14.
//
//

#ifndef xcproject_Logging_h
#define xcproject_Logging_h

#import "p.h"

#if defined(DEBUG)

#undef LOG

#define LOG(_format, ...) fprintf(stderr, "%s\n", StringRef().appendFormat((_format), ##__VA_ARGS__).c_str())

#else

#define LOG(_format, ...)

#endif

#if defined(__cplusplus)

#define op(arg) std::cout << npStringFromAnyType(@encode(__typeof__(arg)), (arg)) << std::endl;

#else

#define op(arg) printf("%s\n", npStringFromAnyType(@encode(__typeof__(arg)), (arg)).UTF8String)

#endif

#endif

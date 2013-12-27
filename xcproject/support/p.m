//
//  p.m
//  p
//
//  Created by Stephen Sykes on 13/10/13.
//  Copyright (c) 2013 BinaryAge. All rights reserved.
//

#import "p.h"

#define npNSStringForType(type, stringFunction) \
    if (strcmp(typeCode, @encode(type)) == 0) {\
        type arg = va_arg(listPointer, type);\
        va_end(listPointer);\
        return stringFunction(arg);\
    }

#define npNSStringForSimpleType(type, va_argType, formatString) \
    if (strcmp(typeCode, @encode(type)) == 0) {\
        va_argType arg = va_arg(listPointer, va_argType);\
        va_end(listPointer);\
        return [NSString stringWithFormat:formatString, arg];\
    }


NSString * npStringFromAnyType(const char *typeCode, ...) {
    va_list listPointer;
    va_start(listPointer, typeCode);
    
#if TARGET_OS_IPHONE
    npNSStringForType(CGPoint, NSStringFromCGPoint);
    npNSStringForType(CGRect, NSStringFromCGRect);
    npNSStringForType(CGSize, NSStringFromCGSize);
    npNSStringForType(CGAffineTransform, NSStringFromCGAffineTransform);
    npNSStringForType(UIEdgeInsets, NSStringFromUIEdgeInsets);
    npNSStringForType(UIOffset, NSStringFromUIOffset);
#else
    npNSStringForType(CGPoint, NSStringFromPoint);
    npNSStringForType(CGRect, NSStringFromRect);
    npNSStringForType(CGSize, NSStringFromSize);
#endif
    
    npNSStringForType(SEL, NSStringFromSelector);
    npNSStringForType(Class, NSStringFromClass);
    npNSStringForType(NSRange, NSStringFromRange);
    npNSStringForType(id, );

    npNSStringForSimpleType(BOOL, int, @"%d");
    npNSStringForSimpleType(int, int, @"%d");
    npNSStringForSimpleType(short, int, @"%d");
    npNSStringForSimpleType(unsigned int, unsigned int, @"%u");
    npNSStringForSimpleType(unsigned short, unsigned int, @"%u");
    npNSStringForSimpleType(long, long, @"%li");
    npNSStringForSimpleType(unsigned long, unsigned long, @"%lu");
    npNSStringForSimpleType(long long, long long, @"%lli");
    npNSStringForSimpleType(unsigned long long, unsigned long long, @"%llu");
    npNSStringForSimpleType(float, double, @"%f");
    npNSStringForSimpleType(double, double, @"%f");
    npNSStringForSimpleType(char *, char *, @"%s");
    npNSStringForSimpleType(unsigned char *, unsigned char *, @"%s");
    
    if (*typeCode == '[' && strspn(typeCode, "[]1234567890c") == strlen(typeCode)) {
        char *arg = va_arg(listPointer, char *);
        va_end(listPointer);
        return [NSString stringWithFormat:@"%s", arg];
    }

    if (*typeCode == '^' ) {
        void *arg = va_arg(listPointer, void *);
        va_end(listPointer);
        return [NSString stringWithFormat:@"%p", arg];
    }

    return @"(unknown type)";
}

#define pNSStringForType(type, stringFunction) \
    if (strcmp(typeCode, @encode(type)) == 0) {\
        type arg = va_arg(listPointer, type);\
        va_end(listPointer);\
        return stringFunction(arg).UTF8String;\
    }

#define pNSStringForSimpleType(type, va_argType, formatString) \
    if (strcmp(typeCode, @encode(type)) == 0) {\
        va_argType arg = va_arg(listPointer, va_argType);\
        va_end(listPointer);\
        return [NSString stringWithFormat:formatString, arg].UTF8String;\
    }

const char* pStringFromAnyType(const char *typeCode, ...) {
  va_list listPointer;
  va_start(listPointer, typeCode);

#if TARGET_OS_IPHONE
  pNSStringForType(CGPoint, NSStringFromCGPoint);
  pNSStringForType(CGRect, NSStringFromCGRect);
  pNSStringForType(CGSize, NSStringFromCGSize);
  pNSStringForType(CGAffineTransform, NSStringFromCGAffineTransform);
  pNSStringForType(UIEdgeInsets, NSStringFromUIEdgeInsets);
  pNSStringForType(UIOffset, NSStringFromUIOffset);
#else
  pNSStringForType(CGPoint, NSStringFromPoint);
  pNSStringForType(CGRect, NSStringFromRect);
  pNSStringForType(CGSize, NSStringFromSize);
#endif

  pNSStringForType(SEL, NSStringFromSelector);
  pNSStringForType(Class, NSStringFromClass);
  pNSStringForType(NSRange, NSStringFromRange);
  pNSStringForSimpleType(id, id, @"%@");

  pNSStringForSimpleType(BOOL, int, @"%d");
  pNSStringForSimpleType(int, int, @"%d");
  pNSStringForSimpleType(short, int, @"%d");
  pNSStringForSimpleType(unsigned int, unsigned int, @"%u");
  pNSStringForSimpleType(unsigned short, unsigned int, @"%u");
  pNSStringForSimpleType(long, long, @"%li");
  pNSStringForSimpleType(unsigned long, unsigned long, @"%lu");
  pNSStringForSimpleType(long long, long long, @"%lli");
  pNSStringForSimpleType(unsigned long long, unsigned long long, @"%llu");
  pNSStringForSimpleType(float, double, @"%f");
  pNSStringForSimpleType(double, double, @"%f");
  pNSStringForSimpleType(char *, char *, @"%s");
  pNSStringForSimpleType(unsigned char *, unsigned char *, @"%s");

  if (*typeCode == '[' && strspn(typeCode, "[]1234567890c") == strlen(typeCode)) {
    char *arg = va_arg(listPointer, char *);
    va_end(listPointer);
    return [NSString stringWithFormat:@"%s", arg].UTF8String;
  }

  if (*typeCode == '^' ) {
    void *arg = va_arg(listPointer, void *);
    va_end(listPointer);
    return [NSString stringWithFormat:@"%p", arg].UTF8String;
  }

  return "(unknown type)";
}

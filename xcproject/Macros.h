#if defined(DEBUG)
# define ERROR(format, ...) NSBeep(), NSLog(format, ## __VA_ARGS__)
#else
# define ERROR(format, ...) NSLog(format, ## __VA_ARGS__)
#endif
#define INFO(format, ...) NSLog(format, ## __VA_ARGS__)

#ifndef __has_attribute         // Optional of course.
# define __has_attribute(x) 0 // Compatibility with non-clang compilers.
#endif

#if !defined(FORCE_INLINE)
# if __has_attribute(always_inline)
#  define FORCE_INLINE __inline__ __attribute__((always_inline))
# else
#  define FORCE_INLINE __inline__
# endif
#endif

#if (__cplusplus && __cplusplus >= 201103L && (__has_extension(cxx_strong_enums) || __has_feature(objc_fixed_enum))) || (!__cplusplus && __has_feature(objc_fixed_enum))
# define XC_ENUM(_type, _name) typedef enum _name : _type _name; enum _name : _type
# if (__cplusplus)
#  define XC_OPTIONS(_type, _name) typedef _type _name; enum : _type
# else
#  define XC_OPTIONS(_type, _name) typedef enum _name : _type _name; enum _name : _type
# endif
#else
# define XC_ENUM(_type, _name) typedef _type _name; enum
# define XC_OPTIONS(_type, _name) typedef _type _name; enum
#endif

// http://clang-analyzer.llvm.org/annotations.html#attr_nonnull
#define NONNULL(...) __attribute__((nonnull(__VA_ARGS__)))

#define XCP_STR(x) #x
#define XCP_STRINGIFY(macro) XCP_STR(macro)

#if !defined(VERSION_STR)
# if defined(XCP_VERSION)
#  define VERSION_STR XCP_STRINGIFY(XCP_VERSION)
#  define VERSION (@ VERSION_STR)
# endif
#endif

#if !defined(BUILD_STR)
# if defined(XCP_BUILD)
#  define BUILD_STR XCP_STRINGIFY(XCP_BUILD)
#  define BUILD (@ BUILD_STR)
#endif
#endif


#if !defined(EQ_OPERATOR)
# define EQ_OPERATOR(__type, __test) \
   bool operator ==(__type rs) const { return __test; } \
   bool operator !=(__type rs) const { return !(*this == rs); }
#endif

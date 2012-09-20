#ifndef OS_TYPES_HEADER
#define OS_TYPES_HEADER

#include <TargetConditionals.h> /* Do not rely on this imports in your software (libkern, obviously, does not perform it) */
#include <AvailabilityMacros.h>

#if TARGET_OS_MAC || (defined(TARGET_OS_DARWIN) && TARGET_OS_DARWIN)
    #if MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_6
        #include <libkern/OSBase.h>
    #else
        #include <libkern/OSTypes.h>
    #endif
#else


#if !defined(OS_INLINE)
    #if defined(__GNUC__)
        #define OS_INLINE static __inline__ __attribute__((always_inline))
    #elif defined(__MWERKS__) || defined(__cplusplus)
        #define OS_INLINE static inline
    #elif defined(_MSC_VER)
        #define OS_INLINE static __inline
    #elif TARGET_OS_WIN32
        #define OS_INLINE static __inline__
    #endif
#endif

/* OS-specific includes should follow */


#endif /* TARGET_OS_DARWIN */
#endif /* OS_TYPES_HEADER */
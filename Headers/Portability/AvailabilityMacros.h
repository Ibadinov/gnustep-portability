/*
 * Some basic macros related to feature-availability
 */

#ifndef __AVAILABILITYMACROS__ /* Needs to be compatibale with Apple's counterpart */
#define __AVAILABILITYMACROS__

/*
 * Define Apple-compatible API version numbers (if not already defined by GSVersionMacros.h)
 */

#if	!defined(MAC_OS_X_VERSION_10_0)
    #define MAC_OS_X_VERSION_10_0   1000
    #define MAC_OS_X_VERSION_10_1   1010
    #define MAC_OS_X_VERSION_10_2   1020
    #define MAC_OS_X_VERSION_10_3   1030
    #define MAC_OS_X_VERSION_10_4   1040
    #define MAC_OS_X_VERSION_10_5   1050
    #define MAC_OS_X_VERSION_10_6   1060
    #define MAC_OS_X_VERSION_10_7   1070
#endif

/*
 * Validate/define MAC_OS_X_VERSION_MIN_REQUIRED and MAC_OS_X_VERSION_MAX_ALLOWED
 */

#if !defined(MAC_OS_X_VERSION_MIN_REQUIRED)
    #if defined(__arm__)
        #define MAC_OS_X_VERSION_MIN_REQUIRED MAC_OS_X_VERSION_10_5
    #elif defined(__x86_64__) || defined(__i386__) || defined(__ppc64__)
        #define MAC_OS_X_VERSION_MIN_REQUIRED MAC_OS_X_VERSION_10_4 
    #else
        #define MAC_OS_X_VERSION_MIN_REQUIRED MAC_OS_X_VERSION_10_2 /* Just a random value, feel free to correct */
    #endif
#endif

#if !defined(MAC_OS_X_VERSION_MAX_ALLOWED)
    #if MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_6
        #define MAC_OS_X_VERSION_MAX_ALLOWED MAC_OS_X_VERSION_MIN_REQUIRED
    #else
        #define MAC_OS_X_VERSION_MAX_ALLOWED MAC_OS_X_VERSION_10_7 /* GNUstep's CFBase.h sets this to 100700 */
    #endif
#endif

#if MAC_OS_X_VERSION_MAX_ALLOWED < MAC_OS_X_VERSION_MIN_REQUIRED
    #error AvailabilityMacros.h: required platform version is greater than max allowed
#endif

/*
 * Define attribute wrappers: DEPRECATED_ATTRIBUTE, UNAVAILABLE_ATTRIBUTE, WEEK_IMPORT_ATTRIBUTE
 */

#if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
    #define AVAILABILITY_MACROS_GCC_31 1
#else
    #define AVAILABILITY_MACROS_GCC_31 0
#endif

#if AVAILABILITY_MACROS_GCC_31
    #define DEPRECATED_ATTRIBUTE __attribute__((deprecated))
    #define UNAVAILABLE_ATTRIBUTE __attribute__((unavailable))
#else
    #define DEPRECATED_ATTRIBUTE
    #define UNAVAILABLE_ATTRIBUTE
#endif

#if MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_2
    #if AVAILABILITY_MACROS_GCC_31 || (defined(__MWERKS__) && (__MWERKS__ >= 12805)) /* 0x3205 */
        #define WEAK_IMPORT_ATTRIBUTE __attribute__((weak_import))
    #else
        #define WEAK_IMPORT_ATTRIBUTE
    #endif
#else
    #define WEAK_IMPORT_ATTRIBUTE
#endif

#endif /* __AVAILABILITYMACROS__ */
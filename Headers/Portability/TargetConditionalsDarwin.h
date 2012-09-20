/*
 * Should be included on Darwin
 */

#ifndef __TARGETCONDITIONALS_DARWIN__
#define __TARGETCONDITIONALS_DARWIN__

#define TARGET_OS_MAC               1
#define TARGET_OS_EMBEDDED          0
#define TARGET_OS_IPHONE            0
#define TARGET_IPHONE_SIMULATOR     0

/* Mac OS with GCC-based compiler */
#if defined(__GNUC__) && (defined(__APPLE_CPP__) || defined(__APPLE_CC__) || defined(__MACOS_CLASSIC__))
    #if defined(__ppc__) 
        #ifdef __MACOS_CLASSIC__
            #define TARGET_RT_MAC_CFM   1
        #else
            #define TARGET_RT_MAC_MACHO 1
        #endif
    #elif defined(__ppc64__) 
        #define TARGET_RT_MAC_MACHO     1
    #elif defined(__i386__) 
        #define TARGET_RT_MAC_MACHO     1
    #elif defined(__x86_64__) 
        #define TARGET_RT_MAC_MACHO     1
    #elif defined(__arm__) 
        #define TARGET_RT_MAC_MACHO     1
    #else
        #error TargetConditionals.h: unknown CPU type (using GNU C compiler under Mac OS)
    #endif
#elif defined(__MWERKS__) /* Motorola/Metrowerks CodeWarrior compiler */
    #ifdef __MACH__
        #define TARGET_RT_MAC_MACHO     1
    #else
        #define TARGET_RT_MAC_CFM       1
    #endif
#else /* Unknown compiler */
    #ifdef __MACH__
        #define TARGET_RT_MAC_MACHO     1
    #else
        #define TARGET_RT_MAC_CFM       1
    #endif
#endif

#if defined(TARGET_RT_MAC_CFM) && TARGET_RT_MAC_CFM
    #define TARGET_RT_MAC_MACHO     0
#elif defined(TARGET_RT_MAC_MACHO) && TARGET_RT_MAC_MACHO
    #define TARGET_RT_MAC_CFM       0
#else
    #error TargetConditionals.h: unknown Mac OS variant
#endif

#endif /* __TARGETCONDITIONALS_DARWIN__ */
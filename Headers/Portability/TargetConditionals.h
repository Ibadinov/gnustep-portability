/*
 * Defines following macros:
 *
 * TARGET_GNUSTEP
 *
 * TARGET_CPU:
 *          TARGET_CPU_68K
 *          TARGET_CPU_ALPHA
 *          TARGET_CPU_ARM
 *          TARGET_CPU_MIPS
 *          TARGET_CPU_PPC
 *          TARGET_CPU_PPC64
 *          TARGET_CPU_SPARC
 *          TARGET_CPU_X86
 *          TARGET_CPU_X86_64
 *
 * TARGET_OS:
 *          TARGET_OS_DARWIN
 *              TARGET_OS_MAC
 *              TARGET_OS_EMBEDDED
 *              TARGET_OS_IPHONE
 *          TARGET_OS_UNIX
 *              TARGET_OS_BSD
 *              TARGET_OS_HURD
 *              TARGET_OS_LINUX
 *              TARGET_OS_SOLARIS
 *          TARGET_OS_WINDOWS
 *
 * TARGET_TR:
 *          TARGET_RT_64_BIT
 *          TARGET_RT_BIG_ENDIAN
 *          TARGET_RT_LITTLE_ENDIAN
 *          TARGET_RT_MAC_CFM
 *          TARGET_RT_MAC_MACHO
 */

#ifndef __TARGETCONDITIONALS__ /* Needs to be compatibale with Apple's counterpart */
#define __TARGETCONDITIONALS__

#define TARGET_GNUSTEP          1

#if defined(__APPLE__) || defined(__MACH__) || defined(__MACOS_CLASSIC__)
    #define TARGET_OS_DARWIN    1
#elif defined(__unix__) || defined(__unix) || defined(unix)
    #define TARGET_OS_UNIX      1
#elif defined (_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__WINDOWS__) || defined(__TOS_WIN__)
    #define TARGET_OS_WINDOWS   1
#endif

#if defined(TARGET_OS_DARWIN)
    #include <TargetConditionalsDarwin.h>
#elif defined(TARGET_OS_UNIX)
    #include <TargetConditionalsUnix.h>
#elif defined(TARGET_OS_WINDOWS)
    #include <TargetConditionalsWindows.h>
#else
    #error TargetConditionals.h: unknown operating system family
#endif

/*
 * TARGET_CPU (determined using compiler-specific macros)
 */
#if defined(__GNUC__) /* GCC-based compiler */
    #if defined(__ppc__) 
        #define TARGET_CPU_PPC          1
        #define TARGET_RT_BIG_ENDIAN    1
        #define TARGET_RT_64_BIT        0
    #elif defined(__ppc64__) 
        #define TARGET_CPU_PPC64        1
        #define TARGET_RT_BIG_ENDIAN    1
        #define TARGET_RT_64_BIT        1
    #elif defined(__i386__) 
        #define TARGET_CPU_X86          1
        #define TARGET_RT_LITTLE_ENDIAN 1
        #define TARGET_RT_64_BIT        0
    #elif defined(__x86_64__) 
        #define TARGET_CPU_X86_64       1
        #define TARGET_RT_LITTLE_ENDIAN 1
        #define TARGET_RT_64_BIT        1
    #elif defined(__arm__) 
        #define TARGET_CPU_ARM          1
        #define TARGET_RT_LITTLE_ENDIAN 1
        #define TARGET_RT_64_BIT        0
    #else
        #error TargetConditionals.h: unknown CPU type (using GNU C compiler)
    #endif
#elif defined(__MWERKS__) /* Motorola/Metrowerks CodeWarrior compiler */
    #if defined(__POWERPC__)
        #define TARGET_CPU_PPC          1
        #define TARGET_RT_BIG_ENDIAN    1
        #define TARGET_RT_64_BIT        0
    #elif defined(__INTEL__)
        #define TARGET_CPU_X86          1
        #define TARGET_RT_LITTLE_ENDIAN 1
        #define TARGET_RT_64_BIT        0
    #else
        #error TargetConditionals.h: unknown Metrowerks CPU type
    #endif
#elif defined(_MSC_VER) /* MSVC */
    #if defined(_M_IX86)
        #define TARGET_CPU_X86          1
        #define TARGET_RT_LITTLE_ENDIAN 1
        #define TARGET_RT_64_BIT        0
    #elif defined(_M_X64)
        #define TARGET_CPU_X86_64       1
        #define TARGET_RT_LITTLE_ENDIAN 1
        #define TARGET_RT_64_BIT        1
    #else
        #error TargetConditionals.h: unknown CPU type (using MSVC compiler)
    #endif
#else
    #error TargetConditionals.h: unsupported compiler
#enif

/*
 * TARGET_CPU negatives
 */
#if defined(TARGET_CPU_68K) && TARGET_CPU_68K
    #define TARGET_CPU_ALPHA    0
    #define TARGET_CPU_ARM      0
    #define TARGET_CPU_MIPS     0
    #define TARGET_CPU_PPC      0
    #define TARGET_CPU_PPC64    0
    #define TARGET_CPU_SPARC    0
    #define TARGET_CPU_X86      0
    #define TARGET_CPU_X86_64   0
#elif defined(TARGET_CPU_ALPHA) && TARGET_CPU_ALPHA
    #define TARGET_CPU_68K      0
    #define TARGET_CPU_MIPS     0
    #define TARGET_CPU_PPC      0
    #define TARGET_CPU_PPC64    0
    #define TARGET_CPU_SPARC    0
    #define TARGET_CPU_X86      0
    #define TARGET_CPU_X86_64   0
#elif defined(TARGET_CPU_ARM) && TARGET_CPU_ARM
    #define TARGET_CPU_68K      0
    #define TARGET_CPU_ALPHA    0
    #define TARGET_CPU_MIPS     0
    #define TARGET_CPU_PPC      0
    #define TARGET_CPU_PPC64    0
    #define TARGET_CPU_SPARC    0
    #define TARGET_CPU_X86      0
    #define TARGET_CPU_X86_64   0
#elif defined(TARGET_CPU_MIPS) && TARGET_CPU_MIPS
    #define TARGET_CPU_68K      0
    #define TARGET_CPU_ALPHA    0
    #define TARGET_CPU_ARM      0
    #define TARGET_CPU_MIPS     0
    #define TARGET_CPU_PPC      0
    #define TARGET_CPU_PPC64    0
    #define TARGET_CPU_SPARC    0
    #define TARGET_CPU_X86      0
    #define TARGET_CPU_X86_64   0
#elif defined(TARGET_CPU_PPC) && TARGET_CPU_PPC
    #define TARGET_CPU_68K      0
    #define TARGET_CPU_ALPHA    0
    #define TARGET_CPU_ARM      0
    #define TARGET_CPU_MIPS     0
    #define TARGET_CPU_PPC64    0
    #define TARGET_CPU_SPARC    0
    #define TARGET_CPU_X86      0
    #define TARGET_CPU_X86_64   0
#elif defined(TARGET_CPU_PPC64) && TARGET_CPU_PPC64
    #define TARGET_CPU_68K      0
    #define TARGET_CPU_ALPHA    0
    #define TARGET_CPU_ARM      0
    #define TARGET_CPU_MIPS     0
    #define TARGET_CPU_PPC      0
    #define TARGET_CPU_SPARC    0
    #define TARGET_CPU_X86      0
    #define TARGET_CPU_X86_64   0
#elif defined(TARGET_CPU_SPARC) && TARGET_CPU_SPARC
    #define TARGET_CPU_68K      0
    #define TARGET_CPU_ALPHA    0
    #define TARGET_CPU_ARM      0
    #define TARGET_CPU_MIPS     0
    #define TARGET_CPU_PPC      0
    #define TARGET_CPU_PPC64    0
    #define TARGET_CPU_X86      0
    #define TARGET_CPU_X86_64   0
#elif defined(TARGET_CPU_X86) && TARGET_CPU_X86
    #define TARGET_CPU_68K      0
    #define TARGET_CPU_ALPHA    0
    #define TARGET_CPU_ARM      0
    #define TARGET_CPU_MIPS     0
    #define TARGET_CPU_PPC      0
    #define TARGET_CPU_PPC64    0
    #define TARGET_CPU_SPARC    0
    #define TARGET_CPU_X86_64   0
#elif defined(TARGET_CPU_X86_64) && TARGET_CPU_X86_64
    #define TARGET_CPU_68K      0
    #define TARGET_CPU_ALPHA    0
    #define TARGET_CPU_ARM      0
    #define TARGET_CPU_MIPS     0
    #define TARGET_CPU_PPC      0
    #define TARGET_CPU_PPC64    0
    #define TARGET_CPU_SPARC    0
    #define TARGET_CPU_X86      0
#else
    #error TargetConditionals.h: unknown CPU
#endif

/*
 * TARGET_OS negatives
 */
#if defined(TARGET_OS_DARWIN) && TARGET_OS_DARWIN
    #define TARGET_OS_UNIX      0
    #define TARGET_OS_WINDOWS   0
#elif defined(TARGET_OS_UNIX) && TARGET_OS_UNIX
    #define TARGET_OS_MAC       0
    #define TARGET_OS_WINDOWS   0
#elif defined(TARGET_OS_WINDOWS) && TARGET_OS_WINDOWS
    #define TARGET_OS_MAC       0
    #define TARGET_OS_UNIX      0
#else
    #error TargetConditionals.h: unknown operating system
#endif

/*
 * TARGET_RT negatives
 */
#if defined(TARGET_RT_BIG_ENDIAN) && TARGET_RT_BIG_ENDIAN
    #define TARGET_RT_LITTLE_ENDIAN     0
#elif defined(TARGET_RT_LITTLE_ENDIAN) && TARGET_RT_LITTLE_ENDIAN
    #define TARGET_RT_BIG_ENDIAN        0
#else
    #error TargetConditionals.h: unknown CPU endiannes
#endif

/* We must know all details about the platform we are working on */
#if !defined(TARGET_RT_64_BIT)
    #error TargetConditionals.h: unknown CPU architecture
#endif

#endif /* __TARGETCONDITIONALS__ */
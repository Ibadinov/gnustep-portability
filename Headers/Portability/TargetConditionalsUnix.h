/*
 * Should be included on *NIX
 */

#ifndef __TARGETCONDITIONALS_UNIX__
#define __TARGETCONDITIONALS_UNIX__

#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__) || defined(_SYSTYPE_BSD)
    #define TARGET_OS_BSD       1
#if defined(__GNU__)
    #define TARGET_OS_HURD      1
#elif defined(__linux) || define(__linux) || defined(linux)
    #define TARGET_OS_LINUX     1
#elif defined(__sun) || defined(sun)
    #define TARGET_OS_SOLARIS
#else
    #error TargetConditionals.h: unknown POSIX system family
#endif

#endif /* __TARGETCONDITIONALS_UNIX__ */
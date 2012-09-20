#ifndef OS_ATOMIC_HEADER
#define OS_ATOMIC_HEADER

#import <TargetConditionals.h> /* Do not rely on this import in your software (libkern, obviously, does not perform it) */

#if TARGET_OS_MAC || (defined(TARGET_OS_DARWIN) && TARGET_OS_DARWIN)
    #import <libkern/OSAtomic.h>
#else


#import <OSTypes.h>

#define OS_ATOMIC_PROTO 0
#if OS_ATOMIC_PROTO

    /*
     * Currently, implementations should contain following:
     */

    bool OSAtomicCompareAndSwapIntBarrier(int oldValue, int newValue, volatile int *theValue);

#endif /* OS_ATOMIC_PROTO */

#if TARGET_OS_LINUX
    #include <OSAtomicLinux.h>
#endif


#endif /* TARGET_OS_DARWIN */
#endif /* OS_ATOMIC_HEADER */
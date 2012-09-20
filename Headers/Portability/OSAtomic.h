#ifndef OS_ATOMIC_HEADER
#define OS_ATOMIC_HEADER

#import <TargetConditionals.h> /* Do not rely on this import in your software (libkern, obviously, does not perform it) */

#if TARGET_OS_MAC || (defined(TARGET_OS_DARWIN) && TARGET_OS_DARWIN)
    #import <libkern/OSAtomic.h>
#else


#import <OSTypes.h>

/*
 * Currently, should contain following:
 *      typedef __OSSpinLock OSSpinLock;
 *      #define OS_SPINLOCK_INIT __SPIN_LOCK_UNLOCKED_VALUE
 *      bool OSSpinLockTry(volatile OSSpinLock *lock);
 *      void OSSpinLockLock(volatile OSSpinLock *lock);
 *      void OSSpinLockUnlock(volatile OSSpinLock *lock);
 *
 *      bool OSAtomicCompareAndSwapIntBarrier(int oldValue, int newValue, volatile int *theValue);
 */

#if TARGET_OS_LINUX
    #include <OSAtomicLinux.h>
#endif


#endif /* TARGET_OS_DARWIN */
#endif /* OS_ATOMIC_HEADER */
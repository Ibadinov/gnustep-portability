#ifndef PThreadSpinLock_h
#define PThreadSpinLock_h

#include <TargetConditionals.h>

#if defined(TARGET_OS_MAC)

    #include <libkern/OSAtomic.h>

    typedef OSSpinLock pthread_spinlock_t;

    OS_INLINE int pthread_spinlock_init(pthread_spinlock_t *lock, int mode) {
        *lock = OS_SPINLOCK_INIT;
        return 1;
    }

    OS_INLINE int pthread_spinlock_destroy(pthread_spinlock_t *lock) {
        /* noop */
        return 1;
    }

    OS_INLINE int pthread_spinlock_trylock(volatile pthread_spinlock_t *lock) {
        return OSSpinLockTry(lock);
    }

    OS_INLINE int pthread_spinlock_lock(volatile pthread_spinlock_t *lock) {
        OSSpinLockLock(lock);
        return 1;
    }

    OS_INLINE int pthread_spinlock_unlock(volatile pthread_spinlock_t *lock) {
        OSSpinLockUnlock(lock);
        return 1;
    }

    #include <pthread.h>

#else
    #include <pthread.h>
#endif /* TARGET_OS_MAC */

#endif /* PThreadSpinLock_h */
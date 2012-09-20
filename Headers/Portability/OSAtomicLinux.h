#ifndef OS_ATOMIC_LINUX_HEADER
#define OS_ATOMIC_LINUX_HEADER

#include <linux/spinlock.h>
#include <atomic_ops.h>

typedef spinlock_t OSSpinLock;
#define OS_SPINLOCK_INIT SPIN_LOCK_UNLOCKED

OS_INLINE bool OSSpinLockTry(volatile OSSpinLock *lock) {
    return (bool) spin_trylock(lock);
}

OS_INLINE void OSSpinLockLock(volatile OSSpinLock *lock) {
    spin_lock(lock);
}

OS_INLINE void OSSpinLockUnlock(volatile OSSpinLock *lock) {
    spin_unlock(lock);
}

#ifdef AO_HAVE_int_compare_and_swap_full
OS_INLINE bool OSAtomicCompareAndSwapIntBarrier(int oldValue, int newValue, volatile int *theValue) {
    return (bool) AO_int_compare_and_swap_full(theValue, oldValue, newValue);
}
#endif

#endif
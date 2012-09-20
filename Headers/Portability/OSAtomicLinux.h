#ifndef OS_ATOMIC_LINUX_HEADER
#define OS_ATOMIC_LINUX_HEADER

#include <atomic_ops.h>

#ifdef AO_HAVE_int_compare_and_swap_full
OS_INLINE bool OSAtomicCompareAndSwapIntBarrier(int oldValue, int newValue, volatile int *theValue) {
    return (bool) AO_int_compare_and_swap_full(theValue, oldValue, newValue);
}
#endif

#endif
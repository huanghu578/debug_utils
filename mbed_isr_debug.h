#ifndef ENABLE_MBED_ISR_DEBUG_H
#define ENABLE_MBED_ISR_DEBUG_H
#include "mbed.h"
extern EventQueue debug_queue;  //
extern Thread debug_thread;
#define ENABLE_MBED_ISR_DEBUG 1  // 1:on; 0:off

#if ENABLE_MBED_ISR_DEBUG
#define DEBUG_PRINT_ISR(fmt, ...)                                        \
    do {                                                                 \
        debug_queue.call(printf, "[ISR]%s-%d: " fmt, __FILE__, __LINE__, \
                         ##__VA_ARGS__);                                 \
    } while (0)
#else
	#define DEBUG_PRINT_ISR(fmt, ...)
#endif

/*
1.要使能中断输出，在main里
    #if ENABLE_MBED_ISR_DEBUG
        debug_thread.start(callback(&debug_queue,&EventQueue::dispatch_forever));
        #endif
*/

#endif  // ENABLE_MBED_ISR_DEBUG_H
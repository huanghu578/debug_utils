#include "mbed_isr_debug.h"
EventQueue debug_queue(32 * EVENTS_EVENT_SIZE);
Thread debug_thread;
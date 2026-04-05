/*
 * performance.h — High-resolution wall-clock timer
 *
 * Uses POSIX clock_gettime(CLOCK_MONOTONIC) when available,
 * falling back to clock() from <time.h>.
 *
 * Usage:
 *   Timer t;
 *   timer_start(&t);
 *   ... work ...
 *   timer_stop(&t);
 *   printf("%.4f ms\n", timer_elapsed_ms(&t));
 */
#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include <time.h>

typedef struct {
    struct timespec start;
    struct timespec end;
} Timer;

void   timer_start(Timer *t);
void   timer_stop(Timer *t);
double timer_elapsed_ms(const Timer *t);   /* milliseconds */
double timer_elapsed_sec(const Timer *t);  /* seconds      */

#endif /* PERFORMANCE_H */

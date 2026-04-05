/* performance.c */
#include "performance.h"

void timer_start(Timer *t) {
    clock_gettime(CLOCK_MONOTONIC, &t->start);
}

void timer_stop(Timer *t) {
    clock_gettime(CLOCK_MONOTONIC, &t->end);
}

double timer_elapsed_ms(const Timer *t) {
    double s  = (double)(t->end.tv_sec  - t->start.tv_sec);
    double ns = (double)(t->end.tv_nsec - t->start.tv_nsec);
    return s * 1000.0 + ns / 1e6;
}

double timer_elapsed_sec(const Timer *t) {
    return timer_elapsed_ms(t) / 1000.0;
}

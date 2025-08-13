#include "timing.h"
#include <windows.h>

void timer_init(timer_t * timer) {
    LARGE_INTEGER f;
    QueryPerformanceFrequency(&f);
    timer->frequency = f.QuadPart;
}
void timer_start(timer_t * timer) {
    LARGE_INTEGER t1;
    QueryPerformanceCounter(&t1);
    timer->t1 = t1.QuadPart;
}
void timer_end(timer_t * timer) {
    LARGE_INTEGER t2;
    QueryPerformanceCounter(&t2);
    timer->t2 = t2.QuadPart;
}
// elapsed time in ms
double timer_elapsed(timer_t *timer, time_res_t time_res) {
    float time_factor = 1;
    switch (time_res) {
    case S:
        break;
    case MS:
        time_factor = 1e3;
        break;
    case US:
        time_factor = 1e6;
        break;
    }

    return (timer->t2 - timer->t1)*time_factor/timer->frequency;
}
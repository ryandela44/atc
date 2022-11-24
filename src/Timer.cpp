#include "Timer.h"

Timer::Timer(uint64_t offset,  int period ) : offset(offset), period(period) {

}

void Timer::wait_next_activation(void) {
    /* suspend calling process until a signal is pending */
    sigwait(&sigst, &dummy);
}

int Timer::start_periodic_timer() {

    /* set timer parameters */
    timer_spec.it_value.tv_sec = offset / ONE_MILLION;
    timer_spec.it_value.tv_nsec = (offset % ONE_MILLION) * ONE_THOUSAND;
    timer_spec.it_interval.tv_sec = period / ONE_MILLION;
    timer_spec.it_interval.tv_nsec = (period % ONE_MILLION) * ONE_THOUSAND;

    sigemptyset(&sigst); // initialize a signal set
    sigaddset(&sigst, signal); // add SIGALRM to the signal set
    sigprocmask(SIG_BLOCK, &sigst, NULL); //block the signal

    /* set the signal event a timer expiration */
    memset(&sigev, 0, sizeof(struct sigevent));
    sigev.sigev_notify = SIGEV_SIGNAL;
    sigev.sigev_signo = signal;

    /* create timer */
    res = timer_create(CLOCK_MONOTONIC, &sigev, &timer);

    if (res < 0) {
        perror("Timer Create");
        exit(-1);
    }

    /* activate the timer */
    return timer_settime(timer, 0, &timer_spec, NULL);
}

void Timer::task_body(void) {
    struct timespec tv;

    if (start == 0) {
        clock_gettime(CLOCK_MONOTONIC, &tv);
        start = tv.tv_sec * ONE_THOUSAND + tv.tv_nsec / ONE_MILLION;
    }

    clock_gettime(CLOCK_MONOTONIC, &tv);
    current = tv.tv_sec * ONE_THOUSAND + tv.tv_nsec / ONE_MILLION;

    if (cycles > 0) {
//        fprintf(stderr, "Ave interval between instances: %f milliseconds\n",
//                (double) (current - start) / cycles);
    }

    cycles++;

}

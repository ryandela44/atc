/*
 * Timer.h
 *
 *  Created on: Nov. 19, 2022
 *      Author: coen320
 */
#pragma once

#include <sys/time.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define ONE_THOUSAND    1000
#define ONE_MILLION        1000000

class Timer {
private:
    int dummy;
    sigset_t sigst;
    struct itimerspec timer_spec;
    struct sigevent sigev;
    timer_t timer;
    const int signal = SIGALRM;
    int res;
    int cycles = 0;
    uint64_t start;
    uint64_t current;
    uint64_t offset;
	int period;
public:
    Timer(uint64_t offset, int period);

    void wait_next_activation(void);

    int start_periodic_timer();

    void task_body(void);


};

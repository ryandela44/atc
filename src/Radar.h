/*
 * Radar.h
 *
 *  Created on: Nov. 19, 2022
 *      Author: coen320
 */
#pragma once

#include <vector>
#include "Server.h"
#include <pthread.h>
#include <tuple>
#include "cTimer.h"
#include "Client.h"

class Radar {
	friend void * radar_start_routine(void* arg);
private:
	int rc = 0;
    std::vector<std::vector<int>> aircrafts;
    my_data_t msg;
    my_data_t rcv_data;
    int period_sec;
	int period_msec;
	Client client;
public:
    pthread_t thread_id;

    Radar(int period_sec,int period_msec);

    void init();

    void interrogate();

    std::vector<std::vector<int>> getAircrafts();

    void send_data();
};




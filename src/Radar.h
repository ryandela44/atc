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

class Radar {
	friend void * radar_start_routine(void* arg);
private:
	int rc = 0;
    Server server;
    std::vector<std::vector<int>> aircrafts;
    my_data_t msg;
public:
    pthread_t thread_id;

    Radar(Server server);

    void init();

    void interrogate();

    std::vector<std::vector<int>> getAircrafts();
};




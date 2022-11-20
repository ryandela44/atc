/*
 * Radar.h
 *
 *  Created on: Nov. 19, 2022
 *      Author: coen320
 */
#pragma once

#include <vector>
#include "DataDisplay.h"
#include "Server.h"
#include <pthread.h>

class Radar {
private:
    std::vector <Aircraft> aircrafts;
    Airspace airspace;
    DataDisplay display;
    Server server;
    pthread_t thread_id;
    std::vector<int> tmp;
public:
    Radar(std::vector <Aircraft> aircrafts, Airspace airspace, DataDisplay display, Server server);

    void *radar_start_routine(void *arg);

    void init();

    void interrogate();

    void print();
};




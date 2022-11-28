/*
 * DataDisplay.h
 *
 *  Created on: Nov. 19, 2022
 *      Author: coen320
 */

#pragma once

#include "Aircraft.h"
#include "Airspace.h"
#include "ComputerSystem.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <pthread.h>
#include "cTimer.h"

class DataDisplay {
	friend void * display_start_routine(void* arg);
private:
    int x, y;
    std::vector <std::tuple<int, int>> positions;
    ComputerSystem computer_system;
    std::vector <std::vector<int>> aircrafts;
    my_airspace airspace;
    int period_sec;
    int period_msec;
    std::vector<int> info;
public:
    pthread_t thread_id;
    DataDisplay(ComputerSystem computer_system,int period_sec,int period_msec);

    int scale(int param);

    void print();

    void init();
};

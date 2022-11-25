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

class DataDisplay {
	friend void * display_start_routine(void* arg);
private:
    int x, y;
    std::vector <std::tuple<int, int>> positions;
    ComputerSystem computer_system;
    std::vector <std::vector<int>> aircrafts;
    my_airspace airspace;
public:
    pthread_t thread_id;
    DataDisplay(ComputerSystem computer_system);

    int scale(int param);

    void print();

    void init();
};

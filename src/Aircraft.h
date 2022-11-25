/*
 * Aircraft.h
 *
 *  Created on: Nov. 19, 2022
 *      Author: coen320
 */

#pragma once

#include <pthread.h>
#include <iostream>
#include "Client.h"
#include "Server.h"
#include "Timer.h"
#include "Airspace.h"

class Aircraft : public Timer{
	friend void * aircraft_start_routine(void* arg);
private:
	uint16_t id;
    int x_coor;
    int y_coor;
    int z_coor;
    int x_speed;
    int y_speed;
    int z_speed;
    int rc;
    pthread_attr_t attr;
    Client client;
    Server server;
    my_data_t msg;
    int time = 0;
    int res = 0;
    int cycles = 0;
    uint64_t start;
    uint64_t current;
    my_airspace airspace;
public:
    pthread_t thread_id;

    Aircraft(uint16_t id, int x_coor, int y_coor, int z_coor, int x_speed, int y_speed, int z_speed, Client client,Server server);

    ~Aircraft();

    void update_position();

    void calculate_position();

    void update();

    void task_body(void);

    bool exit();
};

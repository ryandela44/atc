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
#include "cTimer.h"

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
    my_data_t rcv_data;
    int time = 0;
    int res = 0;
    int cycles = 0;
    uint64_t start;
    uint64_t current;
    my_airspace airspace;
    int period_sec;
    int period_msec;
public:
    pthread_t thread_id;

    Aircraft(uint16_t id, int x_coor, int y_coor, int z_coor, int x_speed, int y_speed, int z_speed, Client client,Server server,int period_sec,int period_msec);

    ~Aircraft();

    void update_position();

    void calculate_position();

    void update();

    void task_body(void);

    void rcv_cmd();

    bool exit();
};

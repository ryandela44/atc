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
#include "Airspace.h"
#include "cTimer.h"

class Aircraft{
	friend void * aircraft_start_routine(void* arg);
	friend void * aircraft_server_start_routine(void *arg);
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
    my_data_t msg;
    my_data_t rcv;
    int res = 0;
    my_airspace airspace;
    int period_sec;
    int period_msec;
    bool flag = true;
    Client client;
public:
    pthread_t thread_id;
    pthread_t server_thread_id;

    Aircraft(uint16_t id, int x_coor, int y_coor, int z_coor, int x_speed, int y_speed, int z_speed, int period_sec,int period_msec);

    ~Aircraft();

    void update_position();

    void calculate_position();

    void change_speed(int x_new_speed, int y_new_speed);

    void change_altitude(int z_new_coor);

    void change_position(int x_new_coor, int y_new_coor);

    void init();

    void send_to_radar();

    void rcv_cmd();

    bool exit();
};

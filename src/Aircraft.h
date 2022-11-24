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

class Aircraft {
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
public:
    pthread_t thread_id;

    Aircraft(uint16_t id, int x_coor, int y_coor, int z_coor, int x_speed, int y_speed, int z_speed, Client client,Server server);

    ~Aircraft();


    uint16_t get_id();

    int get_x_coor();

    int get_y_coor();

    int get_z_coor();

    int get_x_speed();

    int get_y_speed();

    int get_z_speed();

    void update_position();

    void calculate_position();

    void update();
};

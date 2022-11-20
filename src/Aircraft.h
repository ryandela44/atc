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

class Aircraft {
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
    pthread_t pthread;
    Client client;
    my_data_t msg;
    std::vector<int> aircraft_info;
    int time = 0;
public:
    Aircraft(uint16_t id, int x_coor, int y_coor, int z_coor, int x_speed, int y_speed, int z_speed, Client client);

    ~Aircraft();

    void * start_routine(void *arg);

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

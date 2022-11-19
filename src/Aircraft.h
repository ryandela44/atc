/*
 * Aircraft.h
 *
 *  Created on: Nov. 19, 2022
 *      Author: coen320
 */

#pragma once

#include <pthread.h>
#include <iostream>

#include "Server.h"

class Aircraft {
private:
    int id;
    int x_coor;
    int y_coor;
    int z_coor;
    int x_speed;
    int y_speed;
    int z_speed;
    int rc;
    pthread_attr_t attr;
    pthread_t pthread;
public:
    Aircraft(int id, int x_coor, int y_coor, int z_coor, int x_speed, int y_speed, int z_speed);

    ~Aircraft();

    int get_id();

    int get_x_coor();

    int get_y_coor();

    int get_z_coor();

    int get_x_speed();

    int get_y_speed();

    int get_z_speed();

    void *update_position(void *arg);

    void update();
};

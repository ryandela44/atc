/*
 * ClientServer.h
 *
 *  Created on: Nov. 19, 2022
 *      Author: coen320
 */
#pragma once
#include <string>
typedef struct _pulse msg_header_t;

typedef struct _my_data {
    msg_header_t hdr;
    int id;
    int x_coor;
    int y_coor;
    int z_coor;
    int x_speed;
    int y_speed;
    int z_speed;
    std::string cmd;
} my_data_t;

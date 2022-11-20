/*
 * ClientServer.h
 *
 *  Created on: Nov. 19, 2022
 *      Author: coen320
 */
#pragma once
#include <vector>
typedef struct _pulse msg_header_t;

typedef struct _my_data {
    msg_header_t hdr;
    std::vector<int> data;
} my_data_t;

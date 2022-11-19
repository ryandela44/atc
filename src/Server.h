/*
 * Server.h
 *
 *  Created on: Nov. 19, 2022
 *      Author: coen320
 */
#pragma once

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/dispatch.h>

typedef struct _pulse msg_header_t;

typedef struct _my_data {
    msg_header_t hdr;
    int data;
} my_data_t;


class Server {
private:
    const char *ATTACH_POINT;
    int rcvid = 0;
    my_data_t msg;
    name_attach_t *attach;
public:
    Server(const char *ATTACH_POINT);

    int init();

    int run();
};

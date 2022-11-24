/*
 * Client.h
 *
 *  Created on: Nov. 19, 2022
 *      Author: coen320
 */

#pragma once

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sys/dispatch.h>
#include "ClientServer.h"

class Client {
private:
    const char *ATTACH_POINT;
    int server_coid;
public:
    Client(const char *ATTACH_POINT);

    int send(my_data_t msg);
};

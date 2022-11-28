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
    int server_coid;
public:
    Client();

    int send(const char *ATTACH_POINT,my_data_t msg);
};

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
#include "ClientServer.h"
#include <vector>
#include <iostream>

class Server {
private:
    const char *ATTACH_POINT;
    int rcvid = 0;
    name_attach_t *attach;
public:
    Server(const char *ATTACH_POINT);

    std::vector<int> run();
};

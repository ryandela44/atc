/*
 * Client.cpp
 *
 *  Created on: Nov. 19, 2022
 *      Author: coen320
 */
#include "Client.h"

Client::Client(const char *ATTACH_POINT) : ATTACH_POINT(ATTACH_POINT) {

}

int Client::init() {
    int server_coid;
    if ((server_coid = name_open(ATTACH_POINT, 0)) == -1) {
        return EXIT_FAILURE;
    }
    return 0;
}


int Client::send(my_data_t msg) {
    MsgSend(server_coid, &msg, sizeof(msg), NULL, 0);
    return EXIT_SUCCESS;
}




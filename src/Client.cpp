/*
 * Client.cpp
 *
 *  Created on: Nov. 19, 2022
 *      Author: coen320
 */
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

class Client {
private:
    const char *ATTACH_POINT;
    int server_coid;

public:
    Client(const char *ATTACH_POINT) : ATTACH_POINT(ATTACH_POINT) {

    }

    int init() {
        int server_coid;
        if ((server_coid = name_open(ATTACH_POINT, 0)) == -1) {
            return EXIT_FAILURE;
        }
        return 0;
    }


    int send(my_data_t msg) {
        MsgSend(server_coid, &msg, sizeof(msg), NULL, 0);
        return EXIT_SUCCESS;
    }

};




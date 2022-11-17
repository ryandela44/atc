/*
 * ClientServer.cpp
 *
 *  Created on: Nov. 16, 2022
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

class ClientServer {
private:
	const char* ATTACH_POINT;
public:
ClientServer(const char * ATTACH_POINT) : ATTACH_POINT(ATTACH_POINT) {};

int server(const void * response) {
    name_attach_t *attach;
    my_data_t msg;
    int rcvid;

    if ((attach = name_attach(response, ATTACH_POINT,0)) == NULL) {
        return EXIT_FAILURE;
    }

    while (1) {
        rcvid = MsgReceive(attach->chid, &msg, sizeof(msg), NULL);

        if (rcvid == -1) {
        	break;
        }

        if (rcid == 0) {
        	switch (msg.hdr.code) {
        		case _PULSE_CODE_DISCONNECT:
        			ConnectDetach(msg.hdr.scoid);
        			break;
        		case _PULSE_CODE_UNBLOCK:
        			break;
        		default:
        			break;
        	}
        	continue;
        }

        if (msg.hdr.type == _IO_CONNECT) {
        	MsgReply(rcvid, EOK, response, 0);
        	continue;
        }

        if (msg.hdr.hype > _IO_BASE && msg.hdr.type <= _IO_MAX) {
        	MsgError(rcvid, ENOSYS);
        	continue;
        }

        MsgReply(rcvid, EOK, 0, 0);
    }

    name_detach(attach, 0);
    return EXIT_SUCCESS;
}

int client(my_data_t msg) {
	int server_coid;

	if ((server_coid = name_open(ATTACH_POINT,0)) == -1) {
	return EXIT_FAILURE;
	}

	MsgSend(server_coid, &msg, sizeof(msg), NULL, 0);
}
};




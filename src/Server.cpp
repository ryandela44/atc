/*
 * ClientServer.cpp
 *
 *  Created on: Nov. 16, 2022
 *      Author: coen320
 */
#include "Server.h"

Server::Server(const char *ATTACH_POINT) : ATTACH_POINT(ATTACH_POINT) {

}

int Server::init() {

    if ((attach = name_attach(NULL, ATTACH_POINT, 0)) == NULL) {
        return EXIT_FAILURE;
    }
    return 0;
}

int Server::run() {
    while (1) {
        my_data_t msg;
        rcvid = MsgReceive(attach->chid, &msg, sizeof(msg), NULL);

        if (rcvid == -1) {
            break;
        }

        if (rcvid == 0) {
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
            MsgReply(rcvid, EOK, NULL, 0);
            continue;
        }

        if (msg.hdr.type > _IO_BASE && msg.hdr.type <= _IO_MAX) {
            MsgError(rcvid, ENOSYS);
            continue;
        }

        MsgReply(rcvid, EOK, 0, 0);
    }

    name_detach(attach, 0);
    return EXIT_SUCCESS;
}



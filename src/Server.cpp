/*
 * ClientServer.cpp
 *
 *  Created on: Nov. 16, 2022
 *      Author: coen320
 */
#include "Server.h"

Server::Server(const char *ATTACH_POINT) : ATTACH_POINT(ATTACH_POINT) {
	  if ((attach = name_attach(NULL, ATTACH_POINT, 0)) == NULL) {
	        std::cout << "no attach point";
	    }
	  std::cout << "server attached" << std::endl;
}

my_data_t Server::run() {
    while (1) {
    	std::cout << "waiting for message" << std::endl;
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

       /* if (msg.hdr.type == 0x00) {
            if (msg.hdr.subtype == 0x01) {
                return msg;
            }
        }
*/
        MsgReply(rcvid, EOK, 0, 0);
    }

    return msg;
    name_detach(attach, 0);
    //return EXIT_SUCCESS;
}



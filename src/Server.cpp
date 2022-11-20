/*
 * ClientServer.cpp
 *
 *  Created on: Nov. 16, 2022
 *      Author: coen320
 */
#include "Server.h"

Server::Server(const char *ATTACH_POINT) : ATTACH_POINT(ATTACH_POINT) {}

std::vector<int> Server::run() {
	  if ((attach = name_attach(NULL, ATTACH_POINT, 0)) == NULL) {
			std::cout << "no attach point";
		    }

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

        if (msg.hdr.type == 0x00) {
        	      if (msg.hdr.subtype == 0x01) {
                      return msg.data;
        	      }
        	   }

        MsgReply(rcvid, EOK, 0, 0);
    }

    name_detach(attach, 0);
    //return EXIT_SUCCESS;
    return {};
}


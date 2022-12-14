/*
 * ClientServer.cpp
 *
 *  Created on: Nov. 16, 2022
 *      Author: coen320
 */
#include "Server.h"

//Server used by the processes to receive data;

Server::Server(const char *ATTACH_POINT) : ATTACH_POINT(ATTACH_POINT) {
	if ((attach = name_attach(NULL, ATTACH_POINT, 0)) == NULL) {
		//std::cout << "no attach point";
	}
}

my_data_t Server::run() {
	my_data_t msg;
	while (1) {
		// receive message from client;
		rcvid = MsgReceive(attach->chid, &msg, sizeof(msg), NULL);
		if (rcvid == -1) {
			continue;
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

		//reply to client to unblock it
		MsgReply(rcvid, EOK, 0, sizeof(msg));
		return msg;
	}
	name_detach(attach, 0);
}

// Used to receive a vector of data;
std::vector<my_data_t>  Server::run_(int n) {
	//Timer used to display vector of planes to the display every 5 seconds.
	cTimer timer(n, 0);
	while (1) {
		// receive message from client;
		rcvid = MsgReceive(attach->chid, &data, sizeof(data), NULL);

		if (data.size() != 3) {
			continue;
		}

		for (auto msg : data) {
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
		}
		//reply to client to unblock it
		MsgReply(rcvid, EOK, 0, sizeof(data));
		timer.waitTimer();
		return data;
	}
	name_detach(attach, 0);
}



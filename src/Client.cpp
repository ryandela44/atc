/*
 * Client.cpp
 *
 *  Created on: Nov. 19, 2022
 *      Author: coen320
 */
#include "Client.h"

Client::Client(const char *ATTACH_POINT) : ATTACH_POINT(ATTACH_POINT) {
	 if ((server_coid = name_open(ATTACH_POINT, 0)) == -1) {
		 std::cout << "no attach point";
	    }
}

int Client::send(my_data_t msg) {
    MsgSend(server_coid, &msg, sizeof(msg), NULL, 0);
    name_close(server_coid);
    return EXIT_SUCCESS;
}




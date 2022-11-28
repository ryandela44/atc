/*
 * Client.cpp
 *
 *  Created on: Nov. 19, 2022
 *      Author: coen320
 */
#include "Client.h"

Client::Client() {

}

int Client::send(const char *ATTACH_POINT,my_data_t msg) {
	if ((server_coid = name_open(ATTACH_POINT, 0)) == -1) {
			 std::cout << "no attach point";
	}
    MsgSend(server_coid, &msg, sizeof(msg), NULL, 0);
    name_close(server_coid);
    return EXIT_SUCCESS;
}




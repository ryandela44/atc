/*
 * CommunicationSystem.h
 *
 *  Created on: Nov. 20, 2022
 *      Author: coen320
 */

#pragma once
#include "Client.h"
#include "ClientServer.h"
#include "Server.h"
#include <pthread.h>

class CommunicationSystem {
	friend void * com_start_routine(void* arg);
private:
	int id;
	int command;
	 my_data_t msg;
	 my_data_t rcv_data;
public:
	pthread_t thread_id;
	CommunicationSystem();
	void init();
	void send();
};

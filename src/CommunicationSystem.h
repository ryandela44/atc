/*
 * CommunicationSystem.h
 *
 *  Created on: Nov. 20, 2022
 *      Author: coen320
 */

#pragma once
#include "ComputerSystem.h"
#include "Client.h"
#include "ClientServer.h"
#include <pthread.h>

class CommunicationSystem {
	friend void * com_start_routine(void* arg);
private:
	ComputerSystem computer;
	Client client;
	my_data_t msg;
	uint16_t id;
	int command;
public:
	pthread_t thread_id;
	CommunicationSystem(ComputerSystem computer, Client client);
	void init();
	void send();
};

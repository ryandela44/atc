/*
 * ComputerSystem.h
 *
 *  Created on: Nov. 20, 2022
 *      Author: coen320
 */

#pragma once
#include <pthread.h>
#include <tuple>
#include "cTimer.h"
#include "Client.h"
#include "Server.h"
#include <vector>

class ComputerSystem {
	friend void * computer_start_routine(void* arg);
public:
	pthread_t thread_id;
	ComputerSystem(int period_sec,int period_msec);
	void compute_violation();
	void init();
	std::tuple<int, int> send_command();
	void send_data();
private:
	int period_sec;
	int period_msec;
	int command = 0;
	int id = 0;
	my_data_t msg;
	my_data_t rcv_data;
	std::vector<std::vector<int>> aircrafts;
	Client display;
	Client console;
	const int x_constraint = 3000;
	const int y_constraint = 3000;
	const int z_constraint = 1000;
};

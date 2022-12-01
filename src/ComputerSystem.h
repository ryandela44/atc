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
	void compute();
	void notify(my_data_t aircraft);
	void analyze(my_data_t aircraft);
private:
	int period_sec;
	int period_msec;
	int command = 0;
	int id = 0;
	pthread_mutex_t mutex;
	bool flag_x = false;
	bool flag_y = false;
	bool flag_z = false;
	my_data_t msg;
	std::vector<my_data_t> aircrafts;
	my_data_t rcv;
	Client display;
	Client console;
	const int x_constraint = 3000;
	const int y_constraint = 3000;
	const int z_constraint = 1000;
};

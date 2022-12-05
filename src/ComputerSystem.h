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
#include <stdio.h>
#include <stdlib.h>
#include <vector>

class ComputerSystem {
	friend void * computer_start_routine(void* arg);
	friend void * computer_server_start_routine(void* arg);
public:
	pthread_t thread_id;
	pthread_t thread_server_id;
	ComputerSystem(int period_sec,int period_msec);
	void compute_violation();
	void init();
	int send();
	int send_computer();
	void compute();
	void notify(my_data_t aircraft);
	void analyze(my_data_t aircraft);
private:
	int n;
	int period_sec;
	int period_msec;
	int command = 0;
	int id = 0;
	pthread_mutex_t mutex;
	bool flag_x = false;
	bool flag_y = false;
	bool flag_z = false;
	my_data_t msg;
	my_data_t  rcv;
	std::vector <my_data_t> aircrafts;
	Client display;
	Client console;
	const int x_constraint = 3000;
	const int y_constraint = 3000;
	const int z_constraint = 1000;
};

/*
 * ComputerSystem.h
 *
 *  Created on: Nov. 20, 2022
 *      Author: coen320
 */

#pragma once
#include "Radar.h"
#include "OperatorConsole.h"
#include <pthread.h>

class ComputerSystem {
	friend void * computer_start_routine(void* arg);
public:
	pthread_t thread_id;
	ComputerSystem(Radar radar, OperatorConsole console);
	void compute_violation();
	void alert();
	std::vector <std::vector<int>> send_to_display();
	void notify_airplane(uint64_t id);
	void init();
private:
	Radar radar;
	OperatorConsole console;
	my_data_t msg;
	const int x_constraint = 3000;
	const int y_constraint = 3000;
	const int z_constraint = 1000;
};

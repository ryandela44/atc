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
#include <tuple>
#include "cTimer.h"

class ComputerSystem {
	friend void * computer_start_routine(void* arg);
public:
	pthread_t thread_id;
	ComputerSystem(Radar radar, OperatorConsole console, int period_sec,int period_msec);
	void compute_violation();
	void alert();
	std::vector <std::vector<int>> send_to_display();
	std::vector <int> more_display();
	void notify_airplane(uint64_t id);
	void init();
	std::tuple<uint16_t, int> send_command();
	int period_sec;
	int period_msec;
	int command = 0;
	uint16_t id = 0;
private:
	Radar radar;
	OperatorConsole console;
	my_data_t msg;
	const int x_constraint = 3000;
	const int y_constraint = 3000;
	const int z_constraint = 1000;
};

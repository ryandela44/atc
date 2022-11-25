/*
 * OperatorConsole.h
 *
 *  Created on: Nov. 20, 2022
 *      Author: coen320
 */

#pragma once
#include <pthread.h>
#include <vector>
#include "cTimer.h"
#include "Client.h"
#include "ClientServer.h"

class OperatorConsole {
	friend void * aircraft_start_routine(void* arg);
private:
	 int period_sec;
	 int period_msec;
	 my_data_t msg;
	 Client client;
public:
	OperatorConsole(int period_sec, int period_msec);
	void init();
	void send(uint16_t id, int x_coor, int y_coor, int z_coor, int x_speed, int y_speed, int z_speed);
	std::vector<int> request();
};

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
#include "Logger.h"
#include "Server.h"

class OperatorConsole {
	friend void * aircraft_start_routine(void* arg);
	friend void * input_console_start_routine(void* arg);
	friend void * rcv_console_start_routine(void* arg);
private:
	 int period_sec;
	 int period_msec;
	 my_data_t rcv_data;
	 bool flag_add = false;
public:
	pthread_t thread_id;
	pthread_t thread_rcv_console_id;
	pthread_t thread_input_console_id;
	OperatorConsole(int period_sec, int period_msec);
	void init();
	void send();
	void rcv();
	void input();
};

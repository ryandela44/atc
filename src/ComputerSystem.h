/*
 * ComputerSystem.h
 *
 *  Created on: Nov. 20, 2022
 *      Author: coen320
 */

#pragma once
#include "Radar.h"
#include "OperatorConsole.h"
#include "Server.h"
#include "Client.h"

class ComputerSystem {
public:
	ComputerSystem(Radar radar, OperatorConsole console, Client client, Server server);
	void compute_violation();
	void alert();
	void send_to_display();
	void notify_airplane(uint64_t id);
private:
	Radar radar;
	OperatorConsole console;
	Client client;
	Server server;
	my_data_t msg;
	const int x_constraint = 3000;
	const int y_constraint = 3000;
	const int z_constraint = 1000;
};

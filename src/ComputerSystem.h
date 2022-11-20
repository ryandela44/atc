/*
 * ComputerSystem.h
 *
 *  Created on: Nov. 20, 2022
 *      Author: coen320
 */

#pragma once
#include "Radar.h"
#include "OperatorConsole.h"

class ComputerSystem {
public:
	ComputerSystem(Radar radar, OperatorConsole console);
	void compute_violation();
	void alert();
	void send_to_display();
private:
	Radar radar;
	OperatorConsole console;
};

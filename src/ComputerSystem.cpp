#include "ComputerSystem.h"
ComputerSystem::ComputerSystem(int period_sec,int period_msec) : period_sec( period_sec), period_msec(period_msec) {
	init();
}

void * computer_start_routine(void *arg) {
	ComputerSystem& computer = *(ComputerSystem*) arg;
	computer.compute();
	return NULL;
}

void ComputerSystem::compute() {
	Server server("computer");
	//cTimer timer(period_sec, period_msec);
	//Client client;

	while (1) {
		rcv= server.run();
		//std::cout<< "id : " << rcv.id << std::endl;
		if (rcv.hdr.type == 0x01) {
			rcv.hdr.type = 0x02;
			aircrafts.push_back(rcv);
		}

		if (rcv.hdr.type == 0x04) {
			std::cout << "computer received data :  " << rcv.cmd << std::endl;
			analyze(rcv);
		}
		//std::cout<< "size : " << aircrafts.size() << std::endl;
		if (aircrafts.size() == 3) {
			send();
			aircrafts.clear();
		}
		compute_violation();
		//timer.waitTimer();
		//aircrafts.clear();
	}
}

void ComputerSystem::compute_violation() {
	/*	if(!aircrafts.empty() || aircrafts.size() < 2) {
		for(int i = 0; i < this->aircrafts.size(); i++) {
			for (int j = 1; j < this->aircrafts.size(); i++) {
				if ((aircrafts[i][1] - aircrafts[j][1] <= x_constraint) || (aircrafts[i][1] + (180 * aircrafts[i][4]) == aircrafts[j][1] + (180 * aircrafts[j][4]) )) {
					if (aircrafts[i][0] != aircrafts[j][0]) {
						flag_x = true;
						//notify(aircrafts[i]);
					}
				}

				if ((aircrafts[i][2] - aircrafts[j][2] <= y_constraint) || (aircrafts[i][2] + (180 * aircrafts[i][5]) == aircrafts[j][2] + (180 * aircrafts[j][5]) )) {
					if (aircrafts[i][0] != aircrafts[j][0]) {
						flag_y = true;
						//notify(aircrafts[i]);
					}
				}

				if ((aircrafts[i][3] - aircrafts[j][3] <= z_constraint) || (aircrafts[i][3] + (180 * aircrafts[i][6]) == aircrafts[j][3] + (180 *aircrafts[j][6]) )) {
					if (aircrafts[i][0] != aircrafts[j][0]) {
						flag_z = true;
						//notify(aircrafts[i]);
					}
				}
			}
		}
	}*/
}

void ComputerSystem::init() {
	pthread_create(&thread_id, NULL, computer_start_routine , (void *) this);
}

int ComputerSystem::send() {
	int server_coid = 0;
	if ((server_coid = name_open("display", 0)) == -1) {

	}

	MsgSend(server_coid, &aircrafts, sizeof(aircrafts), NULL, 0);
	name_close(server_coid);
	return EXIT_SUCCESS;
}

void ComputerSystem::notify(my_data_t aircraft) {
	aircraft.hdr.type = 0x02;
	console.send("operator",aircraft);
}

void ComputerSystem::analyze(my_data_t aircraft) {
	Client client;
	aircraft.hdr.type = 0x02;
	std::string in = aircraft.cmd;
	if (in == "speed") {
		if (flag_x) {
			aircraft.x_speed = (aircraft.x_speed)/2;
		}
		if (flag_y) {
			aircraft.y_speed = (aircraft.y_speed)/2;
		}
		if (flag_z) {
			aircraft.z_speed = (aircraft.z_speed)/2;
		}
		std::cout << "sending to com" << std::endl;
		client.send("com", aircraft);
	}
	if ( in == "altitude") {
		aircraft.cmd = "altitude";
	}
	if (in == "position") {
		aircraft.cmd = "position";
	}
	if (in == "display") {
		aircraft.hdr.subtype = 0x01;
		aircraft.cmd = "display";
		client.send("display", aircraft);
	}
}

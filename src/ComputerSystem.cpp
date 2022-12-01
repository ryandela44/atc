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
	//cTimer timer(period_sec, period_msec);
	Server server("computer");
	while (1) {
		rcv = server.run();
		if (rcv.hdr.type == 0x01) {
			//std::cout << "computer :  " << rcv.id << std::endl;
			rcv.hdr.type = 0x02;
			display.send("display", rcv);
		}
		if (rcv.hdr.type == 0x04) {
			analyze(rcv);
		}
		compute_violation();
		//timer.waitTimer();
	}

}

void ComputerSystem::compute_violation() {
	if(!aircrafts.empty() || aircrafts.size() < 2) {
		for(int i = 0; i < this->aircrafts.size(); i++) {
			for (int j = 1; j < this->aircrafts.size(); i++) {
				if ((aircrafts[i].x_coor - aircrafts[j].x_coor <= x_constraint) || (aircrafts[i].x_coor + (180 * aircrafts[i].x_speed) == aircrafts[j].x_coor + (180*aircrafts[j].x_speed) )) {
					if (aircrafts[i].id != aircrafts[j].id) {
						flag_x = true;
						notify(aircrafts[i]);
					}
				}

				if ((aircrafts[i].y_coor - aircrafts[j].y_coor <= y_constraint) || (aircrafts[i].y_coor + (180 * aircrafts[i].y_speed) == aircrafts[j].y_coor + (180*aircrafts[j].y_speed) )) {
					if (aircrafts[i].id != aircrafts[j].id) {
						flag_y = true;
						notify(aircrafts[i]);
					}
				}

				if ((aircrafts[i].z_coor - aircrafts[j].z_coor <= z_constraint) || (aircrafts[i].z_coor + (180 * aircrafts[i].z_speed) == aircrafts[j].z_coor + (180*aircrafts[j].z_speed) )) {
					if (aircrafts[i].id != aircrafts[j].id) {
						flag_z = true;
						notify(aircrafts[i]);
					}
				}
			}
		}
	}
}

void ComputerSystem::init() {
	pthread_create(&thread_id, NULL, computer_start_routine , (void *) this);
}

void ComputerSystem::notify(my_data_t aircraft) {
	aircraft.hdr.type = 0x02;
	console.send("operator",aircraft);
}

void ComputerSystem::analyze(my_data_t aircraft) {
	Client client;
	for (int i = 0; i < aircrafts.size(); i ++) {
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
}

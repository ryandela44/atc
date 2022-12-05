#include "ComputerSystem.h"
ComputerSystem::ComputerSystem(int period_sec,int period_msec) : period_sec( period_sec), period_msec(period_msec) {
	init();
}

void * computer_start_routine(void *arg) {
	ComputerSystem& computer = *(ComputerSystem*) arg;
	computer.compute();
	return NULL;
}

void * computer_server_start_routine(void* arg) {
	ComputerSystem& computer = *(ComputerSystem*) arg;
	computer.compute_violation();
	return NULL;
}

void ComputerSystem::compute() {
	Server server("computer");
	while (1) {
		rcv= server.run();
		if (rcv.hdr.type == 0x01) {
			rcv.hdr.type = 0x02;
			aircrafts.push_back(rcv);
		}

		if (rcv.hdr.type == 0x04) {
			//std::cout << "computer received data :  " << rcv.cmd << std::endl;
			analyze(rcv);
		}
		//std::cout<< "size : " << aircrafts.size() << std::endl;
		if (aircrafts.size() == 3) {
			send_computer();
			send();
			aircrafts.clear();
		}
	}
}

void ComputerSystem::compute_violation() {
	Server server1 ("violation");
	std::vector<my_data_t> rcver;
	while (1) {
		n = 1 + (rand() % 10);
		rcver = server1.run_(n);

		if(!rcver.empty() || rcver.size() < 2) {
			for(int i = 0; i < rcver.size(); i++) {
				for (int j = 0; j < rcver.size(); j++) {
					if (rcver[i].id != rcver[j].id) {
						if ((rcver[i].x_coor - rcver[j].x_coor <= x_constraint) || (rcver[i].x_coor + (180 * aircrafts[i].x_speed) == rcver[j].x_coor + (180 * aircrafts[j].x_speed) )) {
							flag_x = true;
							notify(rcver[i]);
						}

						if ((rcver[i].y_coor - rcver[j].y_coor <= y_constraint) || (rcver[i].y_coor + (180 * rcver[i].y_speed) == rcver[j].y_coor + (180 * rcver[j].y_speed) )) {
							flag_y = true;
							notify(rcver[i]);
						}
						if ((rcver[i].z_coor - rcver[j].z_coor <= z_constraint) || (rcver[i].z_coor + (180 * rcver[i].z_speed) == rcver[j].z_coor + (180 * rcver[j].z_speed) )) {
							flag_z = true;
							notify(rcver[i]);
						}
					}
				}
			}
		}
	}
}

void ComputerSystem::init() {
	pthread_create(&thread_id, NULL, computer_start_routine , (void *) this);
	pthread_create(&thread_server_id, NULL, computer_server_start_routine , (void *) this);
}

int ComputerSystem::send() {
	int server_coid = 0;
	if ((server_coid = name_open("display", 0)) == -1) {

	}

	MsgSend(server_coid, &aircrafts, sizeof(aircrafts), NULL, 0);
	name_close(server_coid);
	return EXIT_SUCCESS;
}

int ComputerSystem::send_computer() {
	int server_coid = 0;
	if ((server_coid = name_open("violation", 0)) == -1) {

	}

	MsgSend(server_coid, &aircrafts, sizeof(aircrafts), NULL, 0);
	name_close(server_coid);
	return EXIT_SUCCESS;
}

void ComputerSystem::notify(my_data_t aircraft) {
	aircraft.hdr.type = 0x02;
	std::cout << "violation from aircraft " << aircraft.id << std::endl;
	console.send("console", aircraft);
}

void ComputerSystem::analyze(my_data_t aircraft) {
	Client client;
	aircraft.hdr.type = 0x02;
	std::string in = aircraft.cmd;
	if (in == "speed") {
		if (flag_x) {
			aircraft.x_speed = -300 + (rand() % 300);
			flag_x = false;
		}
		if (flag_y) {
			aircraft.y_speed = -300 + (rand() % 300);
			flag_y = false;
		}
		if (flag_z) {
			aircraft.z_speed = -300 + (rand() % 300);
			flag_z = false;
		}
		std::cout << "sending to com" << std::endl;
		client.send("com", aircraft);
	}
	if ( in == "altitude") {
		aircraft.cmd = "altitude";
		client.send("com", aircraft);
	}
	if (in == "position") {
		aircraft.cmd = "position";
		client.send("com", aircraft);
	}
	if (in == "display") {
		aircraft.hdr.subtype = 0x01;
		aircraft.cmd = "display";
		client.send("display", aircraft);
	}
}

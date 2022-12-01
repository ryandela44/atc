#include "DataDisplay.h"

DataDisplay::DataDisplay( int period_sec, int period_msec) : period_sec(period_sec),period_msec(period_msec) {
	init();
}

void * display_start_routine(void *arg) {
	DataDisplay& display = *(DataDisplay*) arg;
	display.print();
	return NULL;
}

int DataDisplay::scale(int param) {
	return param / 100;
}

void DataDisplay::print() {
	Server server("display");
	std::vector<int> check;
	cTimer timer(5,0);
	while (1) {
		//std::cout<< "on top" << std::endl;
		rcv = server.run();
		//std::cout<< "data : " << rcv.id << std::endl;
		if (rcv.hdr.type == 0x02) {
			aircrafts.push_back(rcv);
			print_aircrafts();
			timer.waitTimer();
			positions.clear();
			aircrafts.clear();
		}

	}
}

void DataDisplay::print_aircrafts() {
	x = scale(airspace.x_space);
	y = scale(airspace.y_space);

	pthread_mutex_lock(&mutex);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if ((i == 0 && j != y - 1) || (i == x - 1 && j != y - 1) || j == 0) {
				std::cout << "*";
			} else if (j == y - 1) {
				std::cout << "*" << std::endl;
			} else if (aircrafts.empty()) {
				std::cout << " ";
			} else {
				for (auto aircraft : aircrafts) {
					if (i == (100 - scale(aircraft.x_coor)) && j == scale(aircraft.y_coor)) {
						std::cout << std::to_string(rcv.id);
						positions.push_back(std::make_tuple(i, j));
					} else {
						auto res = std::find(positions.begin(), positions.end(), std::make_tuple(i, j));
						if (res == positions.end()) {
							std::cout << " ";
						}
					}
				}
			}
		}
	}
	pthread_mutex_unlock(&mutex);

}

void DataDisplay::init() {
	pthread_create(&thread_id, NULL, display_start_routine , (void *) this);
}



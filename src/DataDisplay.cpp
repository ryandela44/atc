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
	Logger logger("log");
	while (1) {
		rcv = server.run_();
		print_aircrafts(logger);
	}
}

void DataDisplay::print_aircrafts(Logger logger) {
	x = scale(airspace.x_space);
	y = scale(airspace.y_space);
	pthread_mutex_lock(&mutex);
	for (auto data : rcv) {
		std::cout<< "id : " << data.id << std::endl;
		std::cout<< "x_coor : " << data.x_coor << std::endl;
		std::cout<< "y_coor : " << data.y_coor << std::endl;
		std::cout<< "z_coor : " << data.z_coor << std::endl;
		std::cout<< "x_speed : " << data.x_speed << std::endl;
		std::cout<< "y_speed : " << data.y_speed << std::endl;
		std::cout<< "z_speed : " << data.z_speed << std::endl;
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if ((i == 0 && j != y - 1) || (i == x - 1 && j != y - 1) || j == 0) {
				std::cout << " * ";
				logger.log(" * ","");
			} else if (j == y - 1) {
				std::cout << " * " << std::endl;
				logger.log( " * ","r");
			} else if (rcv.empty()) {
				std::cout << " ";
				logger.log(" ","");
			} else {
				for (auto aircraft : rcv) {
					if (i == (100 - scale(aircraft.x_coor)) && j == scale(aircraft.y_coor)) {
						std::cout << std::to_string(aircraft.id);
						logger.log(std::to_string(aircraft.id),"");
						positions.push_back(std::make_tuple(i, j));
					} else {
						auto res = std::find(positions.begin(), positions.end(), std::make_tuple(i, j));
						if (res == positions.end()) {
							std::cout << " ";
							logger.log(" ","");
						}
					}
				}
			}
		}
	}
	positions.clear();
	pthread_mutex_unlock(&mutex);

}

void DataDisplay::init() {
	pthread_create(&thread_id, NULL, display_start_routine , (void *) this);
}



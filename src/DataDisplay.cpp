#include "DataDisplay.h"

DataDisplay::DataDisplay(ComputerSystem computer_system, int period_sec, int period_msec) : computer_system(computer_system), period_sec(period_sec),period_msec(period_msec) {
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
	cTimer timer(period_sec,period_msec);
	while (1) {
	aircrafts = computer_system.send_to_display();
	info = computer_system.more_display();
    x = scale(airspace.x_space);
    y = scale(airspace.y_space);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if ((i == 0 && j != y - 1) || (i == x - 1 && j != y - 1) || j == 0) {
                std::cout << "*";
            } else if (j == y - 1) {
                std::cout << "*" << std::endl;
            } else if (aircrafts.empty()) {
                std::cout << " ";
            } else {
                for (auto aircraft: aircrafts) {
                    if (i == (100 - scale(aircraft[1])) && j == scale(aircraft[2])) {
                        std::cout << std::to_string(aircraft[0]);
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

    for (int i = 0; i < aircrafts.size(); i++) {
    	for (int j =0; j < info.size(); j++) {
    		int x_coor = aircrafts[i][1];
    		int y_coor = aircrafts[i][2];
    		int z_coor = aircrafts[i][3];
    		int x_speed = aircrafts[i][4];
    		int y_speed = aircrafts[i][5];
    		int z_speed	= aircrafts[i][6];
    		if (aircrafts[i][0] == info[0]) {
    			std::cout << x_coor << y_coor << z_coor << x_speed << y_speed << z_speed << std::endl;
    		}
    	}
    }
    timer.waitTimer();
	}
}

void DataDisplay::init() {
	pthread_create(&thread_id, NULL, display_start_routine , (void *) this);
}



#include "DataDisplay.h"

DataDisplay::DataDisplay(ComputerSystem computer_system) : computer_system(computer_system) {
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
	aircrafts = computer_system.send_to_display();
    x = scale(airspace.x_space);
    y = scale(airspace.y_space);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if ((i == 0 && j != y - 1) || (i == x - 1 && j != y - 1) || j == 0) {
                std::cout << " * ";
            } else if (j == y - 1) {
                std::cout << " * " << std::endl;
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
}

void DataDisplay::init() {
	pthread_create(&thread_id, NULL, display_start_routine , (void *) this);
}



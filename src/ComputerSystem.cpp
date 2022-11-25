#include "ComputerSystem.h"

ComputerSystem::ComputerSystem(Radar radar, OperatorConsole console) : radar(radar), console(console){
init();
}

void * computer_start_routine(void *arg) {
	ComputerSystem& computer = *(ComputerSystem*) arg;
	computer.compute_violation();
	return NULL;
}

void ComputerSystem::compute_violation() {
	send_to_display();
/*    auto aircrafts = radar.getAircrafts();
for(int i = 0; i < aircrafts.size(); i++) {
    for (int j = 0; j < aircrafts.size(); i++) {
        if (aircrafts[i] - aircrafts[j] <= x_constraint) {
            if (aircrafts[i].get_id() != aircrafts[j].get_id()) {
                notify_airplane(aircraft[i].get_id());
            }
        }

        if (aircrafts[i] - aircrafts[j] <= y_constraint) {
            if (aircrafts[i].get_id() != aircrafts[j].get_id()) {
                notify_airplane(aircraft[i].get_id());
            }
        }

        if (aircrafts[i] - aircrafts[j] <= z_constraint) {
            if (aircrafts[i].get_id() != aircrafts[j].get_id()) {
                notify_airplane(aircraft[i].get_id());
            }
        }
    }
}*/
}

void ComputerSystem::alert() {

}

std::vector <std::vector<int>> ComputerSystem::send_to_display() {
return radar.getAircrafts();
}

void ComputerSystem::notify_airplane(uint64_t id) {
}

void ComputerSystem::init() {
	pthread_create(&thread_id, NULL, computer_start_routine , (void *) this);
}


#include "ComputerSystem.h"

ComputerSystem::ComputerSystem(Radar radar, OperatorConsole console) : radar(radar), console(console){

}

void ComputerSystem::compute_violation() {
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

void ComputerSystem::send_to_display() {

}

void ComputerSystem::notify_airplane(uint64_t id) {
}

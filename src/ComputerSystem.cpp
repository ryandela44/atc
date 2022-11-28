#include "ComputerSystem.h"

ComputerSystem::ComputerSystem(int period_sec,int period_msec) : period_sec( period_sec), period_msec(period_msec) {
init();
}

void * computer_start_routine(void *arg) {
	ComputerSystem& computer = *(ComputerSystem*) arg;
	computer.compute_violation();
	return NULL;
}

void ComputerSystem::compute_violation() {
	cTimer timer(period_sec,period_msec);
	Server server("computer");
	while (1) {
		rcv_data = server.run();
		aircrafts.clear();
		if (rcv_data.hdr.type == 0x01) {
			aircrafts.push_back({rcv_data.id,rcv_data.x_coor,rcv_data.y_coor,rcv_data.z_coor,rcv_data.x_speed,rcv_data.y_speed,rcv_data.z_speed});
		}
			send_data();
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
	timer.waitTimer();
	}
}
void ComputerSystem::send_data() {
	for (auto aircraft : aircrafts) {
		msg.hdr.type = 0x02;
		msg.id = aircraft[0];
		msg.x_coor = aircraft[1];
		msg.y_coor = aircraft[2];
		msg.z_coor = aircraft[3];
		msg.x_speed = aircraft[4];
		msg.y_speed = aircraft[5];
		msg.z_speed = aircraft[6];
		display.send("display",msg);
	}
}

void ComputerSystem::init() {
	pthread_create(&thread_id, NULL, computer_start_routine , (void *) this);
}

std::tuple<int, int> ComputerSystem::send_command() {
	return std::make_tuple(id, command);
}

#include "Radar.h"

Radar::Radar(int period_sec,int period_msec) : period_sec(period_sec), period_msec(period_msec)  {
	init();
}

void * radar_start_routine(void *arg) {
    Radar &radar = *(Radar *) arg;
    radar.interrogate();
    return NULL;
}

void Radar::interrogate() {
	cTimer timer(period_sec,period_msec);
	Server server("radar");
	while (1) {
	msg = server.run();
	aircrafts.clear();
	if (msg.hdr.type == 0x00) {
	aircrafts.push_back({msg.id,msg.x_coor,msg.y_coor,msg.z_coor,msg.x_speed,msg.y_speed,msg.z_speed});
	std::cout << std::to_string(msg.id) << std::endl;
	}
	std::cout << "went through" << std::endl;
	timer.waitTimer();
	}
}

void Radar::init() {

	rc = pthread_create(&thread_id, NULL, radar_start_routine , (void *) this);
}

std::vector<std::vector<int>> Radar::getAircrafts() {
	return aircrafts;
}

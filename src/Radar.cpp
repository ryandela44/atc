#include "Radar.h"

Radar::Radar(Server server) : server(server) {
	init();
}

void * radar_start_routine(void *arg) {
    Radar &radar = *(Radar *) arg;
    radar.interrogate();
    return NULL;
}

void Radar::interrogate() {
	msg = server.run();
	aircrafts.clear();
	if (msg.hdr.type == 0x00) {
	aircrafts.push_back({msg.id,msg.x_coor,msg.y_coor,msg.z_coor,msg.x_speed,msg.y_speed,msg.z_speed});
	}
}

void Radar::init() {

	rc = pthread_create(&thread_id, NULL, radar_start_routine , (void *) this);
}

std::vector<std::vector<int>> Radar::getAircrafts() {
	return aircrafts;
}

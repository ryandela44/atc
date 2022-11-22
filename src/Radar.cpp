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
//	uint64_t id = 0;
//	int x_coor= 0;
//	int y_coor= 0;
//	int z_coor= 0;;
//	int x_speed = 0;
//	int y_speed= 0;
//	int z_speed = 0;
	msg = server.run();
	std::cout << msg.id << std::endl;
	std::cout << msg.x_coor << std::endl;
	std::cout << msg.y_coor << std::endl;
	std::cout << msg.z_coor << std::endl;
	std::cout << msg.x_speed << std::endl;
	std::cout << msg.y_speed << std::endl;
	std::cout << msg.z_speed << std::endl;
}

void Radar::init() {

	rc = pthread_create(&thread_id, NULL, radar_start_routine , (void *) this);
}

std::vector<Aircraft> Radar::getAircrafts() {
	return aircrafts;
}

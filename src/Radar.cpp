#include "Radar.h"

Radar::Radar(Server server) : server(server) {
}

void Radar::init() {
    //pthread_create(&thread_id, NULL,radar_start_routine,(void *) this);
}

void *Radar::radar_start_routine(void *arg) {
    Radar &radar = *(Radar *) arg;
    interrogate();
    return NULL;
}

void Radar::interrogate() {
    //pthread_mutex_lock(&mutex);
}

std::vector<Aircraft> Radar::getAircrafts() {
	return aircrafts;
}

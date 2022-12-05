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
	// Received signals from aircrafts in the airspace.
	Server server("radar");
	while (1) {
		msg = server.run();
		msg.hdr.type = 0x01;
		client.send("computer", msg);
	}
}

void Radar::init() {

	rc = pthread_create(&thread_id, NULL, radar_start_routine , (void *) this);
}

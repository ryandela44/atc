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
	//cTimer timer(period_sec, period_msec);
	Server server("radar");
	//std::vector<my_data_t> msg_v;
	while (1) {
		msg = server.run();
		msg.hdr.type = 0x01;
		//std::cout << "counter " << msg.id << std::endl;
		client.send("computer", msg);
		//timer.waitTimer();
	}
}

void Radar::init() {

	rc = pthread_create(&thread_id, NULL, radar_start_routine , (void *) this);
}

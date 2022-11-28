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
	rcv_data = server.run();
	aircrafts.clear();
	if (rcv_data.hdr.type == 0x00) {
	aircrafts.push_back({rcv_data.id,rcv_data.x_coor,rcv_data.y_coor,rcv_data.z_coor,rcv_data.x_speed,rcv_data.y_speed,rcv_data.z_speed});
	}
	send_data();
	timer.waitTimer();
	}
}

void Radar::init() {

	rc = pthread_create(&thread_id, NULL, radar_start_routine , (void *) this);
}

std::vector<std::vector<int>> Radar::getAircrafts() {
	return aircrafts;
}

void Radar::send_data() {
	for (auto aircraft : aircrafts) {
		msg.hdr.type = 0x01;
		msg.id = aircraft[0];
		msg.x_coor = aircraft[1];
		msg.y_coor = aircraft[2];
		msg.z_coor = aircraft[3];
		msg.x_speed = aircraft[4];
		msg.y_speed = aircraft[5];
		msg.z_speed = aircraft[6];
		client.send("computer",msg);
	}
}

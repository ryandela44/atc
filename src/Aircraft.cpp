/*
 * Aircraft.c++
 *
 *  Created on: Oct. 25, 2022
 *      Author: coen320
 */
#include "Aircraft.h"

Aircraft::Aircraft(uint16_t id, int x_coor, int y_coor, int z_coor, int x_speed, int y_speed, int z_speed, int period_sec,int period_msec)
: id(id), x_coor(x_coor),
  y_coor(y_coor), z_coor(z_coor), x_speed(x_speed), y_speed(y_speed), z_speed(z_speed), period_sec(period_sec), period_msec(period_msec){
	init();
}

Aircraft::~Aircraft() {
	thread_id = NULL;
}

void * aircraft_start_routine(void *arg) {
	Aircraft& aircraft = *(Aircraft*) arg;
	aircraft.update_position();
	return NULL;
}

void * aircraft_server_start_routine(void *arg) {
	Aircraft& aircraft = *(Aircraft*) arg;
	aircraft.rcv_cmd();
	return NULL;
}

void Aircraft::update_position() {
	cTimer timer(period_sec, period_msec);
	while (flag) {
		calculate_position();
		send_to_radar();
		timer.waitTimer();
	}
}

void Aircraft::calculate_position() {
	x_coor =  x_coor + ((period_sec + ( period_msec/1000)) * x_speed);
	y_coor =  y_coor + ((period_sec + ( period_msec/1000)) * y_speed);
}

void Aircraft::change_speed(int x_new_speed, int y_new_speed) {
	x_speed = x_speed + (x_new_speed - x_speed);
	y_speed = y_speed + (y_new_speed - y_speed);
}

void Aircraft::change_position(int x_new_coor, int y_new_coor) {
	int x_coor = x_speed * (period_sec + ( period_msec/1000)) + (x_new_coor - x_coor);
	int y_coor = y_speed * (period_sec + ( period_msec/1000)) + (y_new_coor - y_coor);
}

void Aircraft::change_altitude(int z_new_coor) {
	int z_coor = z_speed * (period_sec + ( period_msec/1000)) + (z_new_coor - z_coor);
}

void Aircraft::init() {
	pthread_create(&thread_id, NULL, aircraft_start_routine , (void *) this);
	pthread_create(&server_thread_id, NULL,  aircraft_server_start_routine , (void *) this);
}

void Aircraft::rcv_cmd() {
	Server server(std::to_string(id).c_str());
	while (1) {
		std::cout << "someone : " << msg.id << std::endl;
		rcv = server.run();
		if (rcv.hdr.type == 0x05) {
			if (rcv.cmd == "speed") {
				change_speed(rcv.x_speed,rcv.y_speed);
				std::cout << "changing speed : " << msg.id << std::endl;
			}

			if (rcv.cmd == "altitude") {
				change_altitude(rcv.z_coor);
				std::cout << "changing altitude " << msg.id << std::endl;
			}

			if (rcv.cmd == "position") {
				change_position(rcv.x_coor,rcv.y_coor);
				std::cout << "changing position " << msg.id << std::endl;
			}
		}
	}
}

void Aircraft::send_to_radar() {
	msg.hdr.type = 0x00;
	msg.id = id;
	msg.x_coor = x_coor;
	msg.y_coor = y_coor;
	msg.z_coor = z_coor;
	msg.x_speed = x_speed;
	msg.y_speed = y_speed;
	msg.z_speed = z_speed;
	client.send("radar", msg);
	if ((airspace.x_space < x_coor) || (airspace.y_space < y_coor) || (airspace.z_space < z_coor)) {
		flag = false;
	}
}

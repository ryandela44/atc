/*
 * Aircraft.c++
 *
 *  Created on: Oct. 25, 2022
 *      Author: coen320
 */
#include "Aircraft.h"

Aircraft::Aircraft(uint16_t id, int x_coor, int y_coor, int z_coor, int x_speed, int y_speed, int z_speed, Client client, Timer timer)
        : id(id), x_coor(x_coor),
          y_coor(y_coor), z_coor(z_coor), x_speed(x_speed), y_speed(y_speed), z_speed(z_speed), client(client), timer(timer) {

	client.init();
	msg.hdr.type = 0x00;
	msg.hdr.subtype = id;
//    rc = pthread_attr_init(&attr);
//    if (!rc) {
//    }
//    pthread_attr_setschedpolicy(&attr, SCHED_RR);
}

Aircraft::~Aircraft() {
//    pthread_attr_destroy(&attr);
//    pthread_exit(NULL);
}

void* Aircraft::start_routine(void *arg) {
	res = timer.start_periodic_timer();
		if (res < 0) {
			perror("Start periodic timer");
		}

	Aircraft& aircraft = *(Aircraft*) arg;
	while (1) {
	timer.wait_next_activation();
	update_position();
	}
	return NULL;
}

uint16_t Aircraft::get_id() {
	msg.hdr.subtype = id;
    return id;
}

int Aircraft::get_x_coor() {
    return x_coor;
}

int Aircraft::get_y_coor() {
    return y_coor;
}

int Aircraft::get_z_coor() {
    return z_coor;
}

int Aircraft::get_x_speed() {
    return x_speed;
}

int Aircraft::get_y_speed() {
    return y_speed;
}

int Aircraft::get_z_speed() {
    return z_speed;
}

void Aircraft::update_position() {
	calculate_position();
	aircraft_info.push_back(id);
	aircraft_info.push_back(x_coor);
	aircraft_info.push_back(y_coor);
	aircraft_info.push_back(z_coor);
	aircraft_info.push_back(x_speed);
	aircraft_info.push_back(y_speed);
	aircraft_info.push_back(z_speed);
	msg.data = aircraft_info;
	client.send(msg);
	aircraft_info.clear();
}

void Aircraft::calculate_position() {
	this->x_coor = x_coor + (time * x_speed);
	this->y_coor = y_coor + (time * y_speed);
	this->z_coor = z_coor + (time *	z_speed);
}

void Aircraft::update() {
    //rc = pthread_create(&pthread, &attr, update_position , std::to_string(id));
//    if (!rc) {
//
//    }
//    pthread_join(pthread, NULL);
}

/*
 * Aircraft.c++
 *
 *  Created on: Oct. 25, 2022
 *      Author: coen320
 */
#include "Aircraft.h"

Aircraft::Aircraft(uint16_t id, int x_coor, int y_coor, int z_coor, int x_speed, int y_speed, int z_speed, Client client,Server server, Timer timer)
        : id(id), x_coor(x_coor),
          y_coor(y_coor), z_coor(z_coor), x_speed(x_speed), y_speed(y_speed), z_speed(z_speed), client(client), server(server), timer(timer) {

	msg.hdr.type = 0x00;
	msg.hdr.subtype = id;
	msg.id = id;
	update();
}

Aircraft::~Aircraft() {
//    pthread_attr_destroy(&attr);
//    pthread_exit(NULL);
}

void * aircraft_start_routine(void *arg) {
	Aircraft& aircraft = *(Aircraft*) arg;
	aircraft.update_position();
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
	res = timer.start_periodic_timer();
			if (res < 0) {
				perror("Start periodic timer");
			}

	while (1) {
	timer.wait_next_activation();
	calculate_position();
	msg.id = id;
	msg.x_coor = x_coor;
	msg.y_coor = y_coor;
	msg.z_coor = z_coor;
	msg.x_speed = x_speed;
	msg.y_speed = y_speed;
	msg.z_speed = z_speed;
	std::cout << msg.id;
	std::cout << msg.x_coor;
	std::cout << msg.y_coor;
	std::cout << msg.z_coor;
	std::cout << msg.x_speed;
	std::cout << msg.y_speed;
	std::cout << msg.z_speed;
	client.send(msg);
	}
}

void Aircraft::calculate_position() {
	this->x_coor = x_coor + (time * x_speed);
	this->y_coor = y_coor + (time * y_speed);
	this->z_coor = z_coor + (time *	z_speed);
}

void Aircraft::update() {
	 rc = pthread_attr_init(&attr);
//	    if (!rc) {
//	    }
	    pthread_attr_setschedpolicy(&attr, SCHED_RR);
    rc = pthread_create(&thread_id, NULL, aircraft_start_routine , (void *) this);
//    if (!rc) {
//
//    }
//    pthread_join(pthread, NULL);
}

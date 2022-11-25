/*
 * Aircraft.c++
 *
 *  Created on: Oct. 25, 2022
 *      Author: coen320
 */
#include "Aircraft.h"

Aircraft::Aircraft(uint16_t id, int x_coor, int y_coor, int z_coor, int x_speed, int y_speed, int z_speed, Client client,Server server)
        : id(id), x_coor(x_coor),
          y_coor(y_coor), z_coor(z_coor), x_speed(x_speed), y_speed(y_speed), z_speed(z_speed), client(client), server(server){
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

void Aircraft::update_position() {
	start_periodic_timer(1000000,5000000);
	while (!exit()) {
	wait_next_activation();
	task_body();
	}
}

void Aircraft::calculate_position() {

}

void Aircraft::update() {
//	 rc = pthread_attr_init(&attr);
//	    if (!rc) {
//	    }
//	    pthread_attr_setschedpolicy(&attr, SCHED_RR);
    	rc = pthread_create(&thread_id, NULL, aircraft_start_routine , (void *) this);
    	std::cout<< "plane thread running" << std::endl;
}

void Aircraft::task_body() {
    struct timespec tv;

    if (start == 0) {
        clock_gettime(CLOCK_MONOTONIC, &tv);
        start = tv.tv_sec * ONE_THOUSAND + tv.tv_nsec / ONE_MILLION;
    }

    clock_gettime(CLOCK_MONOTONIC, &tv);
    current = tv.tv_sec * ONE_THOUSAND + tv.tv_nsec / ONE_MILLION;

    if (cycles > 0) {
    	fprintf(stderr, "Ave interval between instances: %f milliseconds\n",(double) (current - start) / cycles);
    	calculate_position();
    	msg.id = id;
    	msg.x_coor = x_coor;
    	msg.y_coor = y_coor;
    	msg.z_coor = z_coor;
    	msg.x_speed = x_speed;
    	msg.y_speed = y_speed;
    	msg.z_speed = z_speed;
    	client.send(msg);
    }

    cycles++;
}

bool Aircraft::exit() {
	return airspace.x_space < x_coor || airspace.y_space < y_coor || airspace.z_space < z_coor;
}

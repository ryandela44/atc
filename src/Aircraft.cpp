/*
 * Aircraft.c++
 *
 *  Created on: Oct. 25, 2022
 *      Author: coen320
 */
#include "Aircraft.h"

Aircraft::Aircraft(int id, int x_coor, int y_coor, int z_coor, int x_speed, int y_speed, int z_speed)
        : id(id), x_coor(x_coor),
          y_coor(y_coor), z_coor(z_coor), x_speed(x_speed), y_speed(y_speed), z_speed(z_speed) {
//    rc = pthread_attr_init(&attr);
//    if (!rc) {
//    }
//    pthread_attr_setschedpolicy(&attr, SCHED_RR);
}

Aircraft::~Aircraft() {
//    pthread_attr_destroy(&attr);
//    pthread_exit(NULL);
}

int Aircraft::get_id() {
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

void *Aircraft::update_position(void *arg) {
    return NULL;
}

void Aircraft::update() {
    //rc = pthread_create(&pthread, &attr, update_position , std::to_string(id));
//    if (!rc) {
//
//    }
//    pthread_join(pthread, NULL);
}

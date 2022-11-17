/*
 * Aircraft.c++
 *
 *  Created on: Oct. 25, 2022
 *      Author: coen320
 */
#include <pthread.h>
#include "ClientServer.cpp"
class Aircraft {
public:
    Aircraft(int id, int x_coor, int y_coor, int z_coor, int x_speed,int y_speed,int z_speed, ClientServer server) {
        this->id = id;
        this->x_coor = x_coor;
        this->y_coor = y_coor;
        this->z_coor = z_coor;
        this->x_speed = x_speed;
        this->y_speed = y_speed;
        this->z_speed = z_speed;
        this->server = server;
        rc = pthread_attr_init(&attr);
        if (!rc) {
        }
        pthread_attr_setschedpolicy(&attr,SCHED_RR);
    }

    ~Aircraft() {
        pthread_attr_destroy(&attr);
        pthread_exit(NULL);
    }

    int get_id() {
        return id;
    }

    int get_x_coor() {
        return x_coor;
    }

    int get_y_coor() {
        return y_coor;
    }

    int get_z_coor() {
        return z_coor;
    }

    int get_x_speed() {
        return x_speed;
    }

    int get_y_speed() {
        return y_speed;
    }

    int get_z_speed() {
        return z_speed;
    }

    void *update_position(int x_coor, int y_coor, int z_coor, int x_speed, int y_speed,int z_speed) {
        this->x_coor = x_coor;
        this->y_coor = y_coor;
        this->z_coor = z_coor;
        this->x_speed = x_speed;
        this->y_speed = y_speed;
        this->z_speed = z_speed;
        server.send(get_x_coor());
        return NULL;
    }

    void update() {
        rc = pthread_create(&pthread, &attr, update_position , void(*) id);
        if (!rc) {

        }
        pthread_join(pthread, NULL);
    }


private:
    int id;
    int x_coor;
    int y_coor;
    int z_coor;
    int x_speed;
    int y_speed;
    int z_speed;
    int rc;
    pthread_attr_t attr;
    pthread_t pthread;
    ClientServer server;
};

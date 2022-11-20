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
    tmp = server.run();
    std::cout << "ID : " << tmp[0] << std::endl;
    std::cout << "x_coor : " << tmp[1] << std::endl;
    std::cout << "y_coor : " << tmp[2] << std::endl;
    std::cout << "altitude : " << tmp[3] << std::endl;
    std::cout << "x_speed : " << tmp[4] << std::endl;
    std::cout << "y_speed : " << tmp[5] << std::endl;
    std::cout << "z_speed : " << tmp[6] << std::endl;
    tmp.clear();
}

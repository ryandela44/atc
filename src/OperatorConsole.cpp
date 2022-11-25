#include "OperatorConsole.h"

OperatorConsole::OperatorConsole(ComputerSystem computer,Client client,int period_sec, int period_msec) : computer(computer), client(client), period_sec(period_sec), period_msec(period_msec) {
	init();
}

void * console_start_routine(void *arg) {
	OperatorConsole& aircraft = *(OperatorConsole*) arg;
	return NULL;
}

void OperatorConsole::init(){
	pthread_create(&thread_id, NULL, console_start_routine , (void *) this);
}

void OperatorConsole::send(uint16_t id, int x_coor, int y_coor, int z_coor, int x_speed, int y_speed, int z_speed) {
	msg.hdr.type = 0x02;
	msg.id = id;
	msg.x_coor = x_coor;
	msg.y_coor = y_coor;
	msg.z_coor = z_coor;
	msg.x_speed = x_speed;
	msg.y_speed = y_speed;
	msg.z_speed = z_speed;
	client.send(msg);
}

std::vector<int> OperatorConsole::request(std::vector<int> info) {
return info;
}



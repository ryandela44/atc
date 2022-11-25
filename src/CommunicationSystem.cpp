#include "CommunicationSystem.h"

CommunicationSystem::CommunicationSystem(ComputerSystem computer,  Client client) : computer(computer), client(client) {
init();
}

void * com_start_routine(void *arg) {
	CommunicationSystem& com = *(CommunicationSystem*) arg;
	com.send();
	return NULL;
}

void CommunicationSystem::init() {
	pthread_create(&thread_id, NULL, com_start_routine , (void *) this);
}

void CommunicationSystem::send() {
	id = std::get<0>(computer.send_command());
	command = std::get<1>(computer.send_command());
	msg.hdr.type = 0x01;
	msg.id = id;
	msg.cmd = command;
	client.send(msg);
}

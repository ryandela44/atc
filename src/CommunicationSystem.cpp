#include "CommunicationSystem.h"

CommunicationSystem::CommunicationSystem() {
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
	Server server("com");
	Client client;
	while (1) {
		rcv_data = server.run();
		if (rcv_data.hdr.type == 0x02) {
			rcv_data.hdr.type = 0x05;
			std::cout << "com received : " << rcv_data.id << std::endl;
			client.send(std::to_string(msg.id).c_str(),msg);
		}
	}
}

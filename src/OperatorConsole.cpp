#include "OperatorConsole.h"
std::string in;
OperatorConsole::OperatorConsole(int period_sec, int period_msec) :  period_sec(period_sec), period_msec(period_msec) {
	init();
}

void * console_start_routine(void *arg) {
	OperatorConsole& aircraft = *(OperatorConsole*) arg;
	return NULL;
}

void * input_console_start_routine(void* arg) {
	std::string s;
	std::cin >> s;
	in = s;
	return NULL;
}

void * rcv_console_start_routine(void* arg) {
	Server server("console");
	Client client;
	my_data_t rcv_data = server.run();

	if ( rcv_data.hdr.type == 0x02) {
		if (in.find( "speed") != in.npos) {
			rcv_data.cmd = "speed";
		}
		if (in.find("altitude") != in.npos) {
			rcv_data.cmd = "altitude";
		}
		if (in.find("position")!= in.npos) {
			rcv_data.cmd = "position";
		}
		rcv_data.hdr.type = 0x04;
		client.send("computer",rcv_data);
	}
	return NULL;
}

void OperatorConsole::init(){
	pthread_create(&thread_id, NULL, console_start_routine , (void *) this);
}

void OperatorConsole::send() {
	cTimer timer(period_sec,period_msec);
	Client client;
	pthread_create(&thread_input_console_id,NULL,input_console_start_routine,NULL);
	pthread_create(&thread_rcv_console_id,NULL,rcv_console_start_routine,NULL);
	pthread_join(thread_input_console_id,NULL);
	pthread_join(thread_rcv_console_id,NULL);

	if (in.find("display") != in.npos) {
	msg.hdr.type = 0x04;
	msg.cmd = "display";
	client.send("computer", msg);
	}
	timer.waitTimer();
}





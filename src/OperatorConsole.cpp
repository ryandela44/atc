#include "OperatorConsole.h"
std::string in;
my_data_t msg;
OperatorConsole::OperatorConsole(int period_sec, int period_msec) :  period_sec(period_sec), period_msec(period_msec) {
	init();
}

void * console_start_routine(void *arg) {
	OperatorConsole& console = *(OperatorConsole*) arg;
	console.send();
	return NULL;
}

void * input_console_start_routine(void* arg) {
	std::string s;
	Client client;
	while (1) {
		std::cout << "enter something " << std::endl;
		std::cin >> s;
		in = s;
		if (!s.empty()) {
			std::cout << s << std::endl;
		}

		if (in.find( "speed") != in.npos) {
			msg.cmd = "speed";
		}
		if (in.find("altitude") != in.npos) {
			msg.cmd = "altitude";
		}
		if (in.find("position")!= in.npos) {
			msg.cmd = "position";
		}
		if (in.find("display") != in.npos) {
			msg.hdr.type = 0x04;
			msg.cmd = "display";
			client.send("computer", msg);
		}

		if (!msg.cmd.empty()) {
			msg.hdr.type = 0x04;
			std::cout << "sending data " << std::endl;
			client.send("computer",msg);
		}
	}
	return NULL;
}

void * rcv_console_start_routine(void* arg) {
	Server server("console");
	Client client;
	while (1) {
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
	}
	return NULL;
}

void OperatorConsole::init() {
	pthread_create(&thread_id, NULL, console_start_routine , (void *) this);
}

void OperatorConsole::send() {
	//cTimer timer(period_sec,period_msec);
	Client client;
	pthread_create(&thread_input_console_id,NULL,input_console_start_routine,NULL);
	pthread_join(thread_input_console_id,NULL);
	pthread_create(&thread_rcv_console_id,NULL,rcv_console_start_routine,NULL);
	pthread_join(thread_rcv_console_id,NULL);
	//timer.waitTimer();
}





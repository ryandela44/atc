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
	Logger logger("console");
	Client client;
	std::string s;

	while (1) {
		std::cin >> s;
		in = s;
		my_data_t rcv_data = msg;

		if (!s.empty()) {
			logger.log(s,"r");
		}

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
		std::cout << "sending data " << std::endl;
		client.send("computer",rcv_data);
	}

	return NULL;
}

void OperatorConsole::init() {
	pthread_create(&thread_id, NULL, console_start_routine , (void *) this);
	pthread_create(&thread_input_console_id, NULL, input_console_start_routine , (void *) this);
}

void OperatorConsole::send() {
	Server server("console");
	Client client;

	while (1) {
		msg = server.run();
	}
}





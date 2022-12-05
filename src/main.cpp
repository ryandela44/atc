#include <iostream>
#include "Radar.h"
#include "Aircraft.h"
#include "DataDisplay.h"
#include <vector>
#include "Server.h"
#include "Filesystem.h"
#include "ComputerSystem.h"
#include "OperatorConsole.h"
#include "CommunicationSystem.h"
#include "Generator.h"


using namespace std;

int main() {
	//cTimer timer(1, 0);
	std::vector <Aircraft> aircrafts = {{0x00, 0, 500, 1000, 200, 200, 200,1,0},
	                                       {0x01, 500, 0, 7000, 200, 200, 200,1,0},
	                                        {0x02, 0, 0, 5000, 200, 200, 200,1,0}};
	Radar radar(1,0);
	OperatorConsole console(2,0);
	ComputerSystem computer(1, 0);
	DataDisplay display(1,0);
	CommunicationSystem com;
	//Generator generator;
	//std::vector <Aircraft> aircrafts;
	//auto planes = generator.generate(5);
	//auto tmp = planes;
	//int counter = 0;
	/*while (1) {
		for (auto p : planes) {
			if (p[0] == counter) {
				auto it = std::find(tmp.begin(), tmp.end(), p);
				if (it != tmp.end()) {
					aircrafts.push_back({p[1],p[2],p[3],p[4],p[5],p[6],p[7],1,0});
				}
				it = tmp.erase(it);
			}
		}
		timer.waitTimer();
		counter ++;
	}*/
	pthread_join(radar.thread_id,NULL);
	for(auto aircraft : aircrafts) {
		pthread_join(aircraft.thread_id,NULL);
		pthread_join(aircraft.server_thread_id,NULL);
	}
	pthread_join(computer.thread_id,NULL);
	pthread_join(computer.thread_server_id, NULL);
	pthread_join(display.thread_id,NULL);
	pthread_join(console.thread_id,NULL);
	pthread_join(console.thread_input_console_id,NULL);
	pthread_join(com.thread_id,NULL);

	return 0;
}

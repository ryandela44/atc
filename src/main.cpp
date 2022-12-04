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
#include "Timer.h"
#include "Generator.h"


using namespace std;

int main() {
	std::vector<std::vector<int>> planes;
	//cTimer timer(1, 0);
	//int counter = 0;
	//std::vector <Aircraft> aircrafts;
	std::vector <Aircraft> aircrafts = {{0x00, 0, 500, 1000, 200, 200, 200,1,0},
	                                        {0x01, 500, 0, 7000, 200, 200, 200,1,0},
	                                        {0x02, 0, 0, 5000, 200, 200, 200,1,0}};
	Radar radar(1,0);
	OperatorConsole console(2,0);
	ComputerSystem computer(1,0);
	DataDisplay display(1,0);
	CommunicationSystem com();
//	Filesystem filesystem;
//	Generator generator;
//	auto planes_ = generator.load(10);
//	char* filename = "input.txt";
//	std::string s;
//	const char * content;
//	for (auto p : planes_) {
//		for (int i = 0;  i < p.size();  i++ ) {
//			if (i == p.size()-1) {
//				s.append(p[i]);
//			}
//			else {
//				s.append(p[i] + " , ");
//			}
//		}
//		s.append("\n");
//	}
//	content = s.c_str();
//	filesystem.write_file(filename, content);
//	planes = filesystem.parse(filename);
//	while (1) {
//		for (int i = 0; i < planes.size(); i++) {
//			for (auto p : planes) {
//				if (p[0] == counter) {
//					auto it = planes.begin();
//					//std::cout << "plane entered airspace " << p[1] << " at time : " << p[0] << std::endl;
//					aircrafts.push_back({p[1],p[2],p[3],p[4],p[5],p[6],p[7]});
//					it = std::find(planes.begin(), planes.end(), p);
//					it = planes.erase(it);
//					break;
//				}
//			}
//		}
//		timer.waitTimer();
//		counter ++;
//	}
	pthread_join(radar.thread_id,NULL);
	for(auto aircraft : aircrafts) {
		pthread_join(aircraft.thread_id,NULL);
	}
	pthread_join(computer.thread_id,NULL);
	pthread_join(display.thread_id,NULL);
	pthread_join(console.thread_id,NULL);
	return 0;
}

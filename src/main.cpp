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


using namespace std;

int main() {
	//cTimer timer(1, 0);
    std::vector <Aircraft> aircrafts = {{0x00, 0, 500, 1000, 200, 200, 200,1,000},
                                        {0x01, 500, 0, 7000, 200, 200, 200,1,000},
                                        {0x02, 0, 0, 5000, 200, 200, 200,1,000}};
    Radar radar(1,0);
//    OperatorConsole console(2,0);
    ComputerSystem computer(1,0);
    DataDisplay display(1,0);
//    CommunicationSystem com();
//    Filesystem filesystem;
    		pthread_join(radar.thread_id,NULL);
    		for(auto aircraft : aircrafts) {
    	    pthread_join(aircraft.thread_id,NULL);
    	    }
    	    pthread_join(computer.thread_id,NULL);
    	    pthread_join(display.thread_id,NULL);
//    	    pthread_join(console.thread_id,NULL);

//    char* filename = "input.txt";
//    char content[] = {"time = 0, id = 0, x_coor = 500, y_coor = 500, z_coor = 1000 , x_speed = 200, y_speed=200 , z_speed = 200, "};
//    filesystem.write_file("input.txt", content);
//    char* buffer = filesystem.read_file(filename);
//    while(1) {
//    	std::cout << "in timer " << std::endl;
//    	timer.waitTimer();
//    }
    return 0;
}

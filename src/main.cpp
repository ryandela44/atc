#include <iostream>
#include "Radar.h"
#include "DataDisplay.h"
#include <vector>
#include "Server.h"
#include "Filesystem.h"
#include "ComputerSystem.h"
#include "OperatorConsole.h"
#include "Timer.h"


using namespace std;

int main() {
	Radar radar(1,0);
    std::vector <Aircraft> aircrafts = {{0x00, 500, 1000, 1000, 200, 200, 200,1,000},
                                        {0x01, 2000, 5000, 7000, 200, 200, 200,1,000},
                                        {0x02, 7000, 7000, 5000, 200, 200, 200,1,000}};
    OperatorConsole console(2,0);
    ComputerSystem computer(1,0);
    DataDisplay display(1,0);
    //Filesystem filesystem;
    		for(auto aircraft : aircrafts) {
    	    pthread_join(aircraft.thread_id,NULL);
    	    }
    	    pthread_join(radar.thread_id,NULL);
    	    pthread_join(computer.thread_id,NULL);
    	    pthread_join(display.thread_id,NULL);
    	    //pthread_join(console.thread_id,NULL);

//    char* filename = "input.txt";
//    char* buffer = filesystem.read_file(filename);
//    char content[] = {"id = 0, x_speed = 20"};
//    filesystem.write_file("input.txt", content);
    return 0;
}

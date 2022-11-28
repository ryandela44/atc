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
	Radar radar(2,0);
    std::vector <Aircraft> aircrafts = {{0x00, 1000, 1000, 1000, 200, 200, 200,1,0},
                                        {0x01, 2000, 5000, 7000, 200, 200, 200,1,0},
                                        {0x02, 7000, 7000, 5000, 200, 200, 200,1,0}};
    OperatorConsole console(4,0);
    ComputerSystem computer(radar, console,3,0);
    DataDisplay display(computer,5,0);
    Filesystem filesystem;
    //Timer timer;
    //timer.start_periodic_timer(1000,5000);
//    while (1) {
//    		//timer.wait_next_activation(); //wait for timer expiration
    	    pthread_join(radar.thread_id,NULL);
    	    for(auto aircraft : aircrafts) {
    	    pthread_join(aircraft.thread_id,NULL);
    	    }
    	    pthread_join(computer.thread_id,NULL);
    	    pthread_join(display.thread_id,NULL);
    	    pthread_join(console.thread_id,NULL);
//    		//timer.task_body(); //executes the task
//    }
//    pthread_join(radar.thread_id,NULL);
//    for (auto aicraft : aircrafts) {
//    	pthread_join(aicraft.thread_id,NULL);
//    }
//    char* filename = "input.txt";
//    char* buffer = filesystem.read_file(filename);
//    char content[] = {"id = 0, x_speed = 20"};
//    filesystem.write_file("G:\realtime\coen320\CLionProjects\atc\src\input.txt", content);
    /* for (auto aircraft : aircrafts) {
     aircraft.update_position();
     radar.interrogate();
     }*/
    return 0;
}

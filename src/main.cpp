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
	Radar radar(Server("data"));
    std::vector <Aircraft> aircrafts = {{0x00, 1000, 1000, 1000, 200, 200, 200, Client("data"),Server ("plane1")},
                                        {0x01, 2000, 5000, 7000, 200, 200, 200, Client("data"),Server ("plane2")},
                                        {0x02, 7000, 7000, 5000, 200, 200, 200, Client ("data"),Server("plane3")}};
    Airspace airspace;
    OperatorConsole console;
    ComputerSystem computer_system(radar, console);
    DataDisplay display(computer_system);
    Filesystem filesystem;
    Timer timer(100000,500000);
    timer.start_periodic_timer();
    while (1) {
    		timer.wait_next_activation(); //wait for timer expiration
    		timer.task_body(); //executes the task
    }
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

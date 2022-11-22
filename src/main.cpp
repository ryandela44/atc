#include <iostream>
#include "Radar.h"
#include "DataDisplay.h"
#include <vector>
#include "Server.h"
#include "Filesystem.h"
#include "ComputerSystem.h"
#include "OperatorConsole.h"


using namespace std;

int main() {
	Server server("data");
    Client client1("data");
    Client client2("data");
    Client client3("data");
    Server server1("plane1");
    Server server2("plane2");
    Server server3("plane3");
    Timer timer1(0,4);
    Timer timer2(2,6);
    Timer timer3(7,5);
    Radar radar(server);
    std::vector <Aircraft> aircrafts = {{0x00, 1000, 1000, 1000, 200, 200, 200, client1,server1,timer1},
                                        {0x01, 2000, 5000, 7000, 200, 200, 200, client2,server2,timer2},
                                        {0x02, 7000, 7000, 5000, 200, 200, 200, client3,server3,timer3}};
    Airspace airspace;
    OperatorConsole console;
    ComputerSystem computer_system(radar, console);
    DataDisplay display(computer_system);
    Filesystem filesystem;
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

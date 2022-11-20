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
    Client client1("data");
    Client client2("data");
    Client client3("data");
    Server server("data");
    Timer timer1(0,4);
    Timer timer2(2,6);
    Timer timer3(7,5);
    std::vector <Aircraft> aircrafts = {{0x00, 1000, 1000, 1000, 200, 200, 200, client1,timer1},
                                        {0x01, 2000, 5000, 7000, 200, 200, 200, client2,timer2},
                                        {0x02, 7000, 7000, 5000, 200, 200, 200, client3,timer3}};
    Airspace airspace;
    Radar radar(server);
    OperatorConsole console;
    ComputerSystem computer_system(radar, console);
    DataDisplay display(computer_system);
    Filesystem filesystem;
    char* filename = "input.txt";
    char* buffer = filesystem.read_file(filename);
//    char content[] = {"id = 0, x_speed = 20"};
//    filesystem.write_file("G:\realtime\coen320\CLionProjects\atc\src\input.txt", content);
    /* for (auto aircraft : aircrafts) {
     aircraft.update_position();
     radar.interrogate();
     }*/
    return 0;
}

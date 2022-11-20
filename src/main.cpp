#include <iostream>
#include "Radar.h"
#include <vector>
#include "Server.h"


using namespace std;

int main() {
	Client client1("data");
	Client client2("data");
	Client client3("data");
	Server server("data");
    std::vector <Aircraft> aircrafts = {{0x00, 1000, 1000, 1000, 200, 200, 200,client1},
                                        {0x01, 2000, 5000, 7000, 200, 200, 200,client2},
                                        {0x02, 7000, 7000, 5000, 200, 200, 200,client3}};
    Airspace airspace;
    DataDisplay display;
    Radar radar(aircrafts, airspace, display, server);
    radar.print();
   /* for (auto aircraft : aircrafts) {
    aircraft.update_position();
    radar.interrogate();
    }*/
    return 0;
}

#include <iostream>
#include "Radar.h"
#include <vector>
#include "Server.h"


using namespace std;

int main() {
    std::vector <Aircraft> aircrafts = {{1, 1000, 1000, 1000, 200, 200, 200},
                                        {2, 2000, 5000, 7000, 200, 200, 200},
                                        {3, 7000, 7000, 5000, 200, 200, 200}};
    Airspace airspace;
    DataDisplay display;
    Radar radar(aircrafts, airspace, display);
    radar.print();
    return 0;
}

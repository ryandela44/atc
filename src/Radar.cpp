#include <vector>
#include "DataDisplay.cpp"

class Radar {
private:
    std::vector <Aircraft> aircrafts;
    Airspace airspace;
    DataDisplay display;
public:
    Radar(std::vector <Aircraft> aircrafts, Airspace airspace, DataDisplay display) : aircrafts(aircrafts),
                                                                                      airspace(airspace),
                                                                                      display(display) {};

    void interrogate() {
        print();
        for (auto aircraft: aircrafts) {

        }
    }

    void print() {
        display.print_borders(aircrafts, airspace);
    }
};

#include <vector>
#include "DataDisplay.cpp"
class Radar {
private:
    std::vector<Aircraft> aircrafts;
    Airspace airspace;
    DataDisplay display;
public:
    Radar(std::vector<Aircraft> aircrafts, Airspace airspace, DataDisplay display) : aircrafts(aircrafts), airspace(airspace), display(display) {};
};

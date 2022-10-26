#include <vector>
#include "DataDisplay.cpp"
class Radar {
private:
    std::vector<Aircraft> aircrafts;
    Airspace airspace;
    DataDisplay display;
public:
    Radar(std::vector<Aircraft> aircrafts, Airspace airspace, DataDisplay display, ) {
        this->aircrafts = aircrafts;
        this->airspace = airspace;
        this->display = display;
    }
};
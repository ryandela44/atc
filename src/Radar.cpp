#include <vector>
#include "DataDisplay.cpp"
class Radar {
private:
    std::vector<Aircraft> aircrafts;
    Airspace airspace;
    DataDisplay display;
public:
    Radar(std::vector<Aircraft> aircrafts, Airspace airspace, DataDisplay display) : aircrafts(aircrafts), airspace(airspace), display(display) {};
  /*  void get_aircrafts_info() {
        for (auto aircraft : aircrafts) {
            aircraft.get_id();
            aircraft.get_x_coor();
            aircraft.get_y_coor();
            aircraft.get_z_coor();
            aircraft.get_x_speed();
            aircraft.get_y-speed();
            aircraft.get_z_speed();
        }
    }*/
};

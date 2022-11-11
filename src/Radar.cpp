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
            std::cout << std::to_string(aircraft.get_id()) << std::endl;
            std::cout
                    << "Position : " + "(" + std::to_string(aircraft.get_x_coor()) + "," + std::to_string(aircraft.get_y_coor()) + ")"
                    << std::endl;
            std::cout << "Altitude : " + std::to_string(aircraft.get_z_coor()) << std::endl;
            std::cout << "Speed : " + "(" +std::to_string(aircraft.get_x_speed()) + "," +
                         std::to_string(aircraft.get_y_speed()) + "," + std::to_string(aircraft.get_z_speed()) + ")" << std::endl;
        }
    }

    void print() {
        display.print_borders(aircrafts, airspace);
    }
};

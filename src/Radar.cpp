#include "Radar.h"

Radar::Radar(std::vector <Aircraft> aircrafts, Airspace airspace, DataDisplay display) : aircrafts(aircrafts),
                                                                                         airspace(airspace),
                                                                                         display(display) {};

void Radar::interrogate() {
    print();
    for (auto aircraft: aircrafts) {
//        	auto tmp_position =  "Position : " + "(" + std::to_string(aircraft.get_x_coor()) + "," + std::to_string(aircraft.get_y_coor()) + ")";
//        	auto tmp_speed = "Speed : " + "(" + std::to_string(aircraft.get_x_speed()) + "," + std::to_string(aircraft.get_y_speed()) + "," + std::to_string(aircraft.get_z_speed()) + ")";
        std::cout << std::to_string(aircraft.get_id()) << std::endl;
//            std::cout << tmp_position << std::endl;
        std::cout << "Altitude : " + std::to_string(aircraft.get_z_coor()) << std::endl;
//            std::cout << tmp_speed << std::endl;
    }
}

void Radar::print() {
    display.print_borders(aircrafts, airspace);
}

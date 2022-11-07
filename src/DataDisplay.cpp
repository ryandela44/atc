#include "Aircraft.cpp"
#include "Airspace.cpp"
#include <iostream>
#include <vector>
#include <tuple>

class DataDisplay {
private:
    int y,z;
    std::vector <Aircraft> aircrafts;
    Airspace airspace;
    std::vector<std::tuple<int,int>> positions;
public:
    DataDisplay(std::vector <Aircraft> aircrafts, Airspace airspace) : aircrafts(aircrafts), airspace(airspace) {};

    int scale(int param) {
        return param / 100;
    }

    void print_borders() {
        y = scale(airspace.get_y_space());
        z = scale(airspace.get_z_space());

        for (int i = 0; i < y; i++) {
            for (int j = 0; j < z; j++) {
                if (i == 0 || i == y - 1) {
                    if (j != z - 1) {
                        std::cout << "*";
                    } else {
                        std::cout << "*" << std::endl;
                    }
                } else if (j == 0) {
                    std::cout << "*";
                } else if (j == z - 1) {
                    std::cout << "*" << std::endl;
                } else if  (aircrafts.empty()) {
                    std::cout << " ";
                }
                else {
                    for (auto aircraft : aircrafts) {
                        if (i == scale(aircraft.get_y_coor()) && j == scale(aircraft.get_z_coor())) {
                            positions.push_back(std::make_tuple(i,j));
                            std::cout << std::to_string(aircraft.get_id());
                        } else {
                            std::vector<int>::iterator it;
                            it = std::find(positions.begin(), positions.end(), std::make_tuple(i,j));
                            if (it != positions.end()) {
                                std::cout << " ";
                            }
                        }
                    }
                }
                }
            }
        }

};

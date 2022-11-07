#include "Aircraft.cpp"
#include "Airspace.cpp"
#include <iostream>
#include <vector>
#include <tuple>

class DataDisplay {
private:
    int x, y;
    std::vector <Aircraft> aircrafts;
    Airspace airspace;
    std::vector <std::tuple<int, int>> positions;
public:
    DataDisplay(std::vector <Aircraft> aircrafts, Airspace airspace) : aircrafts(aircrafts), airspace(airspace) {};

    int scale(int param) {
        return param / 100;
    }

    void print_borders() {
        x = scale(airspace.get_x_space());
        y = scale(airspace.get_y_space());

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if ((i == 0 && j != y-1) || (i == x-1 && j!=y-1) || j == 0) {
                    std::cout << " * ";
                }
                else if (j == y-1) {
                    std::cout << " * " << std::endl;
                }
                else if  (aircrafts.empty()) {
                    std::cout << " ";
                }
                else {
                    for (auto aircraft : aircrafts) {
                        if (i == (100 - scale(aircraft.get_x_coor())) && j == scale(aircraft.get_y_coor())) {
                            std::cout << std::to_string(aircraft.get_id());
                            positions.push_back(std::make_tuple(i,j));
                        } else {
                            auto res = std::find(positions.begin(), positions.end(), std::make_tuple(i,j));
                            if (res == positions.end()) {
                                std::cout << " ";
                            }
                        }
                    }
                }
            }
        }
    }

};

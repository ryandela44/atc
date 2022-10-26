#include "Aircraft.cpp"
#include "Airspace.cpp"
#include <iostream>
#include <vector>

class  DataDisplay{
private:
    int y,z;
    std::vector<Aircraft> all_aircrafts;
    Airspace airspace;
public:
    DataDislay(std::vector<Aircraft> all_aircrafts,Airspace airspace) {
        this->all_aircrafts = all_aircrafts;
        this->airspace = airspace;
    }

    void scale() {
        y = airspace.get_y_space() / 100;
        z = airspace.get_z_space() / 100;
    }
     void print_borders() {
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < z; ++j) {
                if (i == 0 || i == y-1) {
                    if (j != z-1) {
                        std::cout << " - ";
                    }
                    else {
                        std::cout << " - " << std::endl;
                    }
                } else if (j == 0) {
                    std::cout << " | ";
                } else if (j == z-1) {
                    std::cout << " | " << endl;
                } else {
                    std::cout << " ";
                }
            }
        }
    }

};
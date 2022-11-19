/*
 * DataDisplay.h
 *
 *  Created on: Nov. 19, 2022
 *      Author: coen320
 */

#pragma once

#include "Aircraft.h"
#include "Airspace.h"
#include <iostream>
#include <vector>
#include <tuple>

class DataDisplay {
private:
    int x, y;
    std::vector <std::tuple<int, int>> positions;
public:
    DataDisplay();

    int scale(int param);

    void print_borders(std::vector <Aircraft> aircrafts, Airspace airspace);
};

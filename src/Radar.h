/*
 * Radar.h
 *
 *  Created on: Nov. 19, 2022
 *      Author: coen320
 */
#pragma once

#include <vector>
#include "DataDisplay.h"

class Radar {
private:
    std::vector <Aircraft> aircrafts;
    Airspace airspace;
    DataDisplay display;
public:
    Radar(std::vector <Aircraft> aircrafts, Airspace airspace, DataDisplay display);

    void interrogate();

    void print();
};




/*
 * Airspace.h
 *
 *  Created on: Nov. 19, 2022
 *      Author: coen320
 */

#pragma once

class Airspace {
private:
    int x_space = 10000;
    int y_space = 10000;
    int z_space = 25000;
    int sea_level = 15000;
public:
    Airspace();

    int get_x_space();

    int get_y_space();

    int get_z_space();
};

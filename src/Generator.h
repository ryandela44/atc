/*
 * Generator.h
 *
 *  Created on: Dec. 3, 2022
 *      Author: coen320
 */

#pragma once
#include "Filesystem.h"

class Generator {
private:
	bool x = true;
	bool y = false;
	int x_coor;
	int y_coor;
	std::vector<std::vector<std::string>> aircrafts;
	Filesystem filesystem;
public:
	int generate_time();
	int generate_x_value();
	int generate_y_value();
	int generate_x_coor();
	int generate_y_coor();
	int generate_z_coor();
	int generate_x_speed();
	int generate_y_speed();
	int generate_z_speed();
	std::vector<std::vector<std::string>> load(int size);
	std::vector<std::vector<int>> generate(int size);
};

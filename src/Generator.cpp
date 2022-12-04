/*
 * Generator.cpp
 *
 *  Created on: Dec. 3, 2022
 *      Author: coen320
 */
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include "Generator.h"

int Generator::generate_time() {
	int result = 1 + (rand() % 100);
	return result;
}

int Generator::generate_x_value() {
	int result = 0 + (rand() % 10000);
	return result;
}

int Generator::generate_y_value() {
	int result = 0 + (rand() % 10000);
	return result;
}

int Generator::generate_x_coor() {
	int result = 0 + (rand() % 2);
	if (result != 0) {
		x = true;
		y = false;
		return 0;
	}

	else {
		y = false;
		x = true;
		return 10000;
	}
}

int Generator::generate_y_coor() {
	int result = 0 + (rand() % 2);

	if (result != 0) {
		x = false;
		y = true;
		return 0;
	}

	else {
		x = false;
		y = true;
		return 10000;
	}
}

int Generator::generate_z_coor() {
	int result = 0 + (rand() % 15000);
	return result;
}

int Generator::generate_x_speed() {
	int result = 0 + (rand() % 300);
	return result;
}

int Generator::generate_y_speed() {
	int result = 0 + (rand() % 300);
	return result;
}

int Generator::generate_z_speed() {
	int result = 0 + (rand() % 300);
	return result;
}

std::vector<std::vector<std::string>> Generator::load(int size) {
	for (int i = 0; i < size; i++) {
		if (x) {
			x_coor = generate_x_coor();
			y_coor = generate_y_value();
		}

		else if (y) {
			y_coor = generate_y_coor();
			x_coor = generate_x_value();
		}

		if (x) {
			x = false;
			y = true;
		}

		else {
			x = true;
			y = false;
		}

		aircrafts.push_back({std::to_string(generate_time()), std::to_string(i), std::to_string(x_coor), std::to_string(y_coor), std::to_string(generate_z_coor()), std::to_string(generate_x_speed()), std::to_string(generate_y_speed()), std::to_string(generate_z_speed())});
	}

	return aircrafts;

}

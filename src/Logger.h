/*
 * Logger.h
 *
 *  Created on: Dec. 4, 2022
 *      Author: coen320
 */

#pragma once
#include <iostream>
#include <time.h>
#include <string>
#include <fstream>

class Logger {
private:
	std::string filename;
public:
	Logger(std::string filename);
	std::string getCurrentDateTime(std::string);
	void log(std::string msg, std::string ret);
};

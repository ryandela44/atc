/*
 * Filesystem.h
 *
 *  Created on: Nov. 19, 2022
 *      Author: coen320
 */
#pragma once
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

class Filesystem {
private:
	FILE *fp;
	char buffer [4096];
	int fd = 0;
	int size_read = 0;
	int size_written = 0;
	std::vector<std::vector<int>> aircrafts;
public:
	Filesystem();
	char* read_file(char* filename);
	void write_file(char* filename, const char * content);
	std::vector<std::vector<int>> parse(char* filename);
};

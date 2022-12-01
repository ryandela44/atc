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

class Filesystem {
private:
	char buffer [1024];
	int fd = 0;
	int size_read = 0;
	int size_written = 0;
public:
	Filesystem();
	char* read_file(char* filename);
	void write_file(char* filename, char * content);
};

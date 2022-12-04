#include "Filesystem.h"
Filesystem::Filesystem() {

}

char* Filesystem::read_file(char* filename) {
	/* Open a file for input */
	fd = open( filename, O_RDONLY );

	/* Read the text */
	size_read = read( fd, buffer,
			sizeof( buffer ) );

	/* Test for error */
	if( size_read == -1 ) {
		perror( "Error reading input file" );
	}

	//printf(buffer);

	/* Close the file */
	close( fd );
	return buffer;
}

void Filesystem::write_file(char* filename, const char* content) {
	//    	fd = creat( filename, S_IRUSR | S_IWUSR );
	//
	//    	    /* write the text              */
	//    	    size_written = write( fd, content,
	//    	              sizeof( content ) );
	//
	//    	    /* test for error              */
	//    	    if( size_written != sizeof( content ) ) {
	//    	        perror( "Error writing" );
	//    	    }
	//
	//    	    printf("wrote in file");
	//
	//    	    /* close the file              */
	//    	    close( fd );
	fp = fopen(filename,"w");
	fprintf(fp,"%s",content);
	fclose(fp);
}

std::vector<std::vector<int>> Filesystem::parse(char * filename) {
	//	char * line = NULL;
	//	size_t len = 0;
	//	ssize_t read;
	std::string buffer;
	std::vector<int> v;
	std::string s(read_file(filename));
	for (const auto c : s) {
		if (c == ' ' ) {
			continue;
		}

		if (c == ',') {
			v.push_back(std::stoi(buffer));
			buffer.clear();
			continue;
		}

		if (c == '\n') {
			aircrafts.push_back(v);
			buffer.clear();
			v.clear();
			continue;
		}

		buffer = buffer + c;
	}
	return aircrafts;
}

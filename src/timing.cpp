#include <assert.h>
#include <iostream>
#include <fstream>
#include "timing.h"
using namespace std;

//start and end default initalized by their contructor at the start of epoch
Timing::Timing() : start_(), end_() {}

void Timing::start() {
	start_ = chrono::high_resolution_clock::now();
}

void Timing::end() {
	assert(start_.time_since_epoch() != time_hres().time_since_epoch() && "start time should not be default value");
	end_ = chrono::high_resolution_clock::now();
}

double Timing::getTime() {
	assert(start_.time_since_epoch() <= end_.time_since_epoch() && "start time is not lower than end time");
	chrono::duration<double> time_diff = end_ - start_;
	return time_diff.count();
}

void Timing::reset() {
	start_ = time_hres();
	end_ = time_hres();
}

/* utility for writing times to a file 
* @path doesnt expect extension of the file, will set it based on the endline
* @header optional, if different from default value will only write the header and not the time
can use the openmode to set append or delete all content before writing */
void Timing::writeToFileTime(string header, const std::string path, std::ios_base::openmode write_mode, char endline) {
	fstream file;
	string extension_file = "";
	switch (endline) {
		case ',':
			extension_file = "csv";
			break;
		default:
			extension_file = "txt";
			break;
	}
	file.open(path + "." + extension_file, write_mode);
	if (header != "")
		file << header << endline;
	else
		file << getTime() << endl;
	file.close();
}

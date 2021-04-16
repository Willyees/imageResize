#pragma once
#include <chrono>
#include <string>
#include <fstream>

using time_hres = std::chrono::time_point<std::chrono::high_resolution_clock>;

/* collection of helper functions to help in timing the reisizing of an image */
class Timing {
	time_hres start_;
	time_hres end_;
	
public:
	Timing();
	void start();
	void end();
	double getTime();
	void reset();
	time_hres getStart() { return start_; }
	time_hres getEnd() { return end_; }

	void writeToFileTime(std::string header = "", const std::string path = "timing.txt", std::ios_base::openmode write = std::ios::app, char endline = '\n');
};

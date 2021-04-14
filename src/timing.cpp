#include <assert.h>
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
	chrono::duration<double> time_diff = start_ - end_;
	return time_diff.count();
}

void Timing::reset() {
	start_ = time_hres();
	end_ = time_hres();
}

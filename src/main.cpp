#include <iostream>
#include <vector>
#include "image.h"
#include "resample.h"
#include "timing.h"
using namespace std;

int main() {
	Timing t;
	t.writeToFileTime("timing 1d 2x3 scaling 1000");
	for (int i = 0; i < 10; ++i) {
		Image img;
		img.load_test_img2x3();
		t.start();
		nearestNeighborInterpolation(img, 1000);
		//img.print_img();
		t.end();
		t.writeToFileTime();
		t.reset();
	}
	t.writeToFileTime("timing 1d 2x2 scaling 1000");

	for (int i = 0; i < 10; ++i) {
		Image img;
		img.load_test_img2x2();
		t.start();
		nearestNeighborInterpolation(img, 1000);
		//img.print_img();
		t.end();
		t.writeToFileTime();
		t.reset();
	}


	return 0;
}
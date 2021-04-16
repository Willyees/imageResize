#include <iostream>
#include <vector>
#include "image.h"
#include "resample.h"
#include "timing.h"
using namespace std;

int main() {
	Timing t;
	for (int i = 0; i < 10; ++i) {
		Image img;
		img.load_test_img2x3();
		t.start();
		nearestNeighborInterpolation(img, 1000);
		//img.print_img();
		t.end();
		cout << t.getTime() << endl;
		t.reset();
	}

	for (int i = 0; i < 10; ++i) {
		Image img;
		img.load_test_img2x2();
		t.start();
		nearestNeighborInterpolation(img, 1000);
		//img.print_img();
		t.end();
		cout << t.getTime() << endl;
		t.reset();
	}


	return 0;
}
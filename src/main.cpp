#include <iostream>
#include <vector>
#include "image.h"
#include "resample.h"
using namespace std;

int main() {
	Image img;
	img.load_test_img3x2();
	img.print_img();
	nearestNeighborInterpolation(img, 2);
	img.print_img();
	
	return 0;
}
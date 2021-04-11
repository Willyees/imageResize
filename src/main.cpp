#include <iostream>
#include <vector>
#include "image.h"
#include "resample.h"
using namespace std;

int main() {
	Image img;
	img.load_test_img2x3();
	//img.print_img();
	nearestNeighborInterpolation(img, 2);
	img.print_img();
	
	return 0;
}
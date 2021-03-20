#include "image.h"
#include <iostream>
using namespace std;

Image::Image() : _img(), _row_length(0), _col_length(0){

}

/*default initalize (0) the _img vector
*/
Image::Image(size_t rows, size_t columns) : Image() {//delegating to default constructor to initialize members
	for (int i = 0; i < rows; ++i) {
		_img.push_back(vector<int>(columns));
	}
	_row_length = _img.size();
	try {
		_col_length = _img[0].size();
	}
	catch (const std::exception&){
		cout << "image should have at least 1 row" << endl;
	}
}

/*create debug img 3x4
*/
void Image::load_test_img() {
	_img = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
}

#include <iostream>
#include <iomanip>

#include "image.h"

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

/*create debug img 2x2
*/
void Image::load_test_img2x2() {
	_img = { {1,4}, {6, 8} };
	_row_length = 2;
	_col_length = 2;
	//_img = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
}

void Image::load_test_img3x2() {
	_img = { {1,4}, {6, 8}, {13, 19} };
	_row_length = 3;
	_col_length = 2;
}

void Image::print_img() {
	char prev = cout.fill('0');
	for (int row = 0; row < _row_length; ++row) {
		for (int col = 0; col < _col_length; ++col)
			cout << setw(2) << _img[row][col] << " ";
		cout << endl;
	}
	cout.fill(prev);
}

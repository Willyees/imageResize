#include <iostream>
#include <iomanip>
#include <assert.h>
#include "image.h"

using namespace std;
/*
* @params idx: index on the _img
* @return index pointing to the row number where the idx parameter is.
*/
inline int Image::_getRow(int idx) {
	return idx / _row_length;
}

/*
* @return index of 1d representation of 2d vector of specific row, col coordinate (opposite of _getRow())
*/
int Image::_getIdx(int row, int col) const {
	return row * _row_length + col;
}

Image::Image() : _img(), _row_length(0), _col_length(0){

}

/*default initalize (0) the _img vector
*/
Image::Image(size_t rows, size_t columns) : Image() {//delegating to default constructor to initialize members
	_img.resize(rows * columns, 0);//default initalized all the pixel values
	
	_row_length = rows;
	_col_length = columns;
	assert(_img.size() == _row_length * _col_length && "number of pixels is not correct, review col and row length");
}

//copy
Image::Image(Image& other) {
	*this = other;
}

//move
Image::Image(Image&& other) {
	*this = move(other);
}

//copy assign
Image& Image::operator=(const Image& other){
	_col_length = other._col_length;
	_row_length = other._row_length;
	_img = other._img;
	return *this;
}

//move assign
Image& Image::operator=(const Image&& other) {
	_col_length = other._col_length;
	_row_length = other._row_length;
	_img = move(other._img);//using vector move assign operator
	return *this;
}

/*create debug img 2x2
*/
void Image::load_test_img2x2() {
	_img = { 1,4, 6, 8 };
	_row_length = 2;
	_col_length = 2;
	//_img = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
}

void Image::load_test_img2x3() {
	_img = {1,4, 6, 8, 13, 19};
	_row_length = 3;
	_col_length = 2;
}

void Image::print_img() {
	char prev = cout.fill('0');
	for (size_t row = 0; row < _col_length; ++row) {
		for (size_t col = 0; col < _row_length; ++col)
			cout << setw(2) << _img.at(row * _row_length + col) << " ";
		cout << endl;
	}
	cout << "-----" << endl;
	for (size_t i = 0; i < _img.size(); ++i) {
		cout << setw(2) << _img[i] << " ";
		if (((i + 1) % _row_length) == 0)
			cout << endl;
	}
	cout.fill(prev);
}

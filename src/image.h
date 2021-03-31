#pragma once
#include <vector>
#include <string>

class Image {

public:
	std::vector<int> _img;//single vector containing all pixels. have to refer to _row_length to calculate the rows
	int _row_length;//row length, referring to the complete image. an image being interpolated will have the original _row_length stored
	int _col_length;
//public: //todo: set the private memebrs again, and set friends methods	
	Image();
	Image(size_t rows, size_t columns);
	Image(std::string path_load);

	//DEBUG	
	void load_test_img2x2();
	void load_test_img3x2();
	inline int _getRow(int idx);
	inline int _getIdx(int row, int col);

	void print_img();
};
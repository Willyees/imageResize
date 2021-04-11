#pragma once
#include <vector>
#include <string>

class Image {

public:
	std::vector<int> _img;//single vector containing all pixels. have to refer to _row_length to calculate the rows
	int _row_length;//row length, referring to the complete image. an image being interpolated will have the original _row_length stored
	int _col_length;
//public: //todo: set the private memebrs again, and set friends methods	
	//constructors
	Image();
	Image(size_t rows, size_t columns);
	Image(std::string path_load);
	Image(Image& other);
	Image(Image&& other);
	~Image() = default;

	//operators
	Image& operator=(const Image& other);//copy
	Image& operator=(const Image&& other);//move

	//DEBUG	
	void load_test_img2x2();
	void load_test_img2x3();
	inline int _getRow(int idx);
	int _getIdx(int row, int col) const;

	void print_img();
};
#include <vector>
#include <string>

class Image {
private:
	std::vector<std::vector<int>> _img;//each internal vector is a row (could implement as a single long vector in case it's faster)
	int _row_length;//row length, referring to the complete image. an image being interpolated will have the original _row_length stored
	int _col_length;
public:
	Image();
	Image(size_t rows, size_t columns);
	Image(std::string path_load);

	//DEBUG	
	void load_test_img();
};
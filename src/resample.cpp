#include <vector>
#include "resample.h"

using namespace std;
/*simplest method to upsample an image: repeat the closest pixels. at the moment simple integer scaling factor.
* this method will perform the whole scaling, not very performant because it is O(N*scaling_factor) extra space needed with loads of copies from temp vectors to _img vector
*/
void nearestNeighborInterpolation(Image& img, int scaling_factor) {
	int row_o = img._row_length;
	int col_o = img._col_length;
	int row_n = row_o * scaling_factor;
	int col_n = col_o * scaling_factor;

	vector<vector<int>> v;
	v.reserve(row_n);
	for (int row_idx = 0; row_idx < row_n; ++row_idx) {
		vector<int> row(col_n);
		for (int col_idx = 0; col_idx < col_n; ++col_idx) {
			row[col_idx] = img._img[row_idx / scaling_factor][col_idx / scaling_factor];
		}
		v.push_back(row);
	}
	//updating the row and col length in the img after the interpolation
	img._img = v;//using copy assing operator, move should be faster. TODO: time it!
	img._row_length = row_n;
	img._col_length = col_n;
}

/* TODO working with 2d space, but liner should be only in 1D space. have to fix it later on
* @param: 'img': image to work on;	'row': row in which the cell to be calculated the interpolation is situated;	'col': same as row, but column
*         ~'row_original': n of rows before the scaling-> not using it anymore, getting this info from the img obj
* @return: none. modify the img object to store the interpolated value
*/
void linearInterpolation(Image& img, int row, int col) {
	//use the img._col_length to calculate the nearest neighbours

}

void bilinearInterpolation(Image& img) {
}

#include <vector>
#include "resample.h"
#include <iostream>

using namespace std;
/*simplest method to upsample an image: repeat the closest pixels. at the moment simple integer scaling factor.
* this method will perform the whole scaling, not very performant because it is O(N*scaling_factor) extra space needed with loads of copies from temp vectors to _img vector
*/
void nearestNeighborInterpolation(Image& img, int scaling_factor) {
	/*int row_o = img._row_length;
	int col_o = img._col_length;
	int row_n = row_o * scaling_factor;
	int col_n = col_o * scaling_factor;
	int scaling = row_n * col_n / row_o / col_o;*/

	vector<int> v(img._row_length * scaling_factor * img._col_length * scaling_factor);
	for (size_t row_o = 0; row_o < img._col_length; ++row_o) {
		for (size_t col_o = 0; col_o < img._row_length; ++col_o) {
			const size_t idx_o = row_o * img._row_length + col_o;
			const int val = img._img[idx_o];//img._getIdx(row_o, col_o);
			const size_t idx_first_scaled_row = row_o * scaling_factor;
			const size_t idx_first_scaled_col = col_o * scaling_factor;
			//size_t idx_new_scaled = img._getIdx(idx_first_scaled_row, idx_first_scaled_col);

			//cout << val << endl;
			for (size_t scale_row = 0; scale_row < scaling_factor; ++scale_row) {
				size_t row_2d = scale_row + idx_first_scaled_row;
				for (size_t scale_col = 0; scale_col < scaling_factor; ++scale_col) {
					size_t col_2d = scale_col + idx_first_scaled_col;
					size_t idx_scaled = row_2d * img._row_length * scaling_factor + col_2d;
					cout << idx_scaled << "\t";
					v[idx_scaled] = val;
					//cout << idx_scaled << endl;
				}
			}
			cout << endl;

		}
	}

	img._img = move(v);
	img._col_length *= scaling_factor;
	img._row_length *= scaling_factor;
	/*for (int row_idx = 0; row_idx < row_n; ++row_idx) {
		for (int col_idx = 0; col_idx < col_n; ++col_idx) {
			const int idx = row_idx * col_idx + col_idx;
			v[idx] = img._img[(idx / col_o / row_o )/ scaling_factor];
		}
	}*/
	//updating the row and col length in the img after the interpolation
	/*img._img = v;//using copy assing operator, move should be faster. TODO: time it!
	img._row_length = row_n;
	img._col_length = col_n;*/
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

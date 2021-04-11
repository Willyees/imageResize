#include <vector>
#include <iostream>
#include <assert.h>
#include "resample.h"


using namespace std;
void scaling(Image& img, const int scaling_factor, Interpolation i_type) {
	assert(scaling_factor > 0 && "scaling factor cannot be lower than 0");
	switch (i_type)
	{
	case Interpolation::nearestNeighbor:
		nearestNeighborInterpolation(img, scaling_factor);
		break;
	case Interpolation::linear:
		//linearInterpolation(img, 0, 0);//todo fix row and col here
		break;
	case Interpolation::bilinear:
		//bilinearInterpolation(img);
		break;
	default:
		assert(true && "interpolation selected is not amongst the possible ones - you should not be able to reach this point");
		break;
	}
}
/*simplest method to upsample an image: repeat the closest pixels. at the moment simple integer scaling factor.
* this method will perform the whole scaling, not very performant because it is O(N*scaling_factor) extra space needed with loads of copies from temp vectors to _img vector
*/
void nearestNeighborInterpolation(Image& img, int scaling_factor) {
	
	Image img_scaled(img._row_length * scaling_factor, img._col_length * scaling_factor);//temp image to store all the new pixels
	for (size_t row_o = 0; row_o < img._col_length; ++row_o) {
		for (size_t col_o = 0; col_o < img._row_length; ++col_o) {
			const size_t idx_o = row_o * img._row_length + col_o;
			const int val = img._img[idx_o];
			const size_t idx_first_scaled_row = row_o * scaling_factor;
			const size_t idx_first_scaled_col = col_o * scaling_factor;

			//cout << val << endl;
			for (size_t scale_row = 0; scale_row < scaling_factor; ++scale_row) {
				size_t row_2d = scale_row + idx_first_scaled_row;
				for (size_t scale_col = 0; scale_col < scaling_factor; ++scale_col) {//scale_col is mostly a counter, iterating number of times needed to get next elements in same row (but different column)
					size_t col_2d = scale_col + idx_first_scaled_col;
					size_t idx_scaled = row_2d * img._row_length * scaling_factor + col_2d;
					cout << idx_scaled << "\t";
					img_scaled._img[idx_scaled] = val;
					//cout << idx_scaled << endl;
				}
			}
			cout << endl;

		}
	}

	img = move(img_scaled);
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

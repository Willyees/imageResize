#pragma once
#include "image.h"

void nearestNeighborInterpolation(Image& img, int scaling_factor);
void linearInterpolation(Image& img, int row, int col);
void bilinearInterpolation(Image& img);
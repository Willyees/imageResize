#pragma once
#include "image.h"

enum class Interpolation
{
	nearestNeighbor, linear, bilinear
};
void scaling(Image& img, const int scaling_factor, Interpolation = Interpolation::nearestNeighbor);
void nearestNeighborInterpolation(Image& img, int scaling_factor);
void linearInterpolation(Image& img, int row, int col);
void bilinearInterpolation(Image& img);
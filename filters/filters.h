#ifndef FILTERS_H
#define FILTERS_H

#include <string>
#include "Image_Class.h"
using namespace std;

// functions for filters
void grayscale(Image &image, string &filename);
void BlackandWhite(Image &image, string &filename);
void invert_image(Image &image, string &filename);
void flip_image(Image &image, string &filename, int type);              
void rotate_image(Image &image, string &filename, int angle);           
void Darken_Lighten_Image(Image &image, string &filename, string answer);
void crop_image(Image &image, string &filename, long x, long y, long w, long h);

#endif

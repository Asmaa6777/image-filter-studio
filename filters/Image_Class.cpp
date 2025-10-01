#include "Image_Class.h"

Image::Image(string fname) {
    filename = fname;
    cout << "Image " << filename << " loaded.\n";
}

void Image::saveImage(string fname) {
    cout << "Image saved as " << fname << endl;
}

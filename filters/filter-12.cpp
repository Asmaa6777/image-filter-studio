// A demo for converting image to gray scale

#include <iostream>
using namespace std;
#include "Image_Class.h"

int main() {
    string filename;
    cout << "Pls enter colored image name to turn to gray scale: ";
    cin >> filename;

    Image image(filename);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) 
            for (int k = 0; k < 3; ++k) {
                for (int b; b< 3 ; b++ ){
                int avg += image(i,j,k) ; 
                }
                avg /= 3;
                image(i, j, k) = avg;
            } 
        }
    

    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);

    return 0;
}

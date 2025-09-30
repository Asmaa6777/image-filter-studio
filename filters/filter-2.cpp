#include <iostream>
#include "Image_Class.h"
using namespace std;

int main() {
    string filename;
    cout << "Enter colored image to be converted to black&white ";
    cin >> filename;

    Image image(filename);
    long long sum=0;
    for (int x = 0; x < image.width; x++) {
        for (int y = 0; y < image.height; y++) {
          int gray = (image(x, y, 0)+image(x, y, 1) + image(x, y, 2))/3;
          sum +=gray;   
        }
   
    }
      int midpoint = sum/(image.width*image.height);
    for (int x = 0; x < image.width; x++) {
        for (int y = 0; y < image.height; y++) {
        int gray =(image(x, y, 0) +image(x, y, 1) +image(x, y, 2))/3;
        if (gray >=midpoint) {
        image(x, y, 0) = 255;
        image(x, y, 1) = 255;
        image(x, y, 2)=255;
        }
        else {
        image(x, y, 0) = 0;
        image(x, y, 1) = 0;
        image(x, y, 2)=0; 
        }
    }
  } 
    cout << "Enter image name to save new image and specify extention ";
    cin >> filename;
    image.saveImage(filename);

    return 0;
}

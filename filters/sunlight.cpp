#include <iostream>
#include "Image_Class.h"
using namespace std;

int main() {
    string filename;
    cout << "Enter image name to add sunlight effect ";
    cin >> filename;

    Image image(filename);

    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
           int r=int(image(i, j, 0)*1.3);
           int g=int(image(i, j, 1) * 0.95);
           int b=int(image(i, j, 2) * 0.75);
           image(i, j, 0) =min(r,255);
           image(i, j, 1) = min(g,255);
           image(i, j, 2) = min(b,255);

    }}

    cout << "Please enter image name to store new flipped image and specify extension .jpg, .bmp, .png, .tga: /n" ;
    cin >> filename;
    image.saveImage(filename);

    return 0;
}
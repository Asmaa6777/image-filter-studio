#include <iostream>
#include "Image_Class.h"
using namespace std;

int main(){
    string filename;
    cout << "Enter image to be edged ";
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
        }}} 
Image edges(image.width, image.height);

for (int x=0;x<image.width-1;x++){
    for (int y=0; y<image.height-1;y++){
        int current = image(x, y, 0);
        int right = image(x+1, y, 0);
        int down = image(x, y+1, 0);
        if (current!= right || current != down)
            edges(x, y, 0) = edges(x, y, 1) = edges(x, y, 2) = 0; 
        else
            edges(x, y, 0) = edges(x, y, 1) = edges(x, y, 2) = 255; 
    }
}
   cout << "Enter image name to save new image and specify extension ";
    cin >> filename;
    edges.saveImage(filename);

    return 0;
}

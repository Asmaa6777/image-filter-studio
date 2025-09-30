#include <iostream>
using namespace std;
#include "Image_Class.h"

int main() {
    string filename;
    int choice;  
    cout << "Please enter image name to flip: ";
    cin >> filename;
    Image image(filename);
    Image flipped(image.width, image.height);
    int type;
    while (true)
    {
    cout << "Please enter 1 for horizontal Flip & 2 for vertical flip\n";
    cin >> type;
    if (type ==1){
    for (int i = 0; i < image.width/2; i++) {
      for (int j = 0; j < image.height; j++) {
         for (int k = 0; k < 3; ++k) {
         flipped(i,j,k) = image(image.width-1-i,j,k);
         flipped(image.width-1-i,j,k)=image(i,j,k);
      }
    }}
    break;
    }
    else if (type == 2) {
          for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height/2; ++j) {
                for (int k = 0; k < 3; ++k) {
                flipped(i,j,k) = image(i,image.height-1-j,k);
                flipped(i,image.height-j-1,k)=image(i,j,k);  
                }
            }
        }
    break;
    }
    else {
        cout << "Invalid choice! try again.\n";
    } }

    cout << "Please enter image name to store new flipped image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> filename;
    
    flipped.saveImage(filename);
    return 0;
}
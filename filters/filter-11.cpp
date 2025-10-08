#include <iostream>
using namespace std;
#include "Image_Class.h"

 
 

int main() {

    cout << "Pls enter image's name to resize ";
    string filename;
    cin >> filename;
    Image image(filename);
    int type;
    cout << "Pls enter 1 for resizing with new dimensions and 2 for a ratio of increase or decrease\n";
    cin >> type;
    int neww,newh;
    if (type==1){
    cout << "Enter new width\n ";
    cin >> neww;
    cout << "Enter new height\n "; 
    cin >>  newh;
 } 
  else if (type == 2) {
        double ratio;
        cout << "Enter ratio ";
        cin >> ratio;
        neww= int(image.width * ratio);
        newh = int(image.height * ratio);
    }
  else {
    cout <<"invalid entry ,try again\n";
}
Image resized(neww,newh);

    for (int i = 0; i < neww; ++i) {
        for (int j = 0; j < newh; ++j) {
        int x =int(double(i*image.width/neww));  
        int y = int(double(j*image.height/newh));  
            for (int k = 0; k < 3; ++k) {
                 resized(i, j, k)=image(x,y,k);
            }
        }
    }


    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);

    return 0;
}

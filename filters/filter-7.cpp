#include <iostream>
using namespace std;
#include "Image_Class.h"


int main() {
    string filename, answer;
    cout << "Pls enter colored image name to adjust the brightness of: " << endl;
    cin >> filename;
    Image image(filename);
    cout << "Would you like to go 50% brighter or darker?";
    cin >> answer;
    if(answer=="brighter"){
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i,j,k)= 1.5 * image(i,j,k);
                if (image (i,j,k)>255){
                    image(i,j,k)=255; }
                }
               
               }
            }      
        } 
    else if(answer=="darker"){
        for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i,j,k)= 0.5 * image(i,j,k);
                if (image (i,j,k)<0){
                    image(i,j,k)=0; }
                
               }
            }      
        }
    }

    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);

    return 0;
}

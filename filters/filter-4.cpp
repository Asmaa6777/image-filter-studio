#include <iostream>
#include "Image_Class.h"
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string file1, file2;
    cout << "Enter your 1st image: ";
    cin >> file1;
    cout << "Enter your 2nd image: ";
    cin >> file2;
    Image image1(file1);
    Image image2(file2);
    int mergedWidth= max(image1.width, image2.width);
    int mergedHeight= max(image1.height, image2.height);

    Image mergedImage(mergedWidth, mergedHeight);
    for (int i=0;i<mergedWidth;i++){
        for (int j=0;j<mergedHeight;j++){
            for (int k= 0;k<3;k++){
                int pixels=0;
                int count= 0;

                if (i<image1.width && j<image1.height){
                    pixels+=image1(i, j, k);
                    count++;
                }
                if (i<image2.width && j<image2.height){
                    pixels+=image2(i, j, k);
                    count++;
                }

                mergedImage(i, j, k) = (count!=0) ? pixels/count: 0;
            }
        }
    }
    cout << "Enter image name to save new image and specify extension ";
    cin >> filename;
    margedImage.saveImage(filename);
    return 0;
}

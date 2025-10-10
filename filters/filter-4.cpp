#include <iostream>
#include "Image_Class.h"
#include <string>
#include <algorithm>
using namespace std;
 Image merge(Image &image1, Image &image2, int option) {
    if (option == 1) {
        int mergedWidth = max(image1.width, image2.width);
        int mergedHeight = max(image1.height, image2.height);
        Image temp1 = image1;
        Image temp2 = image2;
        
        Image resized1(mergedWidth, mergedHeight);
        Image resized2(mergedWidth, mergedHeight);
        
        // Manually resize using the same logic as your resize function
        for (int i = 0; i < mergedWidth; ++i) {
            for (int j = 0; j < mergedHeight; ++j) {
                int x1 = int(double(i * image1.width / mergedWidth));  
                int y1 = int(double(j * image1.height / mergedHeight));
                int x2 = int(double(i * image2.width / mergedWidth));  
                int y2 = int(double(j * image2.height / mergedHeight));
                
                for (int k = 0; k < 3; ++k) {
                    resized1(i, j, k) = image1(x1, y1, k);
                    resized2(i, j, k) = image2(x2, y2, k);
                }
            }
        }
        
        Image mergedImage(mergedWidth, mergedHeight);
        for (int i = 0; i < mergedWidth; i++) {
            for (int j = 0; j < mergedHeight; j++) {
                for (int k = 0; k < 3; k++) {
                    // Average the pixel values
                    int avg = (resized1(i, j, k) + resized2(i, j, k)) / 2;
                    mergedImage(i, j, k) = avg;
                }
            }
        }
        return mergedImage;
        
    } else if (option == 2) {
        // Option 2: Merge only the common area (your current approach)
        int mergedWidth = min(image1.width, image2.width);
        int mergedHeight = min(image1.height, image2.height);
        
        Image mergedImage(mergedWidth, mergedHeight);
        for (int i = 0; i < mergedWidth; i++) {
            for (int j = 0; j < mergedHeight; j++) {
                for (int k = 0; k < 3; k++) {
                    // Average the pixel values from common area
                    int avg = (image1(i, j, k) + image2(i, j, k)) / 2;
                    mergedImage(i, j, k) = avg;
                }
            }
        }
        return mergedImage;
    }
    
    // Default fallback
    return image1;
}

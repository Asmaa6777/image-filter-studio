#include <iostream>
using namespace std;
#include "Image_Class.h"

int main() {
    string filename;
    cout << "Pls enter colored image name: ";
    cin >> filename;

    cout << "Choose rotation:" << endl;
    cout << "1  for 90 degree clockwise" << endl;
    cout << "2 for 180 degree" << endl;
    cout << "3 for 270 degree clockwise" << endl;
    int choice;
    cin >> choice;

    Image image(filename);
    Image rotated;

    if (choice == 1 || choice == 3) {
        rotated = Image(image.height, image.width); 
    } else {
        rotated = Image(image.width, image.height);
    }

    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; k++) {
                if (choice == 1) {
                    rotated(j, image.width - 1 - i, k) = image(i, j, k);
                } else if (choice == 2) {
                    rotated(image.width - 1 - i, image.height - 1 - j, k) = image(i, j, k);
                } else if (choice == 3) {
                    rotated(image.height - 1 - j, i, k) = image(i, j, k);
                }
            }
        }
    }

    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> filename;

    rotated.saveImage(filename);

    cout << "Image rotated and saved successfully!" << endl;
    return 0;
}

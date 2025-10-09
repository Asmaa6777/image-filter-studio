#include <iostream>
#include <algorithm>
#include "Image_Class.h"
using namespace std;

void infraredFilter(Image &fi, Image &ci) {
    for (int y = 0; y < fi.height; ++y) {
        for (int x = 0; x < fi.width; ++x) {
            int r = fi(x, y, 0);
            int g = fi(x, y, 1);
            int b = fi(x, y, 2);

            int avg = (r + g + b) / 3;

            int newR = min(255, avg + 100);
            int newG = max(0, avg - 50);
            int newB = max(0, avg - 50);

            ci(x, y, 0) = newR;
            ci(x, y, 1) = newG;
            ci(x, y, 2) = newB;
        }
    }
}

int main() {
    string filename;
    cout << "Enter image name: ";
    cin >> filename;

    Image image(filename);
    Image result = image; // copy for output

    infraredFilter(image, result);

    string out;
    cout << "Enter output image name (with extension .png, .jpg...): ";
    cin >> out;
    result.saveImage(out);

    cout << " Infrared filter applied and saved as " << out << endl;
    return 0;
}

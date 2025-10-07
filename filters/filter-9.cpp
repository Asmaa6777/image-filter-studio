#include <iostream>
#include <string>
#include "Image_Class.h"
using namespace std;

int main() {
    string filename;
    cout << "Enter image name: ";
    cin >> filename;

    Image image(filename);
    int width = image.width;
    int height = image.height;
    int frameThickness = max(1, int(width * 0.05));

    int choice;
    cout << "Choose frame style:\n";
    cout << "1 => Simple purple frame\n";
    cout << "2 => Frame with simple زخارف decoration\n";
    cout << "Enter choice: ";
    cin >> choice;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            bool inFrame = (y < frameThickness || y >= height - frameThickness ||
                            x < frameThickness || x >= width - frameThickness);
            if (inFrame) {
                image(y, x, 0) = 180;
                image(y, x, 1) = 0;
                image(y, x, 2) = 120;
            }
        }
    }

    if (choice == 2) {
        int spacing = max(10, frameThickness * 2);
        int decoSize = 4;
        int goldR = 212, goldG = 175, goldB = 55;

        for (int x = frameThickness; x < width - frameThickness; x += spacing) {
            for (int dx = -decoSize; dx <= decoSize; ++dx) {
                for (int dy = -decoSize; dy <= decoSize; ++dy) {
                    if (abs(dx) + abs(dy) < decoSize) {
                        int px = x + dx;
                        int pyTop = frameThickness / 2 + dy;
                        int pyBottom = height - frameThickness / 2 + dy;

                        if (px >= 0 && px < width && pyTop >= 0 && pyTop < height) {
                            image(pyTop, px, 0) = goldR;
                            image(pyTop, px, 1) = goldG;
                            image(pyTop, px, 2) = goldB;
                        }
                        if (px >= 0 && px < width && pyBottom >= 0 && pyBottom < height) {
                            image(pyBottom, px, 0) = goldR;
                            image(pyBottom, px, 1) = goldG;
                            image(pyBottom, px, 2) = goldB;
                        }
                    }
                }
            }
        }

        for (int y = frameThickness; y < height - frameThickness; y += spacing) {
            for (int dx = -decoSize; dx <= decoSize; ++dx) {
                for (int dy = -decoSize; dy <= decoSize; ++dy) {
                    if (abs(dx) + abs(dy) < decoSize) {
                        int pxLeft = frameThickness / 2 + dx;
                        int py = y + dy;
                        int pxRight = width - frameThickness / 2 + dx;

                        if (pxLeft >= 0 && pxLeft < width && py >= 0 && py < height) {
                            image(py, pxLeft, 0) = goldR;
                            image(py, pxLeft, 1) = goldG;
                            image(py, pxLeft, 2) = goldB;
                        }
                        if (pxRight >= 0 && pxRight < width && py >= 0 && py < height) {
                            image(py, pxRight, 0) = goldR;
                            image(py, pxRight, 1) = goldG;
                            image(py, pxRight, 2) = goldB;
                        }
                    }
                }
            }
        }
    }

    string outName;
    cout << "Enter output image name (e.g. result.bmp): ";
    cin >> outName;
    image.saveImage(outName);
    cout << "Frame added and saved as " << outName << endl;
    return 0;
}

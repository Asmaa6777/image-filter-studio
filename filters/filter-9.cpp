
#include <iostream>
#include <string>
#include "Image_Class.h"
using namespace std;

int main() {
    string filename;
    cout << "Enter image name): ";
    cin >> filename;

    Image image(filename);
    int width = image.width;
    int height = image.height;
    int frameThickness = width * 0.05;

    int choice;
    cout << "Choose frame style:\n";
    cout << "1 => Simple purple frame\n";
    cout << "2 => Frame with simple زخارف decoration\n";
    cout << "Enter choice: ";
    cin >> choice;

    // ---- Base frame ----
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            bool inFrame = (y < frameThickness || y >= height - frameThickness ||
                            x < frameThickness || x >= width - frameThickness);
            if (inFrame) {
                image(x, y, 0) = 180; 
                image(x, y, 1) = 0;
                image(x, y, 2) = 120;
            }
        }
    }

    if (choice == 2) {
        int spacing = frameThickness * 3; 
        int decoSize = 4 
        int goldR = 212, goldG = 175, goldB = 55; // gold color

        // Top border
        for (int x = frameThickness; x < width - frameThickness; x += spacing) {
            for (int dx = -decoSize; dx <= decoSize; ++dx) {
                for (int dy = -decoSize; dy <= decoSize; ++dy) {
                    if (abs(dx) + abs(dy) < decoSize) { // diamond shape
                        int px = x + dx;
                        int py = frameThickness / 2 + dy;
                        if (px >= 0 && px < width && py >= 0 && py < height) {
                            image(px, py, 0) = goldR;
                            image(px, py, 1) = goldG;
                            image(px, py, 2) = goldB;
                        }
                    }
                }
            }
        }

        // Bottom border (same pattern)
        for (int x = frameThickness; x < width - frameThickness; x += spacing) {
            for (int dx = -decoSize; dx <= decoSize; ++dx) {
                for (int dy = -decoSize; dy <= decoSize; ++dy) {
                    if (abs(dx) + abs(dy) < decoSize) {
                        int px = x + dx;
                        int py = height - frameThickness / 2 + dy;
                        if (px >= 0 && px < width && py >= 0 && py < height) {
                            image(px, py, 0) = goldR;
                            image(px, py, 1) = goldG;
                            image(px, py, 2) = goldB;
                        }
                    }
                }
            }
        }

        // Left and right borders (vertical version)
        for (int y = frameThickness; y < height - frameThickness; y += spacing) {
            for (int dx = -decoSize; dx <= decoSize; ++dx) {
                for (int dy = -decoSize; dy <= decoSize; ++dy) {
                    if (abs(dx) + abs(dy) < decoSize) {
                        int px1 = frameThickness / 2 + dx;
                        int py1 = y + dy;
                        int px2 = width - frameThickness / 2 + dx;
                        int py2 = y + dy;

                        if (px1 >= 0 && px1 < width && py1 >= 0 && py1 < height) {
                            image(px1, py1, 0) = goldR;
                            image(px1, py1, 1) = goldG;
                            image(px1, py1, 2) = goldB;
                        }
                        if (px2 >= 0 && px2 < width && py2 >= 0 && py2 < height) {
                            image(px2, py2, 0) = goldR;
                            image(px2, py2, 1) = goldG;
                            image(px2, py2, 2) = goldB;
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

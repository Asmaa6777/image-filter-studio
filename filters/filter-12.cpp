#include <iostream>
#include "Image_Class.h"
using namespace std;

void blurImage(Image &real, Image &output) {
    for (int y = 0; y < real.height; ++y) {
        for (int x = 0; x < real.width; ++x) {
            int SR = 0, SG = 0, SB = 0;
            int count = 0;

            for (int dy = -5; dy <= 5; ++dy) {
                for (int dx = -5; dx <= 5; ++dx) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && nx < real.width && ny >= 0 && ny < real.height) {
                        SR += real(nx, ny, 0);
                        SG += real(nx, ny, 1);
                        SB += real(nx, ny, 2);
                        count++;
                    }
                }
            }

            output(x, y, 0) = SR / count;
            output(x, y, 1) = SG / count;
            output(x, y, 2) = SB / count;
        }
    }
}


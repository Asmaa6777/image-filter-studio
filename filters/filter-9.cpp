#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#include "Image_Class.h"

// Function to draw a white frame
void drawWhiteFrame(Image& image, int frameSize) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            if (i < frameSize || i >= image.width - frameSize ||
                j < frameSize || j >= image.height - frameSize) {
                // Set pixel to white
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
        }
    }
}

// Function to draw a black square
void drawSquare(Image& image, int startX, int startY, int size) {
    for (int i = startX; i < startX + size && i < image.width; ++i) {
        for (int j = startY; j < startY + size && j < image.height; ++j) {
            if (i >= 0 && j >= 0) {
                image(i, j, 0) = 0;   // Black
                image(i, j, 1) = 0;
                image(i, j, 2) = 0;
            }
        }
    }
}

// Function to draw a black circle
void drawCircle(Image& image, int centerX, int centerY, int radius) {
    for (int i = centerX - radius; i <= centerX + radius; ++i) {
        for (int j = centerY - radius; j <= centerY + radius; ++j) {
            if (i >= 0 && i < image.width && j >= 0 && j < image.height) {
                double distance = sqrt((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY));
                if (distance <= radius) {
                    image(i, j, 0) = 0;   // Black
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 0;
                }
            }
        }
    }
}

// Function to draw a black triangle
void drawTriangle(Image& image, int topX, int topY, int baseSize) {
    int height = baseSize;
    for (int j = topY; j < topY + height && j < image.height; ++j) {
        int rowWidth = (j - topY) * 2 + 1;
        int startX = topX - (rowWidth / 2);
        for (int i = startX; i < startX + rowWidth && i < image.width; ++i) {
            if (i >= 0 && j >= 0) {
                image(i, j, 0) = 0;   // Black
                image(i, j, 1) = 0;
                image(i, j, 2) = 0;
            }
        }
    }
}

// Function to add decorative shapes to top-left corner
void decorateTopLeft(Image& image, int frameSize) {
    int cornerX = frameSize / 2;
    int cornerY = frameSize / 2;
    
    // Square in top-left area
    drawSquare(image, 10, 10, 15);
    
    // Circle near the square
    drawCircle(image, 35, 25, 8);
    
    // Triangle pointing inward
    drawTriangle(image, 25, 35, 12);
    
    // Additional small square
    drawSquare(image, 15, 30, 8);
}

// Function to add decorative shapes to top-right corner
void decorateTopRight(Image& image, int frameSize) {
    int cornerX = image.width - frameSize / 2;
    int cornerY = frameSize / 2;
    
    // Square in top-right area
    drawSquare(image, image.width - 25, 10, 15);
    
    // Circle near the square
    drawCircle(image, image.width - 35, 25, 8);
    
    // Triangle pointing inward
    drawTriangle(image, image.width - 25, 35, 12);
    
    // Additional small square
    drawSquare(image, image.width - 23, 30, 8);
}

// Function to add decorative shapes to bottom-left corner
void decorateBottomLeft(Image& image, int frameSize) {
    int cornerX = frameSize / 2;
    int cornerY = image.height - frameSize / 2;
    
    // Square in bottom-left area
    drawSquare(image, 10, image.height - 25, 15);
    
    // Circle near the square
    drawCircle(image, 35, image.height - 25, 8);
    
    // Triangle pointing inward (upside down)
    for (int j = image.height - 35; j > image.height - 35 - 12 && j >= 0; --j) {
        int rowWidth = (image.height - 35 - j) * 2 + 1;
        int startX = 25 - (rowWidth / 2);
        for (int i = startX; i < startX + rowWidth && i < image.width; ++i) {
            if (i >= 0) {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 0;
            }
        }
    }
    
    // Additional small square
    drawSquare(image, 15, image.height - 38, 8);
}

// Function to add decorative shapes to bottom-right corner
void decorateBottomRight(Image& image, int frameSize) {
    int cornerX = image.width - frameSize / 2;
    int cornerY = image.height - frameSize / 2;
    
    // Square in bottom-right area
    drawSquare(image, image.width - 25, image.height - 25, 15);
    
    // Circle near the square
    drawCircle(image, image.width - 35, image.height - 25, 8);
    
    // Triangle pointing inward (upside down)
    for (int j = image.height - 35; j > image.height - 35 - 12 && j >= 0; --j) {
        int rowWidth = (image.height - 35 - j) * 2 + 1;
        int startX = image.width - 25 - (rowWidth / 2);
        for (int i = startX; i < startX + rowWidth && i < image.width; ++i) {
            if (i >= 0) {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 0;
            }
        }
    }
    
    // Additional small square
    drawSquare(image, image.width - 23, image.height - 38, 8);
}

int main() {
    string filename;
    cout << "Please enter colored image name to add a frame: ";
    cin >> filename;

    // Load the image
    Image image(filename);
    
    // Add white frame with 40 pixel thickness
    int frameSize = 40;
    cout << "Adding white frame with thickness of " << frameSize << " pixels..." << endl;
    drawWhiteFrame(image, frameSize);
    
    // Add decorative shapes to all four corners
    cout << "Adding decorative black shapes to corners..." << endl;
    decorateTopLeft(image, frameSize);
    decorateTopRight(image, frameSize);
    decorateBottomLeft(image, frameSize);
    decorateBottomRight(image, frameSize);
    
    // Save the modified image
    cout << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> filename;
    
    image.saveImage(filename);
    cout << "Modified image saved as: " << filename << endl;

    return 0;
}
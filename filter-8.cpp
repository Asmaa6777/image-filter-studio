#include <iostream>
#include <algorithm>
#include "Image_Class.h"
#include <cctype>

using namespace std;

int main() {
    string filename;
    cout << "Please enter the photo's name to be cropped: ";
    cin >> filename;
    Image image(filename);
    long x, y, w, h;

        cout << "Enter starting leftmost point\n ";
        cin >> x;
        cout << "Enter starting upper point\n ";
        cin >> y;
        cout << "Enter width of crop:\n ";
        cin >> w;
        cout << "Enter height of crop:\n ";
        cin >> h;   

    Image cropped(w, h);
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < 3; k++) {
                cropped(i, j, k) = image(x + i, y + j, k);
            }}}
    string replace ;
    cout << "Replace the original image? enter yes or no ";
    while (true) {
        cin >> replace;
        for (char &c:replace) 
        c=tolower(c);
        if (replace == "yes") {
            image = cropped;
            image.saveImage(filename);
            cout << "Your image is now cropped and saved in " << filename << endl;
            break;
        } 
        else if (replace == "no") {
            string outname;
            cout << "Please enter image name to store new image (and specify extension): ";
            cin >> outname;
            cropped.saveImage(outname);
            cout << "Your cropped image is now saved in " << outname << endl;
            break;
        }
        else 
            cout << "Invalid input. Please enter yes or no: ";     
    }

    return 0;
}

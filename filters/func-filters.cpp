#include <iostream>
using namespace std;
#include "Image_Class.h"


void grayscale(Image &image,string &filename){
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int avg = 0;  
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);  
            }

            avg /= 3; 
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

}



void BlackandWhite(Image &image,string &filename){
    long long sum=0;
    for (int x = 0; x < image.width; x++) {
        for (int y = 0; y < image.height; y++) {
          int gray = (image(x, y, 0)+image(x, y, 1) + image(x, y, 2))/3;
          sum +=gray;   
        }
   
    }
      int midpoint = sum/(image.width*image.height);
    for (int x = 0; x < image.width; x++) {
        for (int y = 0; y < image.height; y++) {
        int gray =(image(x, y, 0) +image(x, y, 1) +image(x, y, 2))/3;
        if (gray >=midpoint) {
        image(x, y, 0) = 255;
        image(x, y, 1) = 255;
        image(x, y, 2)=255;
        }
        else {
        image(x, y, 0) = 0;
        image(x, y, 1) = 0;
        image(x, y, 2)=0; 
        }
    }
  } 
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

}





    void invert_image(Image &image,string &filename){
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i,j,k)= 255 - image(i,j,k);
                
               }
            }      
        }

    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
}




void flip_image(Image &image,string &filename,int type){
    Image flipped(image.width, image.height);
    if (type ==1){
    for (int i = 0; i < image.width/2; i++) {
      for (int j = 0; j < image.height; j++) {
         for (int k = 0; k < 3; ++k) {
         flipped(i,j,k) = image(image.width-1-i,j,k);
         flipped(image.width-1-i,j,k)=image(i,j,k);
      }
    }}
    }
    else if (type == 2) {
          for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height/2; ++j) {
                for (int k = 0; k < 3; ++k) {
                flipped(i,j,k) = image(i,image.height-1-j,k);
                flipped(i,image.height-j-1,k)=image(i,j,k);  
                }
            }
        }
    }
    cout << "Pls enter image name to store new flipped image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
}




void rotate_image(Image &image,string &filename,int choice){
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
}




void Darken_Lighten_Image(Image &image,string &filename,string answer){
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
}




void crop_image(Image &image,string &filename,long x, long y, long w, long h){
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
}
   

void resize (Image &image,string &filename){
    cout << "Pls enter image's name to resize ";
    cin >> filename;
    int type;
    cout << "Pls enter 1 for resizing with new dimensions and 2 for a ratio of increase or decrease\n";
    cin >> type;
    int neww,newh;
    if (type==1){
    cout << "Enter new width\n ";
    cin >> neww;
    cout << "Enter new height\n "; 
    cin >>  newh;
 } 
  else if (type == 2) {
        double ratio;
        cout << "Enter ratio ";
        cin >> ratio;
        neww= int(image.width * ratio);
        newh = int(image.height * ratio);
    }
  else {
    cout <<"invalid entry ,try again\n";
}
Image resized(neww,newh);

    for (int i = 0; i < neww; ++i) {
        for (int j = 0; j < newh; ++j) {
        int x =int(double(i*image.width/neww));  
        int y = int(double(j*image.height/newh));  
            for (int k = 0; k < 3; ++k) {
                 resized(i, j, k)=image(x,y,k);
            }
        }
    }
    image=resized;
}


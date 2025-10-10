/** OOP Assignment 1 Phase 2
 * FCAI Cairo University
 * contains the menu for 14 filters ,image loading and saving options.
 * Course Instructor: Dr Mohamed El-Ramely ,
 * @date : 10/10/2025
 * Work breakdown
 * Mariam Sherif - 20240789 - (filters 1,4,7,10 )
 * Arwa Bashier -20243065 - (filters 2,5,8,11 + bonus filter 13)
 * Asmaa Farouq - 20243081 (filters 3,6,9,12 + bonus filter 17+ demo video)
 * Menu was done by both Asmaa & Arwa
 * document : https://docs.google.com/document/d/1UYLykso-yHuRdV3F4WztKsEHK-XYHJecpTrOFiHUlo0/edit?usp=sharing
 * demo : https://drive.google.com/file/d/1i3sS42kyV52KnPmVTQUvyDUtb_ZjtL6v/view?usp=sharing
 */

#include <iostream>
using namespace std;
#include "Image_Class.h" 
#include <cctype>
#include<algorithm>
#include <cmath>    
#include <string>   

//functions for filters
// filter 1: grayscale conversion

void grayscale(Image &image){
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
}

//filter 2: black&white conversion:

void BlackandWhite(Image &image){
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
  } }

//filter 3: Invert images
   void invert_image(Image &image){
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i,j,k)= 255 - image(i,j,k);

               }
            }      
        }}
// filter 11 : resize
// i put it  here because it is used in the next filter (merge filter)
Image resize(Image &image,int neww,int newh) {

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

    return resized;
}
//filter 4: Merge images

Image merge(Image &image1, Image &image2, int option) {
    Image resized1, resized2;
    int mergedWidth, mergedHeight;

    if (option == 1) {       
        mergedWidth = max(image1.width, image2.width);
        mergedHeight = max(image1.height, image2.height);
        resized1 = resize(image1, mergedWidth, mergedHeight);
        resized2 = resize(image2, mergedWidth, mergedHeight);
    }
    else if (option == 2) {
      
        mergedWidth = min(image1.width, image2.width);
        mergedHeight = min(image1.height, image2.height);
        resized1 = image1;
        resized2 = image2;
    }

    Image mergedImage(mergedWidth, mergedHeight);
    for (int i = 0; i < mergedWidth; i++) {
        for (int j = 0; j < mergedHeight; j++) {
            for (int k = 0; k < 3; k++) {
                int avg = (resized1(i, j, k) + resized2(i, j, k)) / 2;
                mergedImage(i, j, k) = avg;
            }
        }
    }
    return mergedImage;
}

// Filter 5: flip images 
void flip_image(Image &image, int type) {
    Image flipped(image.width, image.height);

    if (type == 1) { 
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < 3; k++) {
                    flipped(i, j, k) = image(image.width - 1 - i, j, k);
                }
            }
        }
    } 
    else if (type == 2) { 
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < 3; k++) {
                    flipped(i, j, k) = image(i, image.height - 1 - j, k);
                }
            }
        }
    }
    image =flipped;
}


// Filter 6: Rotate images 
void rotate_image(Image &image, int choice) {
    Image rotated;

    if (choice == 1 || choice == 3) { // 90° or 270° rotation
        rotated = Image(image.height, image.width); 
    } else { 
        rotated = Image(image.width, image.height);
    }
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; k++) {
                if (choice == 1) { // 90° 
                    rotated(j, image.width - 1 - i, k) = image(i, j, k);
                } else if (choice == 2) { // 180°
                    rotated(image.width - 1 - i, image.height - 1 - j, k) = image(i, j, k);
                } else if (choice == 3) { // 270° 
                    rotated(image.height - 1 - j, i, k) = image(i, j, k);
                }
            }
        }
    }
        image = rotated; 
}

//filter 7 : Adjust brightness
void Darken_Lighten_Image(Image &image,int answer){
    if(answer==1){
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i,j,k)= min(int(1.5*image(i,j,k)),255);
                  }
                }

               }
            }      
        
    else if(answer==2){
        for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i,j,k)=max(int(0.5*image(i,j,k)),0);

               }
            }      
        }
    }
}
//filter 8 : crop images
void crop(Image &image,long x, long y, long w, long h){
    Image cropped(w, h);
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < 3; k++) {
                cropped(i, j, k) = image(x + i, y + j, k);
            }}}
    image = cropped;
    }

// filter 9 : add frame to images
 void frame(Image &image, int c) {
    int width = image.width;
    int height = image.height;
    int frameThickness = max(1, int(width * 0.05));

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

    if (c == 2) {
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
                            image(px, pyTop, 0) = goldR;
                            image(px, pyTop, 1) = goldG;
                            image(px, pyTop, 2) = goldB;
                        }
                        if (px >= 0 && px < width && pyBottom >= 0 && pyBottom < height) {
                            image(px, pyBottom, 0) = goldR;
                            image(px, pyBottom, 1) = goldG;
                            image(px, pyBottom, 2) = goldB;
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
                            image(pxLeft, py, 0) = goldR;
                            image(pxLeft, py, 1) = goldG;
                            image(pxLeft, py, 2) = goldB;
                        }
                        if (pxRight >= 0 && pxRight < width && py >= 0 && py < height) {
                            image(pxRight, py, 0) = goldR;
                            image(pxRight, py, 1) = goldG;
                            image(pxRight, py, 2) = goldB;
                        }
                    }
                }
            }
        }
    }
}
//filter 10: Detect Image Edges
void detect_edge(Image &image){
 BlackandWhite(image);
 Image edges(image.width, image.height);

for (int x=0;x<image.width-1;x++){
    for (int y=0; y<image.height-1;y++){
        int current = image(x, y, 0);
        int right = image(x+1, y, 0);
        int down = image(x, y+1, 0);
        if (current!= right || current != down)
            edges(x, y, 0) = edges(x, y, 1) = edges(x, y, 2) = 0; 
        else
            edges(x, y, 0) = edges(x, y, 1) = edges(x, y, 2) = 255; 
    }

}
 image = edges;
}

//filter 12: Blur Images

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

//filter 13 sunlight effect 
 void sunlight(Image &image){
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
           int r=int(image(i, j, 0)*1.3);
           int g=int(image(i, j, 1) * 0.95);
           int b=int(image(i, j, 2) * 0.75);
           image(i, j, 0) =min(r,255);
           image(i, j, 1) = min(g,255);
           image(i, j, 2) = min(b,255);

    }}}

//filter 14 : infrared effect:

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


//helper function for saving after each filter

void save(Image &image, string &filename) {
    cout << "Do you want to save the current image? yes or no\n";
    string s;
    cin >> s;
    for (char &c : s) c = tolower(c);

    if (s== "yes") {
        cout << "Do you want to save it in the same file? enter yes or no\n";
        string same;
        cin >> same;
        for (char &c : same) c = tolower(c);

        if (same == "yes") {
            image.saveImage(filename);
            cout << "Image saved in " << filename << endl;
        } else {
            cout <<"enter filename to save new image and specify extention\n ";
            string newfile;
            cin >> newfile;
            image.saveImage(newfile);
            cout << "Image saved in " << newfile << endl;
        }
    }
}

int main(){
string current;
 cout << "Pls enter image's name to start\n";
 cin >> current;
 Image image(current);
 bool running=true;

  while (running) {

    cout << "\nPlease choose one of the following options by entering the corresponding number\n";
    cout << "1-Load a new image\n2-Save current image\n3-Filter 1 // Gray scale conversion\n";
    cout << "4-Filter 2 // Black & White\n5-Filter 3 // Invert Filter\n";
    cout << "6-Filter 4 // merge Image\n7-Filter 5 // Flip Images\n";
    cout << "8-Filter 6 // Rotate\n9-Filter 7 // Lighten or darken image\n";
    cout << "10-Filter 8 // crop\n11-Filter 9 // add frame\n";
    cout << "12-Filter 10 // detect iamge edges\n13-Filter 11 // resize\n";
    cout << "14-Filter 12 // Blur\n15-Filter 13 // Sunlight effect\n";
    cout << "16-Filter 14 // infrared\n17-Exit\n";

        int choice;
        cin >> choice;
        switch (choice)
 {
 case 1:{
    save(image,current);
    cout << "enter new image's name to load\n";
    string newfile;
    cin >> newfile;
    image = Image(newfile); 
    current = newfile;
    break;
}

  case 2:{
    save(image,current);
   break;}

   case 3:{
   grayscale(image);
   save(image,current);
   break;}

   case 4:{
    BlackandWhite(image);
    save(image,current);
   break;}

   case 5:{
    invert_image(image);
    save(image,current);
   break;}

   case 6:{
    cout <<"please enter the second image that you want to merge with the current image\n";\
    string file2;
    cin >> file2;
    Image image2(file2);
    int opt;
    cout <<"enter 1 for maximum size merge and 2 for common area merge\n";
    cin >> opt;
    image=merge(image,image2,opt);
    save(image,current);
    break;
   } 
    case 7:{
    cout<<"Do you want to flip the image horizontally or vertically?horizontal=1, vertical=2\n";
    int s;
    cin >>s;
    flip_image(image,s);
    save(image,current);
    break;}

case 8:{
    cout<<"Do you want to rotate the image 90=1 /180=2/270=3?\n";
    int angle;
    cin >>angle;
    rotate_image(image,angle);
    save(image,current);
   break;}

   case 9:{
    cout <<"Do you want to darken or lighten the image? 1 = lighten, 2 = darken\n";
    int s;
    cin >>s;
    Darken_Lighten_Image(image,s);
    save(image,current);
   break;}
  case 10:{
  long x, y, w, h;  

        cout << "Enter starting leftmost point\n (must be positive) ";
        cin >> x;
        cout << "Enter starting upper point\n (must be positive) ";
        cin >> y;
        cout << "Enter width of crop(keep in mind the image width is : "<< image.width <<endl;
        cin >> w;
        cout << "Enter height of crop(keep in mind the image height is : "<< image.height <<endl;
        cin >> h;   
        crop(image,x,y,w,h);
        save(image,current);
   break;}

    case 11:{
    int c;
    cout << "Choose frame style:\n";
    cout << "1 => Simple purple frame\n";
    cout << "2 => Frame with simple decoration\n";
    cout << "Enter choice: ";
    cin >> c;
    frame (image,c);
    save(image,current);
   break;
   }

   case 12:{
    detect_edge(image);
    save(image,current);
   break;
   }
   case 13:{
    cout << "Pls enter 1 for resizing with new dimensions and 2 for a ratio of increase or decrease\n";
    int type;
    int neww,newh;
    cin >> type; 
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
    image = resize(image,neww,newh);
    save(image,current);
    break;
   }
   case 14: {
    Image output(image.width,image.height);
    blurImage(image,output);
    image=output; 
    save(image,current);
   break;
   }
   case 15:
   {
    sunlight(image);
    save(image,current);
    break; 
   }
   case 16:
   {
    Image result(image.width,image.height);
    infraredFilter(image,result);
    image=result;
    save(image,current);
    break;
   }
   case 17:{
    save(image,current);
    running=false;
   break;
}

 default:{
 cout <<"Invalid input try again!\n";
    break;   
 }
 
 }
 }
}
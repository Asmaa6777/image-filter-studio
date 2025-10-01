/** OOP Assignment 1 Phase 1
 * FCAI Cairo University
 * contains the menu for filters ,image loading and saving options,
 * Course Instructor: Dr Mohamed El-Ramely ,
 * @date : 30/9/2025
 * Mariam Sherif - 20240789 (filters 1,7)
 * Arwa Bashier -20243065 (filters 2,5)
 * Asmaa Farouq - 20243081 (filters 3,6)
 */

#include <iostream>
using namespace std;
#include "Image_Class.h" 
#include <cctype>

//functions for filters
// filter 1: grayscale conversion

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
}

//filter 2: black&white conversion:

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
  } }

  //filter 3: Invert images
   void invert_image(Image &image,string &filename){
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i,j,k)= 255 - image(i,j,k);
                
               }
            }      
        }}
        
//filter 4: Adjust brightness
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
}
  
// Filter 5: flip images 
void flip_image(Image &image, string &filename, int type) {
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
    
    // Copy flipped image back to original
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; k++) {
                image(i, j, k) = flipped(i, j, k);
            }
        }
    }
}


// Filter 6: Rotate images 
void rotate_image(Image &image, string &filename, int choice) {
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
    cout << "1- Load a new image\n2- Save current image\n3- Filter 1 // Gray scale conversion\n";
    cout << "4- Filter 2 // Black & White\n5- Filter 3 // Invert Filter\n";
    cout << "6- Filter 4 // Darken and Lighten Image\n7- Filter 5 // Flip Images\n";
    cout << "8- Filter 6 // Rotate\n9- Exit\n";

        int choice;
        cin >> choice;
        switch (choice)
 {
 case 1:{
    cout <<"Do you want to save the current image? enter yes or no\n";
    string s;
    cin >> s; 
    for (char &c : s) c = tolower(c);
    if(s == "yes") {
        image.saveImage(current);
        cout << "Image saved in " << current << endl;
    }
    cout << "enter new image's name to load\n";
    string newfile;
    cin >> newfile;
    image = Image(newfile); // Use assignment, not local declaration
    current = newfile;
    break;
}

  case 2:{
    save(image,current);
   break;}

   case 3:{
   grayscale(image,current);
   save(image,current);
   break;}

   case 4:{
    BlackandWhite(image,current);
    save(image,current);
   break;}

   case 5:{
    invert_image(image,current);
    save(image,current);
   break;}

   case 6:{
    cout <<"Do you want to darker or lighter the image? enter darker or lighter\n";
    string s;
    cin >>s;
    Darken_Lighten_Image(image,current, s);
    save(image,current);
   break;}

   case 7:{
    cout<<"Do you want to flip the image horizontally or vertically?horizontal=1, vertical=2\n";
    int s;
    cin >>s;
    flip_image(image,current, s);
    save(image,current);
    break;}

   case 8:{
    cout<<"Do you want to rotate the image 90=1 /180=2/270=3?\n";
    int angle;
    cin >>angle;
    rotate_image(image,current, angle);
    save(image,current);
   break;}

   case 9:{
    save(image,current);
    running=false;
   break;}
 
 default:
 cout <<"Invalid input try again!\n";
    break;
 }
 }
}
#include <iostream>
using namespace std;
#include "Image_Class.h" 
#include <cctype>

//functions for filters 
// grayscale funcyion
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

    cin >> filename;
    image.saveImage(filename);
}

    // Black & white function
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

    cin >> filename;
    image.saveImage(filename);
}

int main(){
string current;
 cout << "Pls enter image's name to load  ";
 cin >> current;
 Image image(current);
 bool running=true;
 while (running){
 cout << "Please choose one of the following options by entering the corresponding number\n";
 cout <<"1- Load a new image\n2- Save current image\n3- Filter 1 // Gray scale conversion\n";
 cout <<"4- Filter 2 // Black & White\n5- Filter 3 // Invert Filter\n";
 cout <<"6- Filter 4 // Merge Images\n7- Filter 5 // Flip Images\n";
 cout <<"8- Filter 6 // Rotate Image\n9- Exit\n" ;
 int choice;
 cin >> choice;
 switch (choice)
 {
 case 1:{
   cout <<"Do you want to save the current? enter yes or no\n";
   string s;
   cin >>s; 
   for (char &c:s) c=tolower(c);
   if(s == "yes") {
   image.saveImage(current);
   cout <<"Image saved in"<< current<<endl;
   break;
   }
   cout <<"enter new image's name to load\n";
   string newfile;
   cin>>newfile;
   Image image(newfile);
   break;
 }
 case 2:{
   image.saveImage(current);
   cout <<"Image saved in"<< current;
   break;
 }
  case 3:{
   grayscale(image,current);
   break;
 }
   case 4:{
    BlackandWhite(image,current);
   break;
 }
   case 6:{

   break;
 }
   case 7:{
    
   break;
 }
   case 8:{
    
   break;
 }
   case 9:{
    cout <<"Do you want to save the current  image before you exit? enter yes or no\n";
    string s;
    cin >>s; 
    for (char &c:s) c=tolower(c);
    if(s =="yes") {
    image.saveImage(current);
    cout <<"Image saved in"<< current<<endl;
    running=false;
   }
   break;
 }
 
 default:
    break;
 }
 }
}
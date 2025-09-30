/** OOP Assignment 1 Phase 1
 * FCAI Cairo University
 * contains the menu for filters ,image loading and saving options,
 * Course Instroctor : Dr Mohamed El-Ramely ,
 * @date : 30/9/2025
 * Mariam Sherif - 20240789 (filters 1,7)
 * Arwa Bashier -20243065 (filters 2,5)
 * Asmaa Farouq - 20243081 (filters 3,6)
 */

#include <iostream>
using namespace std;
#include "Image_Class.h" 
#include <cctype>
#include "filters.h"

int main(){
string current;
 cout << "Pls enter image's name to load  ";
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
  image = Image(newfile);
   break;}

  case 2:{
   image.saveImage(current);
   cout <<"Image saved in"<< current;
   break;}

   case 3:{
   grayscale(image,current);
   break;}

   case 4:{
    BlackandWhite(image,current);
   break;}

   case 5:{
    invert_image(image,current);
   break;}

   case 6:{
    cout <<"Do you want to darken or lighten the image? enter darken or lighten\n";
    string s;
    cin >>s;
    Darken_Lighten_Image(image,current, s);
   break;}

   case 7:{
    cout<<"Do you want to flip the image horizontally or vertically?0 = horizontal, 1 = vertical\n";
    int s;
    cin >>s;
    flip_image(image,current, s);
    break;}

   case 8:{
    cout<<"Do you want to rotate the image 90/180/270?\n";
    int angle;
    cin >>angle;
    rotate_image(image,current, angle);
   break;}

   case 9:{
    cout <<"Do you want to save the current image before you exit? enter yes or no\n";
    string s;
    cin >>s; 
    if (s == "yes"){
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    image.saveImage(current);
    cout <<"Image saved in"<< current<<endl;
    running=false;
    }
    running=false;
   break;}
 
 default:
    break;
 }
 }
}
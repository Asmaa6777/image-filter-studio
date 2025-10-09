# 📸 Image Processing Tool (CS213 – OOP Programming Assignment)

This project is an **image processing tool** built in **C++** for CS213: OOP Programming (Assignment 1).
The program loads an image, allows the user to apply different filters, and then save the processed image.

The tool supports **four image formats**: `.jpg`, `.png`, `.bmp`, and `.tga`.
It uses the provided **`Image_Class.h`** library (which wraps `stb_image.h` and `stb_image_write.h`) for image loading and saving.

---

## 🚀 Features

* Menu-driven console program
* Load any image of supported formats
* Apply different filters (grayscale, invert, blur, edge detection, etc.)
* Save results with custom filenames
* Continuous menu loop until user chooses **Exit**

---

## 🛠 Filters Implemented

Each filter is implemented in a **separate function**.

### ✅ Filters

* [x] Grayscale
* [x] Invert colors
* [x] Black & White threshold
* [x] Blur (Box blur)
* [x] Brightness adjustment
* [x] Edge detection
* [ ] More filters to be added for Hero/Beast/Winged Dragon level

---

## 📂 Project Structure

```
📦 ImageProcessingTool
 ┣ 📂 Filters.cpp           # Main menu + program loop
 ┣ 📜 Image_Class.h      # Provided library wrapper
 ┣ 📜 stb_image.h        # Image loading
 ┣ 📜 stb_image_write.h  # Image saving
 ┣ 📂 images/            # Test images
 ┗ 📜 README.md          # This file
```

---

## 📊 System Diagram

The program structure is modular. Each filter is its own function.

```
                ┌──────────────┐
                │ Filters.cpp  │
                └──────┬───────┘
                       │
        ┌──────────────┴──────────────┐
        │                             │
 ┌──────▼───────┐              ┌──────▼───────┐
 │  loadImage() │              │  saveImage() │
 └──────┬───────┘              └──────┬───────┘
        │                             │
 ┌──────▼──────────────────────────────────────┐
 │                   Filters                   │
 ├──────────────────┬──────────────────────────┤
 │  grayscale()     │  invert()                │
 │  threshold()     │  blur()                  │
 │  brightness()    │  edgeDetection()         │
 └──────────────────┴──────────────────────────┘
```

## ▶️ Usage

1. Compile the program:

   ```bash
   g++ main.cpp -o ImageTool
   ```
2. Run the program:

   ```bash
   ./ImageTool
   ```
3. Follow the menu:

   * Load image
   * Choose a filter
   * Save or continue
   * Exit when finished

---

## 👥 Team

* Asmaa Farouq 
* Arwaa Bashir  
* Mariam Sherif

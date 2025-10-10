# 📸 Image Processing Tool (CS213 – OOP Programming Assignment)

This project is an **image processing tool** built in **C++** for CS213: OOP Programming (Assignment 1).
The program loads an image, allows the user to apply different filters, and then save the processed image.

The tool supports **four image formats**: `.jpg`, `.png`, `.bmp`, and `.tga`.
It uses the provided **`Image_Class.h`** library (which wraps `stb_image.h` and `stb_image_write.h`) for image loading and saving.

---

## 🧪 Filters Description

| # | Filter Name | Function |
|---|--------------|-----------|
| 1 | **Grayscale** | Converts the image to shades of gray. |
| 2 | **Black & White** | Converts the image to pure black and white using midpoint threshold. |
| 3 | **Invert** | Inverts all pixel colors (negative effect). |
| 4 | **Merge** | Combines two images (either full size or common area). |
| 5 | **Flip** | Flips the image horizontally or vertically. |
| 6 | **Rotate** | Rotates the image by 90°, 180°, or 270°. |
| 7 | **Brightness** | Lightens or darkens the image by a fixed factor. |
| 8 | **Crop** | Cuts out a rectangular portion of the image. |
| 9 | **Frame** | Adds a colored frame with optional decorations. |
| 10 | **Detect Edges** | Detects edges using brightness difference. |
| 11 | **Resize** | Resizes image dimensions manually or by ratio. |
| 12 | **Blur** | Softens the image by averaging surrounding pixels. |
| 13 | **Sunlight (Bonus)** | Adds a warm sunlight effect. |
| 14 | **Infrared (Bonus)** | Simulates an infrared camera color filter. |

---

## 💾 Save Function Behavior

After each filter:
- The user is prompted whether to save.  
- You can choose:
  - **Same filename** → overwrite current image.  
  - **New filename** → save as a new file.  

---

## 🧰 Dependencies

- C++ Standard Library (`<iostream>`, `<cmath>`, `<algorithm>`, `<string>`)
- Custom header file: `Image_Class.h`

Make sure the header file and your image files are in the same directory as your executable.

---

## 🧾 Example Run



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
## 🚀 Features

* Menu-driven console program
* Load any image of supported formats
* Apply different filters (grayscale, invert, blur, edge detection, etc.)
* Save results with custom filenames
* Continuous menu loop until user chooses **Exit**

---

## 🛠 Filters Implemented

Each filter is implemented in a **separate function**.

                     +----------------------------------+
                     |         IMAGE EDITOR MENU        |
                     +----------------------------------+
                                  |
                                  v
       +-------------------------------------------------------+
       |  1. Load New Image   |  2. Save Image   | 17. Exit    |
       +-------------------------------------------------------+
                                  |
                                  v
       +-------------------------------------------------------+
       |                 FILTERS AVAILABLE (3 → 16)             |
       +-------------------------------------------------------+
                                  |
                                  v
      ┌───────────────────────────────────────────────────────────┐
      │  3. Grayscale                4. Black & White             │
      │  5. Invert Colors            6. Merge Two Images          │
      │  7. Flip Image               8. Rotate Image              │
      │  9. Brightness Adjust        10. Crop Image               │
      │ 11. Add Frame                12. Detect Edges             │
      │ 13. Resize Image             14. Blur Image               │
      │ 15. Sunlight Effect          16. Infrared Effect          │
      └───────────────────────────────────────────────────────────┘
                                  |
                                  v
       +-------------------------------------------------------+
       |            FILTER OPTIONS (User Inputs)               |
       +-------------------------------------------------------+

            6. Merge → (1) Max size  | (2) Common area
            7. Flip  → (1) Horizontal | (2) Vertical
            8. Rotate → (1) 90° | (2) 180° | (3) 270°
            9. Brightness → (1) Lighten | (2) Darken
           10. Crop → Enter (x, y, width, height)
           11. Frame → (1) Purple | (2) Gold decorated
           13. Resize → (1) New dimensions | (2) Ratio scale
           14. Blur → Automatically averages nearby pixels


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

JPEG Noise/Blur Reduction

A simple project that converts a JPEG to PPM, applies a blur effect in C, and can optionally convert the result back to JPEG. This project demonstrates how to bridge image processing between Python (for conversion) and C (for pixel-level manipulation).

Features

Convert a JPEG image to PPM (using Python & Pillow)

Apply a blur effect in C (box blur using a 3x3 neighborhood)

Save final output as a blurred PPM

Folder Structure

JPEG-Noise-Reduction/
|-- convertJPG.py      # Python script (JPEG → PPM)
|-- driverJPEG.c       # Main C program (handles I/O and function calls)
|-- ppmBlur.c          # All PPM handling functions (reading, writing, blurring)
|-- ppm.h              # Header file for struct definitions & function prototypes
|-- input.jpg          # Example input image (JPEG)
|-- input.ppm          # Generated PPM from `input.jpg`
|-- output.ppm         # Blurred result
|-- venv/              # (Optional) Python virtual environment
|-- README.md          # This file


Requirements

C Compiler (e.g., gcc)

Python 3 and Pillow library

pip install pillow

(Optional) ImageMagick if you want to view/convert PPM files easily.

Steps For Getting Started

1️⃣ Clone This Repo (or download the ZIP):

git clone https://github.com/jenniferjtk/JPEG-Noise-Reduction.git
cd JPEG-Noise-Reduction

2️⃣ Install Python Pillow:

pip install pillow

3️⃣ Convert JPEG → PPM:

python3 convertJPG.py input.jpg

This will create input.ppm.

4️⃣ Compile the C Program:

gcc -o blurred driverJPEG.c ppmBlur.c -Wall

5️⃣ Run the Blur:

./blurred input.ppm output.ppm

This reads input.ppm and creates a blurred image output.ppm.

Screenshots

You can view an example of this program in the root directory under input.jpg and output.jpg

How It Works

1️⃣ Python Conversion

Uses Pillow to read the JPEG and store as a PPM.

2️⃣ C Blur

applyBlur() reads each pixel in a 3×3 neighborhood, summing color values and averaging them. Writes the blurred data to output.ppm.

Contact

Name: Jennifer Johnson
Email: jgj4@clemson.edu

Enjoy blurring your images in C! 


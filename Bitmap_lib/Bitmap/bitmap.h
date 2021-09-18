/*Class: Bitmap
 *  holds an image from a file in '.BMP' format
*/

#ifndef BITMAP_TEST_BITMAP_H
#define BITMAP_TEST_BITMAP_H
#include <iostream>
#include <string>
#include "../Pixel/pixelmap.h"
#include "Bitmap_Headers/bitmapheaders.h"
/*TODO (new):
 * override R, G, B, H, S, L setter and getter functions in HSL & RGB
 * look over Pixel, PixelMap, Color, RGB, & HSL to potentially add helper functions and operators, optimize a bit, and practice SOLID OOP principles
 * implement Selection object to act as a indexable subspace within the PixelMap object to be able to do manipulation functions
 * implement manipulation functions as function pointers to be applied to all Pixels of a PixelMap or Selection in a PixelMap
 * implement Masks as a wrapper for modification & selection functionality, implemented as a stack ultimately in the main program for undo/redo functionality
 * implement a proper main Shell
 * implement drawing shapes?
*/

 /* TODO (old):
 - implement manipulation functions as masks for easy redo and undo of manipulation
 - Manipulation functions
    >wobble (vertical and horizontal)
    >transparent mask replacing a color
    >add impact font stamp filter
    >standard image manipulation functions:
       stretch/shrink - will have to be made using
       brightness/contrast - to be implemented using the HSL class for adjustment
       saturation - to be implemented using the HSL class for adjustment
 - add support for 32 bit images for alpha adjustments

  may be scrapped as it is potentially out of the scope of this project due to printer gamuts and such:
 - add support for CMYK color description and manipulation functions
    >Possibly implement a full color space and conversion library (CIELab, XYZ, CMYK, etc.)
*/

#define FILE_HEADER_SIZE 14
#define INFO_HEADER_SIZE 40

class Bitmap {
public:

    //Constructors:
    Bitmap();
    Bitmap(const Bitmap & toCopy);
    Bitmap(int width, int height);
    Bitmap(int width, int height, const RGB & color);

    //Destructor:
    ~Bitmap();

    //Manipulation Functions:
    void toGrayScale();
    void toSaturated();

    //Getter functions:
    int getWidth() const;
    int getHeight() const;
    int getBitsPerPixel() const;
    int getBytesPerPixel() const;
    int getPixelDataSize() const;


    //Manipulation Function Helpers:
    int setImageSolidColor(uint8_t color[3]);
    int setImageSolidColor(uint8_t R, uint8_t G, uint8_t B);
    
    //Operator overloads:
    friend std::ostream& operator<<(std::ostream& os, const Bitmap& bm);
    friend std::istream& operator>>(std::istream& is, Bitmap& bm);
    Pixel & operator()(int i, int j) const;

private:

    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;
    PixelMap pixelMap;

};

//Test functions:
void test0();
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();

#endif //BITMAP_TEST_BITMAP_H

#ifndef BITMAPPROJECT_BITMAPINFOHEADER_H
#define BITMAPPROJECT_BITMAPINFOHEADER_H
#include "../../Header/byteheader.h"
#define INFO_HEADER_SIZE 40

//Bitmap Info Header Structure:
/* unsigned char infoHeader[] = {
 *       0,0,0,0, /// header size
 *       0,0,0,0, /// image width
 *       0,0,0,0, /// image height
 *       0,0,     /// number of color planes
 *       0,0,     /// bits per pixel
 *       0,0,0,0, /// compression
 *       0,0,0,0, /// image size
 *       0,0,0,0, /// horizontal resolution
 *       0,0,0,0, /// vertical resolution
 *       0,0,0,0, /// colors in color table
 *       0,0,0,0, /// important color count
 *   };           */

//used https://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries
//for reference on how to read in the file

class BitmapInfoHeader : public ByteHeader {
public:
    BitmapInfoHeader();

    //Getter functions:
    int getWidth() const;
    int getHeight() const;
    int getPixelDataSize() const;
    int getBitsPerPixel() const;
    int getBytesPerPixel() const; //calls getBitsPerPixel

    //Setter functions:
    void setWidth(int val);
    void setHeight(int val);
    void setBitsPerPixel(int val);
    void setBytesPerPixel(int val); //calls setBitsPerPixel

    //Constant writing functions:
    void writeInfoHeaderSize();
    void writeNumPlanes();
    void writeXresolution();
    void writeYresolution();
    void writeColorsUsed();
    void writeNumColors();
    void writeAllConstants();

    //Variable writing function:
    void writePixelDataSize();


    //Update functions:
    void updateInfoHeader(int w, int h, int bpp);
    void updateInfoHeader(int w, int h);

    friend std::istream & operator>>(std::istream&is, BitmapInfoHeader & bmih);
    friend std::ostream &operator<<(std::ostream &os, const BitmapInfoHeader &bmih);


};


#endif //BITMAPPROJECT_BITMAPINFOHEADER_H

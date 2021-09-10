#ifndef BITMAP_TEST_BITMAPFILEHEADER_H
#define BITMAP_TEST_BITMAPFILEHEADER_H
#include "../../Header/byteheader.h"
#define FILE_HEADER_SIZE 14

//Bitmap File Header Structure:
/* unsigned char fileHeader[] = {
 *       0,0,     /// signature
 *       0,0,0,0, /// image file size in bytes
 *       0,0,0,0, /// reserved
 *       0,0,0,0, /// start of pixel array
 * };           */

//used https://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries
//for reference on how to read in the file

class BitmapFileHeader : public ByteHeader {
public:

    BitmapFileHeader();

    //Variable writing function:
    void writeTotalFileSize(int pixelDataSize);

    //Constant writing functions:
    void writeFileSignature();
    void writeTotalHeaderSize(); //aka start of the pixel data
    void writeReserved();
    void writeAllConstants();
    void updateFileHeader(int pixelDataSize);

    //Operator overloads:
    friend std::istream & operator>>(std::istream&is, BitmapFileHeader & bmfh);
    friend std::ostream &operator<<(std::ostream &os, const BitmapFileHeader &bmfh);

    };

#endif //BITMAP_TEST_BITMAPFILEHEADER_H

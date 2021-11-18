#include "pixelmap.h"

/*Parentheses indexing operator:
 * returns a reference to the Pixel object at (i,j)
*/
Pixel & PixelMap::operator()(int i, int j) const {
    return pixelData[i][j];
}

/*Default Constructor:
 * initializes pixelData to a 1 by 1 array of Pixel objects (calling default constructor)
*/
PixelMap::PixelMap() : width(1), height(1) {
    pixelData = new Pixel*[height];
    pixelData[0] = new Pixel[width];
}

/*Destructor:
 * deallocates all Pixel objects in pixelData
*/
PixelMap::~PixelMap() {
    int h = height;
    for (int i = 0; i < h; i++) {
        delete[] pixelData[i];
    }
    delete[] pixelData;
}

/*Constructor: PixelMap(w, h)
 *initializes the pixelData to an array of Pixels, width = w, height = h
*/
PixelMap::PixelMap(int w, int h) : width(w), height(h) {
    pixelData = new Pixel*[h];
    for(int i = 0; i < h; i++) {
        pixelData[i] = new Pixel[w];
    }
}

/*setHeight(h)
 * sets the height of pixelData to h
 * NOTE: currently deletes all data previously in the array
*/
void PixelMap::setHeight(int h) {
    for (int i = 0; i < height; i++) {
        delete[] pixelData[i];
    }
    delete[] pixelData;

    pixelData = new Pixel*[h];
    for(int i = 0; i < h; i++) {
        pixelData[i] = new Pixel[width];
    }
    height = h;
}

/*setWidth(w)
 * sets the width of pixelData to w
 * NOTE: currently deletes all data previously in the array
*/
void PixelMap::setWidth(int w) {
    for (int i = 0; i < height; i++) {
        delete[] pixelData[i];
    }
    delete[] pixelData;

    pixelData = new Pixel*[height];
    for(int i = 0; i < height; i++) {
        pixelData[i] = new Pixel[w];
    }
    width = w;
}

/*Index operator overload:
 * returns a reference to the first item in the row i
 * this is a sneaky way to do the double index operator!
*/
Pixel *PixelMap::operator[](int i) const {
    return pixelData[i];
}

std::istream &operator>>(std::istream &is, PixelMap &pm) {
    int numLineBufferBytes = pm.width%4;
    auto * tempEmptyBuf = new uint8_t[numLineBufferBytes];
    for (int i = pm.height-1; i >= 0; i--) {
        for (int j = 0; j < pm.width; j++) {
            is >> pm[i][j];
        }
        //skip the '0' bytes at the end of the line, the number of which is equal to the filler bytes multiplied by the number of bytes per line
        is.read((char *)tempEmptyBuf,numLineBufferBytes);
    }
    delete[] tempEmptyBuf;
    return is;
}


std::ostream &operator<<(std::ostream &os, const PixelMap &pm) {
    int numLineBufferBytes = pm.width%4;
    for (int i = pm.height-1; i >= 0; i--) {
        for (int j = 0; j < pm.width; j++)
            os << pm[i][j];
        //skip the '0' bytes at the end of the line, the number of which is equal to the filler bytes multiplied by the number of bytes per line
        for (int j = 0; j < numLineBufferBytes; j++)
            os << char(0);
    }
    return os;
}

//SelectionMask():
//Returns a new Selection object that is the same dimensions as this object, with no pixels selected
Selection & PixelMap::SelectionMask() const {
    Selection * toReturn = new Selection(width, height);
    return *toReturn;
}

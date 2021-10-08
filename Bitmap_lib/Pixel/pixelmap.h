/*Class: PixelMap
 * a clean dynamic 2D array of Pixel objects to do operations on
*/
#ifndef BITMAPPROJECT_PIXELMAP_H
#define BITMAPPROJECT_PIXELMAP_H
#include "pixel.h"

class PixelMap {
public:

    //Constructors:
    PixelMap();
    PixelMap(int w, int h);

    //Destructor:
    ~PixelMap();

    //Setter functions:
    void setWidth(int w);
    void setHeight(int h);

    //Operator overloads:
    Pixel * operator[](int i) const;
    Pixel & operator()(int i, int j) const;
    friend std::ostream& operator<<(std::ostream& os, const PixelMap& pm);
    friend std::istream& operator>>(std::istream& is, PixelMap& pm);

private:

    int width, height;
    Pixel ** pixelData;

};

#endif //BITMAP_TEST_PIXELARRAY_H

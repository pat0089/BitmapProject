/*Class: PixelMap
 * a clean dynamic 2D array of Pixel objects to do operations on
*/
#ifndef BITMAP_TEST_PIXELARRAY_H
#define BITMAP_TEST_PIXELARRAY_H
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

    //function to run a Pixel manipulation function on each Pixel
    //function to run a PixelArray manipulation function on the whole array

private:

    int width, height;
    Pixel ** pixelData;

};


#endif //BITMAP_TEST_PIXELARRAY_H

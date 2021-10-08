/*Non-Abstract Subclass: HSL
 * Parent: Color
 * HSL representation of color values of a Pixel
*/

#ifndef BITMAPPROJECT_HSL_H
#define BITMAPPROJECT_HSL_H
#include "../RGB/rgb.h"

class RGB;

class HSL {
public:

    //Constructors
    HSL();
    HSL(const RGB &toCopy);

    ~HSL();

    //HSL:
    double H() const;
    double S() const;
    double L() const;

    //Setter functions:
    //HSL:
    void H(double val);
    void S(double val);
    void L(double val);

private:

    //possibly changing implementation to an array like with the original Pixel object, except an array of 3
    double h, s, l;
};


#endif //BITMAPPROJECT_HSL_H

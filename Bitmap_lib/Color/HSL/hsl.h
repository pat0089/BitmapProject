/*Non-Abstract Subclass: HSL
 * Parent: Color
 * HSL representation of color values of a Pixel
*/

#ifndef BITMAP_TEST_HSL_H
#define BITMAP_TEST_HSL_H
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


#endif //BITMAP_TEST_HSL_H

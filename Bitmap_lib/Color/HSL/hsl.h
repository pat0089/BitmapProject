/*Non-Abstract Subclass: HSL
 * Parent: Color
 * HSL representation of color values of a Pixel
*/

#ifndef BITMAP_TEST_HSL_H
#define BITMAP_TEST_HSL_H
#include "../color.h"

class HSL : public Color {
public:

    //Constructors
    HSL();
    HSL(const Color &toCopy);

    ~HSL();

    //Getter functions:
    //RGB:
    uint8_t R() const;
    uint8_t G() const;
    uint8_t B() const;
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

    uint8_t HSL_to_RGB(double h, double s, double l, double n) const;

};


#endif //BITMAP_TEST_HSL_H

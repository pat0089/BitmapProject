/*Non-Abstract Subclass: RGB
 * Parent: Color
 * RGB representation of color values of a Pixel
*/

#ifndef BITMAPPROJECT_RGB_H
#define BITMAPPROJECT_RGB_H
#include "../HSL/hsl.h"
#include <cinttypes>

class HSL;

class RGB {
public:

    RGB();
    RGB(uint8_t r, uint8_t g, uint8_t b);
    RGB(const RGB & toCopy);
    RGB(const HSL & toCopy);

    ~RGB();

    uint8_t R() const;
    uint8_t G() const;
    uint8_t B() const;

    void R(uint8_t val);
    void G(uint8_t val);
    void B(uint8_t val);

    //Operator overloads
    RGB & operator= (const RGB & toEqual);
    friend bool operator == (const RGB & lhs, const RGB & rhs);
    friend bool operator != (const RGB & lhs, const RGB & rhs);

private:

    double r, g, b;

};

#endif //BITMAPPROJECT_RGB_H

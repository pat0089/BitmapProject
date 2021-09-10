/*Non-Abstract Subclass: RGB
 * Parent: Color
 * RGB representation of color values of a Pixel
*/

#ifndef BITMAP_TEST_RGB_H
#define BITMAP_TEST_RGB_H
#include "../color.h"

class HSL;

class RGB : public Color {
public:

    RGB();
    RGB(uint8_t r, uint8_t g, uint8_t b);
    explicit RGB(const Color & toCopy);
    RGB(const RGB & toCopy);

    ~RGB();

    uint8_t R() const;
    uint8_t G() const;
    uint8_t B() const;

    double H() const;
    double S() const;
    double L() const;

    void R(uint8_t val);
    void G(uint8_t val);
    void B(uint8_t val);

    //Operator overloads
    RGB & operator= (const RGB & toEqual);
    RGB & operator= (const Color & toEqual);
    friend bool operator == (const RGB & lhs, const Color & rhs);
    friend bool operator != (const RGB & lhs, const Color & rhs);

private:

    double r, g, b;

    double getMaxRGB() const;
    double getMinRGB() const;

};

#endif //BITMAP_TEST_RGB_H

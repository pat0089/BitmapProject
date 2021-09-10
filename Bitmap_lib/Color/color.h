/*Abstract Class: Color
 * declares abstract getter and setter functions that will be used in the RGB and HSL color format classes
*/
#ifndef BITMAP_TEST_COLOR_H
#define BITMAP_TEST_COLOR_H

#include <cstdint>

class Color {
public:

    //Getter functions:
    //RGB:
    virtual uint8_t R() const = 0;
    virtual uint8_t G() const = 0;
    virtual uint8_t B() const = 0;
    //HSL:
    virtual double H() const = 0;
    virtual double S() const = 0;
    virtual double L() const = 0;

    virtual ~Color() = 0;

};

#endif
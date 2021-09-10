#include "rgb.h"
#include <cmath>

/*R():
 * returns the Red value of the color
*/
uint8_t RGB::R() const {
    return (uint8_t)r * 255.0;
}

/*G():
 * returns the Green value of the color
*/
uint8_t RGB::G() const {
    return (uint8_t)g * 255.0;
}

/*B():
 * returns the Blue value of the color
*/
uint8_t RGB::B() const {
    return (uint8_t)b * 255.0;
}

/*R(val):
 * sets the Red value to the parameter val
*/
void RGB::R(uint8_t val) {
    r = double(val)/255.0;
}

/*G(val):
 * sets the Green value to the parameter val
*/
void RGB::G(uint8_t val) {
    g = double(val)/255.0;
}

/*B(val):
 * sets the Blue value to the parameter val
*/
void RGB::B(uint8_t val) {
    b = double(val)/255.0;
}

/*Constructor:
 * initializes to parameters: (r, g, b)
*/
RGB::RGB(uint8_t r, uint8_t g, uint8_t b) : r(double(r)/255.0), g(double(g)/255.0), b(double(b)/255.0) {}

/*Default Constructor:
 * initializes to black (0, 0, 0)
*/
RGB::RGB(): r(0.0), g(0.0), b(0.0) {}

RGB::~RGB() = default;


RGB::RGB(const RGB & toCopy) {
    r = toCopy.r;
    g = toCopy.g;
    b = toCopy.b;
}


/*Assignment Operator:
 * sets an RGB object equal to another RGB object
*/
RGB &RGB::operator = (const RGB &toEqual) {
    r = toEqual.r;
    g = toEqual.g;
    b = toEqual.b;
    return *this;
}

RGB &RGB::operator= (const Color & toEqual) {
    R(toEqual.R());
    G(toEqual.G());
    B(toEqual.B());
    return *this;
}

/*Comparison Operator:
 * checks to see if the RGB object is equal to another Color
 * */
bool operator == (const RGB & lhs, const Color & rhs) {
    return (lhs.R() == rhs.R() && lhs.G() == rhs.G() && lhs.B() == rhs.B());
}

bool operator != (const RGB & lhs, const Color & rhs) {
    return !(lhs == rhs);
}


/*Copy Constructor:
 * initializes RGB object to another Color type object
*/
RGB::RGB(const Color &toCopy) {
    r = toCopy.R();
    g = toCopy.G();
    b = toCopy.B();
}

double RGB::H() const {
    double min = getMinRGB();
    double max = getMaxRGB();
    double chroma = max - min;
    if (max == r) {
        return (g - b) / chroma;
    } else if (max == g) {
        return (2.0 + (b - r)) / chroma;
    } else if (max == b) {
        return (4.0 + (r - g)) / chroma;
    }
    return 0.0;
}

double RGB::S() const {
    double temp_l = L();
    double max = getMaxRGB();
    return (max - temp_l)/fmin(temp_l, 1.0 - temp_l);
}

double RGB::L() const {
    return (getMaxRGB() + getMinRGB())/2.0;
}

double RGB::getMaxRGB() const {
    return fmax(fmax(r, g), b);
}

double RGB::getMinRGB() const {
    return fmin(fmin(r, g), b);
}
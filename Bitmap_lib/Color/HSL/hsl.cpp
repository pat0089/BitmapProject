#include "hsl.h"
#include <cmath>

HSL::HSL(): h(0.0), s(0.0), l(0.0) {}

HSL::~HSL() = default;


/*H():
 * returns the Hue value of the color
*/
double HSL::H() const {
    return h;
}

/*S():
 * returns the Saturation value of the color
*/
double HSL::S() const {
    return s;
}

/*L():
 * returns the Lightness/Luminosity value of the color
*/
double HSL::L() const {
    return l;
}

/*H(val):
 * sets the Hue to the parameter val
*/
void HSL::H(double val) {
    h = val;
}

/*S(val):
 * sets the Saturation to the parameter val
*/
void HSL::S(double val) {
    s = val;
}

/*L(val):
 * sets the Lightness/Luminosity to the parameter val
*/
void HSL::L(double val) {
    l = val;
}

/*Copy Constructor:
 * initializes HSL object to another Color type object
*/
HSL::HSL(const Color &toCopy) {
    h = toCopy.H();
    s = toCopy.S();
    l = toCopy.L();
}

uint8_t HSL::R() const {
    return HSL_to_RGB(H(), S(), L(), 0.0);
}

uint8_t HSL::G() const {
    return HSL_to_RGB(H(), S(), L(), 8.0);
}

uint8_t HSL::B() const {
    return HSL_to_RGB(H(), S(), L(), 4.0);
}

//Conversion helper function grabbed from wikipedia
uint8_t HSL::HSL_to_RGB(double old_h, double old_s, double old_l, double n) const {
    double k = fmod((n + old_h * 360.0), 12.0);
    double a = old_s * fmin(old_l, 1.0 - old_l);
    return (uint8_t)(old_l - (a * fmax(-1, fmin(fmin(k - 3.0, 9.0 - k), 1))))*255.0;
}
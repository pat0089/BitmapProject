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

/*Conversion Constructor:
 * initializes HSL object to the equivalent RGB type object
*/
HSL::HSL(const RGB &toCopy) {
    double r = double(toCopy.R()) / 255.0;
    double g = double(toCopy.G()) / 255.0;
    double b = double(toCopy.B()) / 255.0;

    double max = fmax(fmax(r, g),b);
    double min = fmin(fmin(r, g),b);
    double delta = max - min;

    //Clamp l value to [0.0, 100.0]
    l = (max + min) / 2.0 * 100.0;

    if (delta == 0.0) {
        h = 0.0;
        l = 0.0;
    } else {
        //set saturation based on lightness value [0.0, 100.0]
        (l < 0.5) ? s = (delta / (max + min)) * 100.0 : s = (delta / (2.0 - max - min)) * 100.0;

        //precalculate hue values
        double delta_r = (((max - r) / 6.0) + (delta / 2.0)) / delta;
        double delta_g = (((max - g) / 6.0) + (delta / 2.0)) / delta;
        double delta_b = (((max - b) / 6.0) + (delta / 2.0)) / delta;

        //set hue
        if (r == max) h = delta_b - delta_g;
        else if (g == max) h = (1.0 / 3.0) + delta_r - delta_b;
        else if (b == max) h = (2.0 / 3.0) + delta_g - delta_r;

        //clamp hue to [0.0, 360)
        if (h < 0.0) h += 1.0;
        if (h > 1.0) h -= 1.0;
        h *= 360.0;
    }
}
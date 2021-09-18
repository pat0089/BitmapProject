#include "rgb.h"

double Hue_to_RGB(double val_1, double val_2, double hue_val) {
    //clamp hue_val to [0, 1.0]
    if (hue_val < 0.0) hue_val += 1.0;
    if (hue_val > 1.0) hue_val -= 1.0;

    //return hue value accordingly
    //if the hue is in the first 60 degrees of the color wheel
    if ((6.0 * hue_val) < 1.0) return (val_1 + (val_2 - val_1) * 6.0 * hue_val);
    //if the hue is in the range of [60, 180) degrees
    if ((2.0 * hue_val) < 1.0) return val_2;
    //if the hue is in the range of [180, 300) degrees
    if ((3.0 * hue_val) < 2.0) return (val_1 + (val_2 - val_1) * ((2.0 / 3.0) - hue_val) * 6.0);
    //covering the final range of [300, 360/0) degrees
    return val_1;
}

/*R():
 * returns the Red value of the color
*/
uint8_t RGB::R() const {
    return (uint8_t)(r + 0.5);
}

/*G():
 * returns the Green value of the color
*/
uint8_t RGB::G() const {
    return (uint8_t)(g + 0.5);
}

/*B():
 * returns the Blue value of the color
*/
uint8_t RGB::B() const {
    return (uint8_t)(b + 0.5);
}

/*R(val):
 * sets the Red value to the parameter val
*/
void RGB::R(uint8_t val) {
    r = double(val);
}

/*G(val):
 * sets the Green value to the parameter val
*/
void RGB::G(uint8_t val) {
    g = double(val);
}

/*B(val):
 * sets the Blue value to the parameter val
*/
void RGB::B(uint8_t val) {
    b = double(val);
}

/*Constructor:
 * initializes to parameters: (r, g, b)
*/
RGB::RGB(uint8_t r, uint8_t g, uint8_t b) : r(double(r)), g(double(g)), b(double(b)) {}

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

/*Comparison Operator:
 * checks to see if the RGB object is equal to another Color
 * */
bool operator == (const RGB & lhs, const RGB & rhs) {
    return (lhs.R() == rhs.R() && lhs.G() == rhs.G() && lhs.B() == rhs.B());
}

bool operator != (const RGB & lhs, const RGB & rhs) {
    return !(lhs == rhs);
}


/*Copy Constructor:
 * initializes RGB object to another Color type object
*/
RGB::RGB(const HSL &toCopy) {
    double h = toCopy.H()/360.0;
    double s = toCopy.S()/100.0;
    double l = toCopy.L()/100.0;

    //if achromatic, set each value equal to the luminosity
    if (s == 0.0) {
        r = g = b = l * 255.0;
    } else {
        double val_2 = 0.0;
        (l < 0.5) ? val_2 = l * (1.0 + s) : val_2 = (l + s) - (s * l);

        double val_1 = 2 * l - val_2;

        //set rgb values according to calculated values
        r = 255 * Hue_to_RGB(val_1, val_2, h + (1.0 / 3.0));
        g = 255 * Hue_to_RGB(val_1, val_2, h);
        b = 255 * Hue_to_RGB(val_1, val_2, h - (1.0 / 3.0));
    }
}
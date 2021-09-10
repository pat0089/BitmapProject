#include "pixel.h"

/*Default Constructor:
 * initialize Pixel with a Color of black: RGB(0, 0, 0)
*/
Pixel::Pixel() {
    color = new RGB(0,0,0);
}

/*Constructor: Pixel(R, G, B)
 * initialize Pixel with a Color of black: RGB(R, G, B)
*/
Pixel::Pixel(uint8_t R, uint8_t G, uint8_t B) {
    color = new RGB(R, G, B);
}

/*Constructor: Pixel(color)
 * initialize Pixel with a Color equal to the parameter Color
*/
Pixel::Pixel(const Color & color) {
    Pixel::color = new RGB(color);
}

/*setColor(R, G, B):
 * Sets the color equal to the RGB equivalent of the combination of the parameter values
*/
void Pixel::setColor(uint8_t R, uint8_t G, uint8_t B) {
    color->R(R);
    color->G(G);
    color->B(B);
}

/*setColor(color[3]):
 * Sets the color equal to the RGB equivalent of the array treated as [R,G,B]
*/
void Pixel::setColor(uint8_t color[3]) {
    Pixel::color->R(color[0]);
    Pixel::color->G(color[1]);
    Pixel::color->B(color[2]);
}

/*setColor(color):
 * Sets the color equal to the RGB equivalent of the color parameter
*/
void Pixel::setColor(const Color & color) {
    delete Pixel::color;
    Pixel::color = new RGB(color);
}

/*Destructor:
 * deletes the smart pointer color
*/
Pixel::~Pixel() {
    delete color;
}

/*getColor():
 * Returns a reference to the Color object within Pixel
*/
const RGB &Pixel::getColor() {
    return *color;
}

std::istream &operator>>(std::istream &is, Pixel &p) {
    uint8_t val[3];
    for (int i = 2; i >= 0; i--) {
        is >> val[i];
    }
    p.setColor(val);
    return is;
}

std::ostream &operator<<(std::ostream &os, const Pixel &p) {
    os << p.color->B() << p.color->G() << p.color->R();
    return os;
}

//functions to be transported and reimplemented in classes 'HSL' and 'RGB'
/*
double Pixel::getHue() const {
    double r = double(getR())/255.0;
    double g = double(getG())/255.0;
    double b = double(getB())/255.0;

    double max = getMaxValue(getR(),int(getMaxValue(getG(),getB())));
    double min = getMinValue(getR(),int(getMinValue(getG(),getB())));
    double hue;

    //hue is calculated out of 360 where 0 is red, 120 is blue, 240 is green, and everything else is everywhere in between
    if (max == r) {
        hue = (g - b) / (max - min) + (g < b ? 0.0 : 6.0);
    } else if (max == g) {
        hue = 2.0 + (b - r) / (max - min);
    } else {
        hue = 4.0 + (r - g) / (max - min);
    }
    hue /= 6.0;
    return hue;
}

double Pixel::getSaturation() const {
    double max = getMaxValue(getR(),(unsigned char)(getMaxValue(getG(),getB())));
    double min = getMinValue(getR(),(unsigned char)(getMinValue(getG(),getB())));
    double dif = max-min;

    //calculate luminosity, average of minimum and maximum value
    double lum = (max+min)/2.0;

    double sat;
    if (lum < 0.5) {
        //if luminosity is less than 50%, the saturation ratio is the difference and sum of the max and min
        sat = dif/(max+min);
    } else {
        //if luminosity is greater than 50%, the saturation ratio is the difference and the sum of max and min subtracted from 2
        sat = dif/(2.0-(max+min));
    }
    return sat;
}

double Pixel::getLuminosity() const {
    double total = 0.0;
    total += double(getR());
    total += double(getG());
    total += double(getB());
    return (total/(3.0*255.0));
}

void Pixel::setHue(const double val) {

}

void Pixel::setSaturation(const double val) {

}

void Pixel::setLuminosity(const double val) {

}
*/

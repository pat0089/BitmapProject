/*Class: Pixel
 * Holds the Color of a representative pixel from an image file
*/
#ifndef BITMAP_TEST_PIXEL_H
#define BITMAP_TEST_PIXEL_H
#include <iostream>
#include "../Color/colortypes.h"
class Pixel {
public:

    //Constructors:
    Pixel();
    explicit Pixel(const RGB & color);
    Pixel(uint8_t R, uint8_t G, uint8_t B);

    //Destructor:
    ~Pixel();

    //Setter functions:
    void setColor(const RGB & color);
    void setColor(uint8_t color[3]);
    void setColor(uint8_t R, uint8_t G, uint8_t B);

    //Getter functions:
    const RGB & getColor();

    //Operator overloads:
    friend std::ostream& operator<<(std::ostream& os, const Pixel& p);
    friend std::istream& operator>>(std::istream& is, Pixel& p);

private:
    RGB * color = nullptr;

};

#endif //BITMAP_TEST_PIXEL_H

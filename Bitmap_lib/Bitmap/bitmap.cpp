#include "bitmap.h"

/*Default Constructor:
 * initialize a Bitmap object to a single 1x1 black pixel
 */
Bitmap::Bitmap() {};



/*Destructor:
 * default destructor because no new memory is allocated within Bitmap itself
 */
Bitmap::~Bitmap() = default;

/*Copy Constructor:
 * copies all data from an existing Bitmap object into a new one
 */
Bitmap::Bitmap(const Bitmap &toCopy) {
    int tempWidth = toCopy.infoHeader.getWidth();
    int tempHeight = toCopy.infoHeader.getHeight();
    infoHeader.updateInfoHeader(tempWidth, tempHeight, toCopy.infoHeader.getBytesPerPixel());
    pixelMap.setWidth(tempWidth);
    pixelMap.setHeight(tempHeight);
    for (int i = 0; i < tempHeight; i++)
        for(int j = 0; j < tempWidth; j++)
            pixelMap[i][j].setColor(toCopy.pixelMap[i][j].getColor());
}

//setImageSolidColor will have to be adapted for 32 bit bitmap images using the getBits/BytesPerPixel functions
int Bitmap::setImageSolidColor(uint8_t R, uint8_t G, uint8_t B) {
    int numPixelsChanged = 0;

    int tempWidth = infoHeader.getWidth();
    int tempHeight = infoHeader.getHeight();

    for (int i = 0; i < tempHeight; i++) {
        for (int j = 0; j < tempWidth; j++) {
            pixelMap[i][j].setColor(R, G, B);
            numPixelsChanged++;
        }
    }
    return numPixelsChanged;
}

int Bitmap::setImageSolidColor(uint8_t color[3]) {
	int numPixelsChanged = 0;

    int tempWidth = infoHeader.getWidth();
    int tempHeight = infoHeader.getHeight();

    for (int i = 0; i < tempHeight; i++) {
        for (int j = 0; j < tempWidth; j++) {
            pixelMap[i][j].setColor(color);
            numPixelsChanged++;
        }
    }
	return numPixelsChanged;
}

//Manipulation functions
void Bitmap::toGrayScale() {
    int tempWidth = infoHeader.getWidth();
    int tempHeight = infoHeader.getHeight();
    for (int i = 0; i < tempHeight; i++) {
        for (int j = 0; j < tempWidth; j++) {
            //auto a = (uint8_t)(pixelMap[i][j].getColor().L()*255);
            //pixelMap[i][j].setColor(a, a, a);
        }
    }
}

void Bitmap::toSaturated() {
    int tempWidth = infoHeader.getWidth();
    int tempHeight = infoHeader.getHeight();
    for (int i = 0; i < tempHeight; i++) {
        for (int j = 0; j < tempWidth; j++) {
            //pixelData[i][j].setColor();
        }
    }
}

/* Ostream operator overload:
 * Puts the Bitmap object to an ostream as if writing to a file
*/
std::ostream &operator<<(std::ostream &os, const Bitmap &bm) {
    os << bm.fileHeader;
    os << bm.infoHeader;
    os << bm.pixelMap;
    return os;
}

/* Istream operator overload:
 * assumes data read from the stream is in the same format as the .BMP file format, reads the data into a Bitmap object
*/
std::istream &operator>>(std::istream &is, Bitmap &bm) {
    is >> bm.fileHeader;
    is >> bm.infoHeader;
    bm.pixelMap.setWidth(bm.infoHeader.getWidth());
    bm.pixelMap.setHeight(bm.infoHeader.getHeight());
    is >> bm.pixelMap;
    return is;
}

/*Parentheses indexing operator:
 * returns a reference to the Pixel object at (i, j) of Bitmap's PixelArray
*/
Pixel & Bitmap::operator()(int i, int j) const{
    return pixelMap[i][j];
}

int Bitmap::getWidth() const {
    return infoHeader.getWidth();
}

int Bitmap::getHeight() const {
    return infoHeader.getHeight();
}

int Bitmap::getPixelDataSize() const {
    return infoHeader.getPixelDataSize();
}

int Bitmap::getBytesPerPixel() const {
    return infoHeader.getBytesPerPixel();
}

int Bitmap::getBitsPerPixel() const {
    return infoHeader.getBitsPerPixel();
}

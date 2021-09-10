#include "bitmapinfoheader.h"

BitmapInfoHeader::BitmapInfoHeader() : ByteHeader(INFO_HEADER_SIZE) {
    updateInfoHeader(1, 1, 3);
}

std::istream &operator>>(std::istream &is, BitmapInfoHeader &bmih) {
    is.read((char *)bmih.headerData, INFO_HEADER_SIZE);
    return is;
}

std::ostream &operator<<(std::ostream &os, const BitmapInfoHeader &bmih) {
    os.write((char *)bmih.headerData, INFO_HEADER_SIZE);
    return os;
}

int BitmapInfoHeader::getWidth() const {
    return getHeaderInt4(4);
}

int BitmapInfoHeader::getHeight() const {
    return getHeaderInt4(8);
}

int BitmapInfoHeader::getPixelDataSize() const {
    return getHeaderInt4(20);
}

int BitmapInfoHeader::getBitsPerPixel() const {
    return getHeaderInt2(14);
}

int BitmapInfoHeader::getBytesPerPixel() const {
    return (getBitsPerPixel()/8);
}

void BitmapInfoHeader::setWidth(int val) {
    setHeaderInt4(4, val);
}

void BitmapInfoHeader::setHeight(int val) {
    setHeaderInt4(8, val);
}

void BitmapInfoHeader::writePixelDataSize() {
    setHeaderInt4(20, ((getWidth()*3 + (getWidth()*3)%4)*getHeight()));
}

void BitmapInfoHeader::setBitsPerPixel(int val) {
    setHeaderInt2(14, val);
}

void BitmapInfoHeader::setBytesPerPixel(int val) {
    setBitsPerPixel(val*8);
}

void BitmapInfoHeader::writeInfoHeaderSize() {
    setHeaderInt4(0, 40);
}

void BitmapInfoHeader::writeNumPlanes() {
    setHeaderInt2(12, 1);
}

void BitmapInfoHeader::writeXresolution() {
    setHeaderInt4(24, 0);
}

void BitmapInfoHeader::writeYresolution() {
    setHeaderInt4(28, 0);
}

void BitmapInfoHeader::writeColorsUsed() {
    setHeaderInt4(32, 0);
}

void BitmapInfoHeader::writeNumColors() {
    setHeaderInt4(36, 0);
}

void BitmapInfoHeader::writeAllConstants() {
    writeInfoHeaderSize();
    writeNumPlanes();
    writeXresolution();
    writeYresolution();
    writeColorsUsed();
    writeNumColors();
}

/*updateInfoHeader(w, h, bpp)
 * Update the entirety of the header, given the parameters
 * Note: bpp stands for Bytes per pixel
*/
void BitmapInfoHeader::updateInfoHeader(int w, int h, int bpp) {
    writeAllConstants();
    setWidth(w);
    setHeight(h);
    writePixelDataSize();
    setBytesPerPixel(bpp);
}

/*updateInfoHeader(w, h)
 * Update the entirety of the header, given the parameters
*/
void BitmapInfoHeader::updateInfoHeader(int w, int h) {
    writeAllConstants();
    setWidth(w);
    setHeight(h);
    writePixelDataSize();
}

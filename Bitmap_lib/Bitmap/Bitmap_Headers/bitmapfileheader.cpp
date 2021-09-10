#include "bitmapfileheader.h"

BitmapFileHeader::BitmapFileHeader() : ByteHeader(FILE_HEADER_SIZE) {}

std::istream &operator>>(std::istream &is, BitmapFileHeader &bmfh) {
    is.read((char *)bmfh.headerData, FILE_HEADER_SIZE);
    return is;
}

std::ostream &operator<<(std::ostream &os, const BitmapFileHeader &bmfh) {
    os.write((char *)bmfh.headerData, FILE_HEADER_SIZE);
    return os;
}

void BitmapFileHeader::writeTotalFileSize(int pixelDataSize) {
    setHeaderInt4(2, (FILE_HEADER_SIZE + 40 + pixelDataSize));
}

void BitmapFileHeader::writeFileSignature() {
    headerData[0] = 'B';
    headerData[1] = 'M';
}

void BitmapFileHeader::writeTotalHeaderSize() {
    setHeaderInt4(10, 54);
}

void BitmapFileHeader::writeReserved() {
    setHeaderInt4(6,0);
}

void BitmapFileHeader::writeAllConstants() {
    writeFileSignature();
    writeReserved();
    writeTotalHeaderSize();
}

void BitmapFileHeader::updateFileHeader(int pixelDataSize) {
    writeAllConstants();
    writeTotalFileSize(pixelDataSize);
}



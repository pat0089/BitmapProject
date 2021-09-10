#include "byteheader.h"

ByteHeader::ByteHeader(): headerData(nullptr), size(0) {};

ByteHeader::ByteHeader(int size) : size(size) {
    headerData = new uint8_t [size];
    for (int i = 0; i < size; i++) {
        headerData[i] = 0;
    }
}

ByteHeader::~ByteHeader() {
    delete[] headerData;
}

int ByteHeader::getSize() const {
    return size;
}

int ByteHeader::getHeaderInt2(int startIndex) const {
    return int((uint8_t)(headerData[startIndex]) |
               (uint8_t)(headerData[startIndex+1]) << 8);
}

int ByteHeader::getHeaderInt4(int startIndex) const {
    return int((uint8_t)(headerData[startIndex]) |
                (uint8_t)(headerData[startIndex+1]) << 8 |
                (uint8_t)(headerData[startIndex+2]) << 16 |
                (uint8_t)(headerData[startIndex+3]) << 24);
}

void ByteHeader::setHeaderInt2(int startIndex, int writeValue) {
    headerData[startIndex] = (uint8_t) (writeValue);
    headerData[startIndex+1] = (uint8_t) (writeValue << 8);
}

void ByteHeader::setHeaderInt4(int startIndex, int writeValue) {
    headerData[startIndex] = (uint8_t) (writeValue);
    headerData[startIndex+1] = (uint8_t) (writeValue << 8);
    headerData[startIndex+2] = (uint8_t) (writeValue << 16);
    headerData[startIndex+3] = (uint8_t) (writeValue << 24);
}



/*Parent Class: ByteHeader
 * a Header class that stores bytes of data
 * Can possibly be used with multiple different image file formats
*/
#ifndef BITMAPPROJECT_BYTEHEADER_H
#define BITMAPPROJECT_BYTEHEADER_H
#include <iostream>
class ByteHeader {
public:

    //Constructors:
    ByteHeader();
    ByteHeader(int size);

    //Destructor:
    ~ByteHeader();

    //Getter function
    int getSize() const;

protected:

    int size;
    uint8_t * headerData;

    //Getter helper functions
    int getHeaderInt2(int startIndex) const;
    int getHeaderInt4(int startIndex) const;

    //Setter Helper functions
    void setHeaderInt2(int startIndex, int writeValue);
    void setHeaderInt4(int startIndex, int writeValue);

};

#endif //BITMAPPROJECT_BYTEHEADER_H

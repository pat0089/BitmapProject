project(BitmapProject)

set(HEADER_FILES
        #ADD HEADER FILES HERE
        Bitmap/bitmap.h
        Bitmap/Bitmap_Headers/bitmapheaders.h
        Header/byteheader.h
        Pixel/pixel.h
        Pixel/pixelmap.h
        Color/RGB/rgb.h
        Color/HSL/HSL.h
        )

set(SOURCE_FILES
        #ADD SOURCE FILES HERE
        Bitmap/bitmap.cpp
        Bitmap/Bitmap_Headers/bitmapfileheader.cpp
        Bitmap/Bitmap_Headers/bitmapinfoheader.cpp
        Header/byteheader.cpp
        Pixel/pixel.cpp
        Pixel/pixelmap.cpp
        Color/RGB/rgb.cpp
        Color/HSL/hsl.cpp
        )

add_library(Bitmap_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
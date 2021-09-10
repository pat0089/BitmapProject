cmake_minimum_required(VERSION 3.16)
project(BitmapProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(Bitmap_run main.cpp)

include_directories(Bitmap_lib)
add_subdirectory(Bitmap_lib)

target_link_libraries(Bitmap_run Bitmap_lib)

add_subdirectory(Catch_tests)
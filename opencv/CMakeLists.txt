cmake_minimum_required(VERSION 3.10)
PROJECT (BadApple)
find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui imgcodecs)
set( NAME_SRC
    src/main.cpp
    src/miniaudio.c
)
add_compile_options(-O3)

INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( BadApple ${NAME_SRC} )

INCLUDE_DIRECTORIES(${OpenCV_LIBS})
target_link_libraries( BadApple ${OpenCV_LIBS})


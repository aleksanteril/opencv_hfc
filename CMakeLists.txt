cmake_minimum_required(VERSION 3.24.2)

project(opencv_hfc)



# Set OpenCV directory paths

set(OpenCV_DIR "C:/opencv/build")

set(OpenCV_INCLUDE_DIRS "C:/opencv/opencv/build/include")

set(OpenCV_LIB_DIR "C:/opencv/build/x64/vc16/lib")

set(OpenCV_BIN_DIR "C:/opencv/build/x64/vc16/bin")



# Find OpenCV package

find_package(OpenCV REQUIRED PATHS ${OpenCV_DIR})



# Include directories from OpenCV

include_directories(${OpenCV_INCLUDE_DIRS})



# Create an executable

add_executable(opencv_hfc main.cpp)



# Link OpenCV libraries

target_link_libraries(opencv_hfc ${OpenCV_LIBS})



# Copy OpenCV DLLs to the output directory

add_custom_command(TARGET opencv_hfc POST_BUILD

    COMMAND ${CMAKE_COMMAND} -E copy_directory

    ${OpenCV_BIN_DIR} $<TARGET_FILE_DIR:opencv_hfc>)

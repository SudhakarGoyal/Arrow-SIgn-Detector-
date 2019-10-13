cmake_minimum_required(VERSION 2.8.3)
project(detector)
find_package(Threads REQUIRED)
## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++14)
find_package(OpenCV REQUIRED)

include(/home/hitech/dlib-19.17/dlib/cmake)
include_directories("/home/hitech/dlib-19.17")

include_directories(
 include
)
add_library(arrow_detect src/arrow_detect.cpp)
target_link_libraries(arrow_detect  ${CMAKE_THREAD_LIBS_INIT} ${OpenCV_LIBS} )

add_executable(arrow_detector src/arrow_detector.cpp)
target_link_libraries(arrow_detector arrow_detect)


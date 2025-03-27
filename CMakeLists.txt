cmake_minimum_required(VERSION 3.16.3)
project(openCV)
set(OpenCV_DIR /home/wjr/build)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)

add_executable(test01 src/show_many_images.cpp)
target_link_libraries(test01 ${OpenCV_LIBS})



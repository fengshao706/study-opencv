cmake_minimum_required(VERSION 3.30)
project(untitled)
set(OpenCV_DIR /home/wjr/opencv-4.8.1/build)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


set(CMAKE_CXX_STANDARD 20)

add_executable(main src/main.cpp)
target_link_libraries(main ${OpenCV_LIBS})

cmake_minimum_required(VERSION 3.8)
project(cubeModel)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(../../public/src ${CMAKE_BINARY_DIR}/public)

add_library(glutil glutil.cpp glutil.h)
target_link_libraries(glutil ysclass)

add_executable(makeCube MACOSX_BUNDLE makeCube.cpp)
target_link_libraries(makeCube fssimplewindow glutil)
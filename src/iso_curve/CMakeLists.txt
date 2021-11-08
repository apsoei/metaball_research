cmake_minimum_required(VERSION 3.8)
project(isoCurve)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(../../public/src ${CMAKE_BINARY_DIR}/public)

add_subdirectory(astar)
add_subdirectory(dha)
add_subdirectory(curve)


# set(TARGET_NAME glutil)
# add_library(${TARGET_NAME}
#     glutil.cpp
#     glutil.h
# )
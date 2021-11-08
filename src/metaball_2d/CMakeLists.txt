cmake_minimum_required(VERSION 3.8)
project(metaball_2d)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(../../public/src ${CMAKE_BINARY_DIR}/public)

add_executable(main MACOSX_BUNDLE metaball_2d.cpp)
target_link_libraries(main fssimplewindow)

add_executable(interp MACOSX_BUNDLE metaball_2d_interp.cpp)
target_link_libraries(interp fssimplewindow)

add_executable(cos MACOSX_BUNDLE metaball_2d_cos.cpp)
target_link_libraries(cos fssimplewindow)

add_executable(line MACOSX_BUNDLE metaball_2d_line.cpp)
target_link_libraries(line fssimplewindow)



# set(TARGET_NAME glutil)
# add_library(${TARGET_NAME}
#     glutil.cpp
#     glutil.h
# )%                               
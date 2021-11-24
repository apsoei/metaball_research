cmake_minimum_required(VERSION 3.8)
project(metaball)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(../../public/src ${CMAKE_BINARY_DIR}/public)

add_library(glutil glutil.cpp glutil.h)
target_link_libraries(glutil ysclass)

add_executable(main MACOSX_BUNDLE metaball.cpp)
target_link_libraries(main fssimplewindow glutil)

add_executable(simple MACOSX_BUNDLE metaSimple.cpp)
target_link_libraries(simple fssimplewindow glutil)

add_executable(meta2 MACOSX_BUNDLE meta2.cpp)
target_link_libraries(meta2 fssimplewindow glutil)

add_executable(meta3 MACOSX_BUNDLE meta3.cpp fileHandle.cpp fileHandle.h)
target_link_libraries(meta3 fssimplewindow glutil)

add_executable(metaEdge MACOSX_BUNDLE metaEdge.cpp fileHandle.cpp fileHandle.h)
target_link_libraries(metaEdge fssimplewindow glutil)

add_executable(meta0903 MACOSX_BUNDLE meta0903.cpp fileHandle.cpp fileHandle.h)
target_link_libraries(meta0903 fssimplewindow glutil)

add_executable(meta0914 MACOSX_BUNDLE meta0914.cpp fileHandle.cpp fileHandle.h util.cpp util.h)
target_link_libraries(meta0914 fssimplewindow glutil)

add_executable(meta0925 MACOSX_BUNDLE meta0925.cpp fileHandle.cpp fileHandle.h util.cpp util.h)
target_link_libraries(meta0925 fssimplewindow glutil)

add_executable(meta1013 MACOSX_BUNDLE meta1013.cpp fileHandle.cpp fileHandle.h util.cpp util.h)
target_link_libraries(meta1013 fssimplewindow glutil)

add_executable(moveEdge MACOSX_BUNDLE moveEdge.cpp fileHandle.cpp fileHandle.h util.cpp util.h)
target_link_libraries(moveEdge fssimplewindow glutil)

add_executable(makeWire MACOSX_BUNDLE makeWire.cpp fileHandle.cpp fileHandle.h util.cpp util.h)
target_link_libraries(makeWire fssimplewindow glutil)

add_executable(move MACOSX_BUNDLE move.cpp fileHandle.cpp fileHandle.h util.cpp util.h)
target_link_libraries(move fssimplewindow glutil)

add_executable(move2 MACOSX_BUNDLE move2.cpp fileHandle.cpp fileHandle.h util.cpp util.h)
target_link_libraries(move2 fssimplewindow glutil)

# testing file handle
# add_executable(fileHandle MACOSX_BUNDLE fileHandle.cpp)



# set(TARGET_NAME glutil)
# add_library(${TARGET_NAME}
#     glutil.cpp
#     glutil.h
# )%                               

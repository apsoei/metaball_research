add_library(astar astar.cpp astar.h)
target_link_libraries(astar geblkernel)
add_executable(ps8_2 MACOSX_BUNDLE main.cpp glutil.cpp glutil.h)
target_link_libraries(ps8_2 astar fssimplewindow)
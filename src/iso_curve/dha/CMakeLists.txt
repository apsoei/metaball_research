add_library(dha dha.h dha.cpp)
target_link_libraries(dha geblkernel)

add_executable(ps8_1 MACOSX_BUNDLE main.cpp glutil.cpp glutil.h)
target_link_libraries(ps8_1 dha fssimplewindow)
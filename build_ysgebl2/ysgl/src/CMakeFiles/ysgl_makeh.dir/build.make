# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.17.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.17.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jaeseoko/Research/public/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jaeseoko/Research/build_ysgebl2

# Include any dependencies generated for this target.
include ysgl/src/CMakeFiles/ysgl_makeh.dir/depend.make

# Include the progress variables for this target.
include ysgl/src/CMakeFiles/ysgl_makeh.dir/progress.make

# Include the compile flags for this target's objects.
include ysgl/src/CMakeFiles/ysgl_makeh.dir/flags.make

ysgl/src/CMakeFiles/ysgl_makeh.dir/glsl_src/makeh.cpp.o: ysgl/src/CMakeFiles/ysgl_makeh.dir/flags.make
ysgl/src/CMakeFiles/ysgl_makeh.dir/glsl_src/makeh.cpp.o: /Users/jaeseoko/Research/public/src/ysgl/src/glsl_src/makeh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build_ysgebl2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ysgl/src/CMakeFiles/ysgl_makeh.dir/glsl_src/makeh.cpp.o"
	cd /Users/jaeseoko/Research/build_ysgebl2/ysgl/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ysgl_makeh.dir/glsl_src/makeh.cpp.o -c /Users/jaeseoko/Research/public/src/ysgl/src/glsl_src/makeh.cpp

ysgl/src/CMakeFiles/ysgl_makeh.dir/glsl_src/makeh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ysgl_makeh.dir/glsl_src/makeh.cpp.i"
	cd /Users/jaeseoko/Research/build_ysgebl2/ysgl/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/public/src/ysgl/src/glsl_src/makeh.cpp > CMakeFiles/ysgl_makeh.dir/glsl_src/makeh.cpp.i

ysgl/src/CMakeFiles/ysgl_makeh.dir/glsl_src/makeh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ysgl_makeh.dir/glsl_src/makeh.cpp.s"
	cd /Users/jaeseoko/Research/build_ysgebl2/ysgl/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/public/src/ysgl/src/glsl_src/makeh.cpp -o CMakeFiles/ysgl_makeh.dir/glsl_src/makeh.cpp.s

# Object files for target ysgl_makeh
ysgl_makeh_OBJECTS = \
"CMakeFiles/ysgl_makeh.dir/glsl_src/makeh.cpp.o"

# External object files for target ysgl_makeh
ysgl_makeh_EXTERNAL_OBJECTS =

exe/ysgl_makeh: ysgl/src/CMakeFiles/ysgl_makeh.dir/glsl_src/makeh.cpp.o
exe/ysgl_makeh: ysgl/src/CMakeFiles/ysgl_makeh.dir/build.make
exe/ysgl_makeh: ysclass/src/libysclass.a
exe/ysgl_makeh: ysgl/src/CMakeFiles/ysgl_makeh.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jaeseoko/Research/build_ysgebl2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../exe/ysgl_makeh"
	cd /Users/jaeseoko/Research/build_ysgebl2/ysgl/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ysgl_makeh.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ysgl/src/CMakeFiles/ysgl_makeh.dir/build: exe/ysgl_makeh

.PHONY : ysgl/src/CMakeFiles/ysgl_makeh.dir/build

ysgl/src/CMakeFiles/ysgl_makeh.dir/clean:
	cd /Users/jaeseoko/Research/build_ysgebl2/ysgl/src && $(CMAKE_COMMAND) -P CMakeFiles/ysgl_makeh.dir/cmake_clean.cmake
.PHONY : ysgl/src/CMakeFiles/ysgl_makeh.dir/clean

ysgl/src/CMakeFiles/ysgl_makeh.dir/depend:
	cd /Users/jaeseoko/Research/build_ysgebl2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jaeseoko/Research/public/src /Users/jaeseoko/Research/public/src/ysgl/src /Users/jaeseoko/Research/build_ysgebl2 /Users/jaeseoko/Research/build_ysgebl2/ysgl/src /Users/jaeseoko/Research/build_ysgebl2/ysgl/src/CMakeFiles/ysgl_makeh.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ysgl/src/CMakeFiles/ysgl_makeh.dir/depend


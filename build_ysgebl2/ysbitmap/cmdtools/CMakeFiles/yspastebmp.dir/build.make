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
include ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/depend.make

# Include the progress variables for this target.
include ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/progress.make

# Include the compile flags for this target's objects.
include ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/flags.make

ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/yspastebmp.cpp.o: ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/flags.make
ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/yspastebmp.cpp.o: /Users/jaeseoko/Research/public/src/ysbitmap/cmdtools/yspastebmp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build_ysgebl2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/yspastebmp.cpp.o"
	cd /Users/jaeseoko/Research/build_ysgebl2/ysbitmap/cmdtools && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/yspastebmp.dir/yspastebmp.cpp.o -c /Users/jaeseoko/Research/public/src/ysbitmap/cmdtools/yspastebmp.cpp

ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/yspastebmp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yspastebmp.dir/yspastebmp.cpp.i"
	cd /Users/jaeseoko/Research/build_ysgebl2/ysbitmap/cmdtools && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/public/src/ysbitmap/cmdtools/yspastebmp.cpp > CMakeFiles/yspastebmp.dir/yspastebmp.cpp.i

ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/yspastebmp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yspastebmp.dir/yspastebmp.cpp.s"
	cd /Users/jaeseoko/Research/build_ysgebl2/ysbitmap/cmdtools && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/public/src/ysbitmap/cmdtools/yspastebmp.cpp -o CMakeFiles/yspastebmp.dir/yspastebmp.cpp.s

# Object files for target yspastebmp
yspastebmp_OBJECTS = \
"CMakeFiles/yspastebmp.dir/yspastebmp.cpp.o"

# External object files for target yspastebmp
yspastebmp_EXTERNAL_OBJECTS =

ysbitmap/cmdtools/yspastebmp: ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/yspastebmp.cpp.o
ysbitmap/cmdtools/yspastebmp: ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/build.make
ysbitmap/cmdtools/yspastebmp: ysclass/src/libysclass.a
ysbitmap/cmdtools/yspastebmp: ysbitmap/src/libysbitmap.a
ysbitmap/cmdtools/yspastebmp: ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jaeseoko/Research/build_ysgebl2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable yspastebmp"
	cd /Users/jaeseoko/Research/build_ysgebl2/ysbitmap/cmdtools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/yspastebmp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/build: ysbitmap/cmdtools/yspastebmp

.PHONY : ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/build

ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/clean:
	cd /Users/jaeseoko/Research/build_ysgebl2/ysbitmap/cmdtools && $(CMAKE_COMMAND) -P CMakeFiles/yspastebmp.dir/cmake_clean.cmake
.PHONY : ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/clean

ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/depend:
	cd /Users/jaeseoko/Research/build_ysgebl2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jaeseoko/Research/public/src /Users/jaeseoko/Research/public/src/ysbitmap/cmdtools /Users/jaeseoko/Research/build_ysgebl2 /Users/jaeseoko/Research/build_ysgebl2/ysbitmap/cmdtools /Users/jaeseoko/Research/build_ysgebl2/ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/depend


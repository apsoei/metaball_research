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
CMAKE_SOURCE_DIR = /Users/jaeseoko/Research/src/metaball

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jaeseoko/Research/build_3d

# Include any dependencies generated for this target.
include public/ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/depend.make

# Include the progress variables for this target.
include public/ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/progress.make

# Include the compile flags for this target's objects.
include public/ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/flags.make

public/ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/yspastebmp.cpp.o: public/ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/flags.make
public/ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/yspastebmp.cpp.o: /Users/jaeseoko/Research/public/src/ysbitmap/cmdtools/yspastebmp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build_3d/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object public/ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/yspastebmp.cpp.o"
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/cmdtools && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/yspastebmp.dir/yspastebmp.cpp.o -c /Users/jaeseoko/Research/public/src/ysbitmap/cmdtools/yspastebmp.cpp

public/ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/yspastebmp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yspastebmp.dir/yspastebmp.cpp.i"
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/cmdtools && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/public/src/ysbitmap/cmdtools/yspastebmp.cpp > CMakeFiles/yspastebmp.dir/yspastebmp.cpp.i

public/ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/yspastebmp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yspastebmp.dir/yspastebmp.cpp.s"
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/cmdtools && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/public/src/ysbitmap/cmdtools/yspastebmp.cpp -o CMakeFiles/yspastebmp.dir/yspastebmp.cpp.s

# Object files for target yspastebmp
yspastebmp_OBJECTS = \
"CMakeFiles/yspastebmp.dir/yspastebmp.cpp.o"

# External object files for target yspastebmp
yspastebmp_EXTERNAL_OBJECTS =

public/ysbitmap/cmdtools/yspastebmp: public/ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/yspastebmp.cpp.o
public/ysbitmap/cmdtools/yspastebmp: public/ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/build.make
public/ysbitmap/cmdtools/yspastebmp: public/ysclass/src/libysclass.a
public/ysbitmap/cmdtools/yspastebmp: public/ysbitmap/src/libysbitmap.a
public/ysbitmap/cmdtools/yspastebmp: public/ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jaeseoko/Research/build_3d/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable yspastebmp"
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/cmdtools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/yspastebmp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
public/ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/build: public/ysbitmap/cmdtools/yspastebmp

.PHONY : public/ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/build

public/ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/clean:
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/cmdtools && $(CMAKE_COMMAND) -P CMakeFiles/yspastebmp.dir/cmake_clean.cmake
.PHONY : public/ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/clean

public/ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/depend:
	cd /Users/jaeseoko/Research/build_3d && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jaeseoko/Research/src/metaball /Users/jaeseoko/Research/public/src/ysbitmap/cmdtools /Users/jaeseoko/Research/build_3d /Users/jaeseoko/Research/build_3d/public/ysbitmap/cmdtools /Users/jaeseoko/Research/build_3d/public/ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : public/ysbitmap/cmdtools/CMakeFiles/yspastebmp.dir/depend


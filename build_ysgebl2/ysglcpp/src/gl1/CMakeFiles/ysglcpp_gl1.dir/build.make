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
include ysglcpp/src/gl1/CMakeFiles/ysglcpp_gl1.dir/depend.make

# Include the progress variables for this target.
include ysglcpp/src/gl1/CMakeFiles/ysglcpp_gl1.dir/progress.make

# Include the compile flags for this target's objects.
include ysglcpp/src/gl1/CMakeFiles/ysglcpp_gl1.dir/flags.make

ysglcpp/src/gl1/CMakeFiles/ysglcpp_gl1.dir/ysglbuffermanager_gl1.cpp.o: ysglcpp/src/gl1/CMakeFiles/ysglcpp_gl1.dir/flags.make
ysglcpp/src/gl1/CMakeFiles/ysglcpp_gl1.dir/ysglbuffermanager_gl1.cpp.o: /Users/jaeseoko/Research/public/src/ysglcpp/src/gl1/ysglbuffermanager_gl1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build_ysgebl2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ysglcpp/src/gl1/CMakeFiles/ysglcpp_gl1.dir/ysglbuffermanager_gl1.cpp.o"
	cd /Users/jaeseoko/Research/build_ysgebl2/ysglcpp/src/gl1 && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ysglcpp_gl1.dir/ysglbuffermanager_gl1.cpp.o -c /Users/jaeseoko/Research/public/src/ysglcpp/src/gl1/ysglbuffermanager_gl1.cpp

ysglcpp/src/gl1/CMakeFiles/ysglcpp_gl1.dir/ysglbuffermanager_gl1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ysglcpp_gl1.dir/ysglbuffermanager_gl1.cpp.i"
	cd /Users/jaeseoko/Research/build_ysgebl2/ysglcpp/src/gl1 && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/public/src/ysglcpp/src/gl1/ysglbuffermanager_gl1.cpp > CMakeFiles/ysglcpp_gl1.dir/ysglbuffermanager_gl1.cpp.i

ysglcpp/src/gl1/CMakeFiles/ysglcpp_gl1.dir/ysglbuffermanager_gl1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ysglcpp_gl1.dir/ysglbuffermanager_gl1.cpp.s"
	cd /Users/jaeseoko/Research/build_ysgebl2/ysglcpp/src/gl1 && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/public/src/ysglcpp/src/gl1/ysglbuffermanager_gl1.cpp -o CMakeFiles/ysglcpp_gl1.dir/ysglbuffermanager_gl1.cpp.s

# Object files for target ysglcpp_gl1
ysglcpp_gl1_OBJECTS = \
"CMakeFiles/ysglcpp_gl1.dir/ysglbuffermanager_gl1.cpp.o"

# External object files for target ysglcpp_gl1
ysglcpp_gl1_EXTERNAL_OBJECTS =

ysglcpp/src/gl1/libysglcpp_gl1.a: ysglcpp/src/gl1/CMakeFiles/ysglcpp_gl1.dir/ysglbuffermanager_gl1.cpp.o
ysglcpp/src/gl1/libysglcpp_gl1.a: ysglcpp/src/gl1/CMakeFiles/ysglcpp_gl1.dir/build.make
ysglcpp/src/gl1/libysglcpp_gl1.a: ysglcpp/src/gl1/CMakeFiles/ysglcpp_gl1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jaeseoko/Research/build_ysgebl2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libysglcpp_gl1.a"
	cd /Users/jaeseoko/Research/build_ysgebl2/ysglcpp/src/gl1 && $(CMAKE_COMMAND) -P CMakeFiles/ysglcpp_gl1.dir/cmake_clean_target.cmake
	cd /Users/jaeseoko/Research/build_ysgebl2/ysglcpp/src/gl1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ysglcpp_gl1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ysglcpp/src/gl1/CMakeFiles/ysglcpp_gl1.dir/build: ysglcpp/src/gl1/libysglcpp_gl1.a

.PHONY : ysglcpp/src/gl1/CMakeFiles/ysglcpp_gl1.dir/build

ysglcpp/src/gl1/CMakeFiles/ysglcpp_gl1.dir/clean:
	cd /Users/jaeseoko/Research/build_ysgebl2/ysglcpp/src/gl1 && $(CMAKE_COMMAND) -P CMakeFiles/ysglcpp_gl1.dir/cmake_clean.cmake
.PHONY : ysglcpp/src/gl1/CMakeFiles/ysglcpp_gl1.dir/clean

ysglcpp/src/gl1/CMakeFiles/ysglcpp_gl1.dir/depend:
	cd /Users/jaeseoko/Research/build_ysgebl2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jaeseoko/Research/public/src /Users/jaeseoko/Research/public/src/ysglcpp/src/gl1 /Users/jaeseoko/Research/build_ysgebl2 /Users/jaeseoko/Research/build_ysgebl2/ysglcpp/src/gl1 /Users/jaeseoko/Research/build_ysgebl2/ysglcpp/src/gl1/CMakeFiles/ysglcpp_gl1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ysglcpp/src/gl1/CMakeFiles/ysglcpp_gl1.dir/depend


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
include ystexturemanager/src/CMakeFiles/ystexturemanager.dir/depend.make

# Include the progress variables for this target.
include ystexturemanager/src/CMakeFiles/ystexturemanager.dir/progress.make

# Include the compile flags for this target's objects.
include ystexturemanager/src/CMakeFiles/ystexturemanager.dir/flags.make

ystexturemanager/src/CMakeFiles/ystexturemanager.dir/ystexturemanager.cpp.o: ystexturemanager/src/CMakeFiles/ystexturemanager.dir/flags.make
ystexturemanager/src/CMakeFiles/ystexturemanager.dir/ystexturemanager.cpp.o: /Users/jaeseoko/Research/public/src/ystexturemanager/src/ystexturemanager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build_ysgebl2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ystexturemanager/src/CMakeFiles/ystexturemanager.dir/ystexturemanager.cpp.o"
	cd /Users/jaeseoko/Research/build_ysgebl2/ystexturemanager/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ystexturemanager.dir/ystexturemanager.cpp.o -c /Users/jaeseoko/Research/public/src/ystexturemanager/src/ystexturemanager.cpp

ystexturemanager/src/CMakeFiles/ystexturemanager.dir/ystexturemanager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ystexturemanager.dir/ystexturemanager.cpp.i"
	cd /Users/jaeseoko/Research/build_ysgebl2/ystexturemanager/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/public/src/ystexturemanager/src/ystexturemanager.cpp > CMakeFiles/ystexturemanager.dir/ystexturemanager.cpp.i

ystexturemanager/src/CMakeFiles/ystexturemanager.dir/ystexturemanager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ystexturemanager.dir/ystexturemanager.cpp.s"
	cd /Users/jaeseoko/Research/build_ysgebl2/ystexturemanager/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/public/src/ystexturemanager/src/ystexturemanager.cpp -o CMakeFiles/ystexturemanager.dir/ystexturemanager.cpp.s

# Object files for target ystexturemanager
ystexturemanager_OBJECTS = \
"CMakeFiles/ystexturemanager.dir/ystexturemanager.cpp.o"

# External object files for target ystexturemanager
ystexturemanager_EXTERNAL_OBJECTS =

ystexturemanager/src/libystexturemanager.a: ystexturemanager/src/CMakeFiles/ystexturemanager.dir/ystexturemanager.cpp.o
ystexturemanager/src/libystexturemanager.a: ystexturemanager/src/CMakeFiles/ystexturemanager.dir/build.make
ystexturemanager/src/libystexturemanager.a: ystexturemanager/src/CMakeFiles/ystexturemanager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jaeseoko/Research/build_ysgebl2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libystexturemanager.a"
	cd /Users/jaeseoko/Research/build_ysgebl2/ystexturemanager/src && $(CMAKE_COMMAND) -P CMakeFiles/ystexturemanager.dir/cmake_clean_target.cmake
	cd /Users/jaeseoko/Research/build_ysgebl2/ystexturemanager/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ystexturemanager.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ystexturemanager/src/CMakeFiles/ystexturemanager.dir/build: ystexturemanager/src/libystexturemanager.a

.PHONY : ystexturemanager/src/CMakeFiles/ystexturemanager.dir/build

ystexturemanager/src/CMakeFiles/ystexturemanager.dir/clean:
	cd /Users/jaeseoko/Research/build_ysgebl2/ystexturemanager/src && $(CMAKE_COMMAND) -P CMakeFiles/ystexturemanager.dir/cmake_clean.cmake
.PHONY : ystexturemanager/src/CMakeFiles/ystexturemanager.dir/clean

ystexturemanager/src/CMakeFiles/ystexturemanager.dir/depend:
	cd /Users/jaeseoko/Research/build_ysgebl2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jaeseoko/Research/public/src /Users/jaeseoko/Research/public/src/ystexturemanager/src /Users/jaeseoko/Research/build_ysgebl2 /Users/jaeseoko/Research/build_ysgebl2/ystexturemanager/src /Users/jaeseoko/Research/build_ysgebl2/ystexturemanager/src/CMakeFiles/ystexturemanager.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ystexturemanager/src/CMakeFiles/ystexturemanager.dir/depend


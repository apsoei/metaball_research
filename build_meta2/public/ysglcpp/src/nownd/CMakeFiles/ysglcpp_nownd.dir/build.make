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
CMAKE_BINARY_DIR = /Users/jaeseoko/Research/build_meta2

# Include any dependencies generated for this target.
include public/ysglcpp/src/nownd/CMakeFiles/ysglcpp_nownd.dir/depend.make

# Include the progress variables for this target.
include public/ysglcpp/src/nownd/CMakeFiles/ysglcpp_nownd.dir/progress.make

# Include the compile flags for this target's objects.
include public/ysglcpp/src/nownd/CMakeFiles/ysglcpp_nownd.dir/flags.make

public/ysglcpp/src/nownd/CMakeFiles/ysglcpp_nownd.dir/ysglbuffermanager_nownd.cpp.o: public/ysglcpp/src/nownd/CMakeFiles/ysglcpp_nownd.dir/flags.make
public/ysglcpp/src/nownd/CMakeFiles/ysglcpp_nownd.dir/ysglbuffermanager_nownd.cpp.o: /Users/jaeseoko/Research/public/src/ysglcpp/src/nownd/ysglbuffermanager_nownd.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build_meta2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object public/ysglcpp/src/nownd/CMakeFiles/ysglcpp_nownd.dir/ysglbuffermanager_nownd.cpp.o"
	cd /Users/jaeseoko/Research/build_meta2/public/ysglcpp/src/nownd && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ysglcpp_nownd.dir/ysglbuffermanager_nownd.cpp.o -c /Users/jaeseoko/Research/public/src/ysglcpp/src/nownd/ysglbuffermanager_nownd.cpp

public/ysglcpp/src/nownd/CMakeFiles/ysglcpp_nownd.dir/ysglbuffermanager_nownd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ysglcpp_nownd.dir/ysglbuffermanager_nownd.cpp.i"
	cd /Users/jaeseoko/Research/build_meta2/public/ysglcpp/src/nownd && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/public/src/ysglcpp/src/nownd/ysglbuffermanager_nownd.cpp > CMakeFiles/ysglcpp_nownd.dir/ysglbuffermanager_nownd.cpp.i

public/ysglcpp/src/nownd/CMakeFiles/ysglcpp_nownd.dir/ysglbuffermanager_nownd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ysglcpp_nownd.dir/ysglbuffermanager_nownd.cpp.s"
	cd /Users/jaeseoko/Research/build_meta2/public/ysglcpp/src/nownd && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/public/src/ysglcpp/src/nownd/ysglbuffermanager_nownd.cpp -o CMakeFiles/ysglcpp_nownd.dir/ysglbuffermanager_nownd.cpp.s

# Object files for target ysglcpp_nownd
ysglcpp_nownd_OBJECTS = \
"CMakeFiles/ysglcpp_nownd.dir/ysglbuffermanager_nownd.cpp.o"

# External object files for target ysglcpp_nownd
ysglcpp_nownd_EXTERNAL_OBJECTS =

public/ysglcpp/src/nownd/libysglcpp_nownd.a: public/ysglcpp/src/nownd/CMakeFiles/ysglcpp_nownd.dir/ysglbuffermanager_nownd.cpp.o
public/ysglcpp/src/nownd/libysglcpp_nownd.a: public/ysglcpp/src/nownd/CMakeFiles/ysglcpp_nownd.dir/build.make
public/ysglcpp/src/nownd/libysglcpp_nownd.a: public/ysglcpp/src/nownd/CMakeFiles/ysglcpp_nownd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jaeseoko/Research/build_meta2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libysglcpp_nownd.a"
	cd /Users/jaeseoko/Research/build_meta2/public/ysglcpp/src/nownd && $(CMAKE_COMMAND) -P CMakeFiles/ysglcpp_nownd.dir/cmake_clean_target.cmake
	cd /Users/jaeseoko/Research/build_meta2/public/ysglcpp/src/nownd && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ysglcpp_nownd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
public/ysglcpp/src/nownd/CMakeFiles/ysglcpp_nownd.dir/build: public/ysglcpp/src/nownd/libysglcpp_nownd.a

.PHONY : public/ysglcpp/src/nownd/CMakeFiles/ysglcpp_nownd.dir/build

public/ysglcpp/src/nownd/CMakeFiles/ysglcpp_nownd.dir/clean:
	cd /Users/jaeseoko/Research/build_meta2/public/ysglcpp/src/nownd && $(CMAKE_COMMAND) -P CMakeFiles/ysglcpp_nownd.dir/cmake_clean.cmake
.PHONY : public/ysglcpp/src/nownd/CMakeFiles/ysglcpp_nownd.dir/clean

public/ysglcpp/src/nownd/CMakeFiles/ysglcpp_nownd.dir/depend:
	cd /Users/jaeseoko/Research/build_meta2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jaeseoko/Research/src/metaball /Users/jaeseoko/Research/public/src/ysglcpp/src/nownd /Users/jaeseoko/Research/build_meta2 /Users/jaeseoko/Research/build_meta2/public/ysglcpp/src/nownd /Users/jaeseoko/Research/build_meta2/public/ysglcpp/src/nownd/CMakeFiles/ysglcpp_nownd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : public/ysglcpp/src/nownd/CMakeFiles/ysglcpp_nownd.dir/depend


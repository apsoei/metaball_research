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
include public/ysbitmap/src/CMakeFiles/ysbitmap.dir/depend.make

# Include the progress variables for this target.
include public/ysbitmap/src/CMakeFiles/ysbitmap.dir/progress.make

# Include the compile flags for this target's objects.
include public/ysbitmap/src/CMakeFiles/ysbitmap.dir/flags.make

public/ysbitmap/src/CMakeFiles/ysbitmap.dir/ysbitmap.cpp.o: public/ysbitmap/src/CMakeFiles/ysbitmap.dir/flags.make
public/ysbitmap/src/CMakeFiles/ysbitmap.dir/ysbitmap.cpp.o: /Users/jaeseoko/Research/public/src/ysbitmap/src/ysbitmap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build_3d/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object public/ysbitmap/src/CMakeFiles/ysbitmap.dir/ysbitmap.cpp.o"
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ysbitmap.dir/ysbitmap.cpp.o -c /Users/jaeseoko/Research/public/src/ysbitmap/src/ysbitmap.cpp

public/ysbitmap/src/CMakeFiles/ysbitmap.dir/ysbitmap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ysbitmap.dir/ysbitmap.cpp.i"
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/public/src/ysbitmap/src/ysbitmap.cpp > CMakeFiles/ysbitmap.dir/ysbitmap.cpp.i

public/ysbitmap/src/CMakeFiles/ysbitmap.dir/ysbitmap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ysbitmap.dir/ysbitmap.cpp.s"
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/public/src/ysbitmap/src/ysbitmap.cpp -o CMakeFiles/ysbitmap.dir/ysbitmap.cpp.s

public/ysbitmap/src/CMakeFiles/ysbitmap.dir/ysbitmaparray.cpp.o: public/ysbitmap/src/CMakeFiles/ysbitmap.dir/flags.make
public/ysbitmap/src/CMakeFiles/ysbitmap.dir/ysbitmaparray.cpp.o: /Users/jaeseoko/Research/public/src/ysbitmap/src/ysbitmaparray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build_3d/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object public/ysbitmap/src/CMakeFiles/ysbitmap.dir/ysbitmaparray.cpp.o"
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ysbitmap.dir/ysbitmaparray.cpp.o -c /Users/jaeseoko/Research/public/src/ysbitmap/src/ysbitmaparray.cpp

public/ysbitmap/src/CMakeFiles/ysbitmap.dir/ysbitmaparray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ysbitmap.dir/ysbitmaparray.cpp.i"
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/public/src/ysbitmap/src/ysbitmaparray.cpp > CMakeFiles/ysbitmap.dir/ysbitmaparray.cpp.i

public/ysbitmap/src/CMakeFiles/ysbitmap.dir/ysbitmaparray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ysbitmap.dir/ysbitmaparray.cpp.s"
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/public/src/ysbitmap/src/ysbitmaparray.cpp -o CMakeFiles/ysbitmap.dir/ysbitmaparray.cpp.s

public/ysbitmap/src/CMakeFiles/ysbitmap.dir/ysbitmappngif.cpp.o: public/ysbitmap/src/CMakeFiles/ysbitmap.dir/flags.make
public/ysbitmap/src/CMakeFiles/ysbitmap.dir/ysbitmappngif.cpp.o: /Users/jaeseoko/Research/public/src/ysbitmap/src/ysbitmappngif.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build_3d/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object public/ysbitmap/src/CMakeFiles/ysbitmap.dir/ysbitmappngif.cpp.o"
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ysbitmap.dir/ysbitmappngif.cpp.o -c /Users/jaeseoko/Research/public/src/ysbitmap/src/ysbitmappngif.cpp

public/ysbitmap/src/CMakeFiles/ysbitmap.dir/ysbitmappngif.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ysbitmap.dir/ysbitmappngif.cpp.i"
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/public/src/ysbitmap/src/ysbitmappngif.cpp > CMakeFiles/ysbitmap.dir/ysbitmappngif.cpp.i

public/ysbitmap/src/CMakeFiles/ysbitmap.dir/ysbitmappngif.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ysbitmap.dir/ysbitmappngif.cpp.s"
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/public/src/ysbitmap/src/ysbitmappngif.cpp -o CMakeFiles/ysbitmap.dir/ysbitmappngif.cpp.s

public/ysbitmap/src/CMakeFiles/ysbitmap.dir/yspng.cpp.o: public/ysbitmap/src/CMakeFiles/ysbitmap.dir/flags.make
public/ysbitmap/src/CMakeFiles/ysbitmap.dir/yspng.cpp.o: /Users/jaeseoko/Research/public/src/ysbitmap/src/yspng.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build_3d/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object public/ysbitmap/src/CMakeFiles/ysbitmap.dir/yspng.cpp.o"
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ysbitmap.dir/yspng.cpp.o -c /Users/jaeseoko/Research/public/src/ysbitmap/src/yspng.cpp

public/ysbitmap/src/CMakeFiles/ysbitmap.dir/yspng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ysbitmap.dir/yspng.cpp.i"
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/public/src/ysbitmap/src/yspng.cpp > CMakeFiles/ysbitmap.dir/yspng.cpp.i

public/ysbitmap/src/CMakeFiles/ysbitmap.dir/yspng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ysbitmap.dir/yspng.cpp.s"
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/public/src/ysbitmap/src/yspng.cpp -o CMakeFiles/ysbitmap.dir/yspng.cpp.s

public/ysbitmap/src/CMakeFiles/ysbitmap.dir/yspngenc.cpp.o: public/ysbitmap/src/CMakeFiles/ysbitmap.dir/flags.make
public/ysbitmap/src/CMakeFiles/ysbitmap.dir/yspngenc.cpp.o: /Users/jaeseoko/Research/public/src/ysbitmap/src/yspngenc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build_3d/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object public/ysbitmap/src/CMakeFiles/ysbitmap.dir/yspngenc.cpp.o"
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ysbitmap.dir/yspngenc.cpp.o -c /Users/jaeseoko/Research/public/src/ysbitmap/src/yspngenc.cpp

public/ysbitmap/src/CMakeFiles/ysbitmap.dir/yspngenc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ysbitmap.dir/yspngenc.cpp.i"
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/public/src/ysbitmap/src/yspngenc.cpp > CMakeFiles/ysbitmap.dir/yspngenc.cpp.i

public/ysbitmap/src/CMakeFiles/ysbitmap.dir/yspngenc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ysbitmap.dir/yspngenc.cpp.s"
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/public/src/ysbitmap/src/yspngenc.cpp -o CMakeFiles/ysbitmap.dir/yspngenc.cpp.s

# Object files for target ysbitmap
ysbitmap_OBJECTS = \
"CMakeFiles/ysbitmap.dir/ysbitmap.cpp.o" \
"CMakeFiles/ysbitmap.dir/ysbitmaparray.cpp.o" \
"CMakeFiles/ysbitmap.dir/ysbitmappngif.cpp.o" \
"CMakeFiles/ysbitmap.dir/yspng.cpp.o" \
"CMakeFiles/ysbitmap.dir/yspngenc.cpp.o"

# External object files for target ysbitmap
ysbitmap_EXTERNAL_OBJECTS =

public/ysbitmap/src/libysbitmap.a: public/ysbitmap/src/CMakeFiles/ysbitmap.dir/ysbitmap.cpp.o
public/ysbitmap/src/libysbitmap.a: public/ysbitmap/src/CMakeFiles/ysbitmap.dir/ysbitmaparray.cpp.o
public/ysbitmap/src/libysbitmap.a: public/ysbitmap/src/CMakeFiles/ysbitmap.dir/ysbitmappngif.cpp.o
public/ysbitmap/src/libysbitmap.a: public/ysbitmap/src/CMakeFiles/ysbitmap.dir/yspng.cpp.o
public/ysbitmap/src/libysbitmap.a: public/ysbitmap/src/CMakeFiles/ysbitmap.dir/yspngenc.cpp.o
public/ysbitmap/src/libysbitmap.a: public/ysbitmap/src/CMakeFiles/ysbitmap.dir/build.make
public/ysbitmap/src/libysbitmap.a: public/ysbitmap/src/CMakeFiles/ysbitmap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jaeseoko/Research/build_3d/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libysbitmap.a"
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/src && $(CMAKE_COMMAND) -P CMakeFiles/ysbitmap.dir/cmake_clean_target.cmake
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ysbitmap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
public/ysbitmap/src/CMakeFiles/ysbitmap.dir/build: public/ysbitmap/src/libysbitmap.a

.PHONY : public/ysbitmap/src/CMakeFiles/ysbitmap.dir/build

public/ysbitmap/src/CMakeFiles/ysbitmap.dir/clean:
	cd /Users/jaeseoko/Research/build_3d/public/ysbitmap/src && $(CMAKE_COMMAND) -P CMakeFiles/ysbitmap.dir/cmake_clean.cmake
.PHONY : public/ysbitmap/src/CMakeFiles/ysbitmap.dir/clean

public/ysbitmap/src/CMakeFiles/ysbitmap.dir/depend:
	cd /Users/jaeseoko/Research/build_3d && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jaeseoko/Research/src/metaball /Users/jaeseoko/Research/public/src/ysbitmap/src /Users/jaeseoko/Research/build_3d /Users/jaeseoko/Research/build_3d/public/ysbitmap/src /Users/jaeseoko/Research/build_3d/public/ysbitmap/src/CMakeFiles/ysbitmap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : public/ysbitmap/src/CMakeFiles/ysbitmap.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.21.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.21.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jaeseoko/Research/src/metaball

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jaeseoko/Research/testBuild

# Include any dependencies generated for this target.
include CMakeFiles/makeWire.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/makeWire.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/makeWire.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/makeWire.dir/flags.make

CMakeFiles/makeWire.dir/makeWire.cpp.o: CMakeFiles/makeWire.dir/flags.make
CMakeFiles/makeWire.dir/makeWire.cpp.o: /Users/jaeseoko/Research/src/metaball/makeWire.cpp
CMakeFiles/makeWire.dir/makeWire.cpp.o: CMakeFiles/makeWire.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/testBuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/makeWire.dir/makeWire.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/makeWire.dir/makeWire.cpp.o -MF CMakeFiles/makeWire.dir/makeWire.cpp.o.d -o CMakeFiles/makeWire.dir/makeWire.cpp.o -c /Users/jaeseoko/Research/src/metaball/makeWire.cpp

CMakeFiles/makeWire.dir/makeWire.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/makeWire.dir/makeWire.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/src/metaball/makeWire.cpp > CMakeFiles/makeWire.dir/makeWire.cpp.i

CMakeFiles/makeWire.dir/makeWire.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/makeWire.dir/makeWire.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/src/metaball/makeWire.cpp -o CMakeFiles/makeWire.dir/makeWire.cpp.s

CMakeFiles/makeWire.dir/fileHandle.cpp.o: CMakeFiles/makeWire.dir/flags.make
CMakeFiles/makeWire.dir/fileHandle.cpp.o: /Users/jaeseoko/Research/src/metaball/fileHandle.cpp
CMakeFiles/makeWire.dir/fileHandle.cpp.o: CMakeFiles/makeWire.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/testBuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/makeWire.dir/fileHandle.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/makeWire.dir/fileHandle.cpp.o -MF CMakeFiles/makeWire.dir/fileHandle.cpp.o.d -o CMakeFiles/makeWire.dir/fileHandle.cpp.o -c /Users/jaeseoko/Research/src/metaball/fileHandle.cpp

CMakeFiles/makeWire.dir/fileHandle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/makeWire.dir/fileHandle.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/src/metaball/fileHandle.cpp > CMakeFiles/makeWire.dir/fileHandle.cpp.i

CMakeFiles/makeWire.dir/fileHandle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/makeWire.dir/fileHandle.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/src/metaball/fileHandle.cpp -o CMakeFiles/makeWire.dir/fileHandle.cpp.s

CMakeFiles/makeWire.dir/util.cpp.o: CMakeFiles/makeWire.dir/flags.make
CMakeFiles/makeWire.dir/util.cpp.o: /Users/jaeseoko/Research/src/metaball/util.cpp
CMakeFiles/makeWire.dir/util.cpp.o: CMakeFiles/makeWire.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/testBuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/makeWire.dir/util.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/makeWire.dir/util.cpp.o -MF CMakeFiles/makeWire.dir/util.cpp.o.d -o CMakeFiles/makeWire.dir/util.cpp.o -c /Users/jaeseoko/Research/src/metaball/util.cpp

CMakeFiles/makeWire.dir/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/makeWire.dir/util.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/src/metaball/util.cpp > CMakeFiles/makeWire.dir/util.cpp.i

CMakeFiles/makeWire.dir/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/makeWire.dir/util.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/src/metaball/util.cpp -o CMakeFiles/makeWire.dir/util.cpp.s

# Object files for target makeWire
makeWire_OBJECTS = \
"CMakeFiles/makeWire.dir/makeWire.cpp.o" \
"CMakeFiles/makeWire.dir/fileHandle.cpp.o" \
"CMakeFiles/makeWire.dir/util.cpp.o"

# External object files for target makeWire
makeWire_EXTERNAL_OBJECTS =

makeWire.app/Contents/MacOS/makeWire: CMakeFiles/makeWire.dir/makeWire.cpp.o
makeWire.app/Contents/MacOS/makeWire: CMakeFiles/makeWire.dir/fileHandle.cpp.o
makeWire.app/Contents/MacOS/makeWire: CMakeFiles/makeWire.dir/util.cpp.o
makeWire.app/Contents/MacOS/makeWire: CMakeFiles/makeWire.dir/build.make
makeWire.app/Contents/MacOS/makeWire: public/fssimplewindow/src/libfssimplewindow.a
makeWire.app/Contents/MacOS/makeWire: libglutil.a
makeWire.app/Contents/MacOS/makeWire: public/ysclass/src/libysclass.a
makeWire.app/Contents/MacOS/makeWire: CMakeFiles/makeWire.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jaeseoko/Research/testBuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable makeWire.app/Contents/MacOS/makeWire"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/makeWire.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/makeWire.dir/build: makeWire.app/Contents/MacOS/makeWire
.PHONY : CMakeFiles/makeWire.dir/build

CMakeFiles/makeWire.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/makeWire.dir/cmake_clean.cmake
.PHONY : CMakeFiles/makeWire.dir/clean

CMakeFiles/makeWire.dir/depend:
	cd /Users/jaeseoko/Research/testBuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jaeseoko/Research/src/metaball /Users/jaeseoko/Research/src/metaball /Users/jaeseoko/Research/testBuild /Users/jaeseoko/Research/testBuild /Users/jaeseoko/Research/testBuild/CMakeFiles/makeWire.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/makeWire.dir/depend


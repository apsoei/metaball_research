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
CMAKE_BINARY_DIR = /Users/jaeseoko/Research/build_current

# Include any dependencies generated for this target.
include CMakeFiles/move.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/move.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/move.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/move.dir/flags.make

CMakeFiles/move.dir/move.cpp.o: CMakeFiles/move.dir/flags.make
CMakeFiles/move.dir/move.cpp.o: /Users/jaeseoko/Research/src/metaball/move.cpp
CMakeFiles/move.dir/move.cpp.o: CMakeFiles/move.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build_current/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/move.dir/move.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/move.dir/move.cpp.o -MF CMakeFiles/move.dir/move.cpp.o.d -o CMakeFiles/move.dir/move.cpp.o -c /Users/jaeseoko/Research/src/metaball/move.cpp

CMakeFiles/move.dir/move.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/move.dir/move.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/src/metaball/move.cpp > CMakeFiles/move.dir/move.cpp.i

CMakeFiles/move.dir/move.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/move.dir/move.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/src/metaball/move.cpp -o CMakeFiles/move.dir/move.cpp.s

CMakeFiles/move.dir/fileHandle.cpp.o: CMakeFiles/move.dir/flags.make
CMakeFiles/move.dir/fileHandle.cpp.o: /Users/jaeseoko/Research/src/metaball/fileHandle.cpp
CMakeFiles/move.dir/fileHandle.cpp.o: CMakeFiles/move.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build_current/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/move.dir/fileHandle.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/move.dir/fileHandle.cpp.o -MF CMakeFiles/move.dir/fileHandle.cpp.o.d -o CMakeFiles/move.dir/fileHandle.cpp.o -c /Users/jaeseoko/Research/src/metaball/fileHandle.cpp

CMakeFiles/move.dir/fileHandle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/move.dir/fileHandle.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/src/metaball/fileHandle.cpp > CMakeFiles/move.dir/fileHandle.cpp.i

CMakeFiles/move.dir/fileHandle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/move.dir/fileHandle.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/src/metaball/fileHandle.cpp -o CMakeFiles/move.dir/fileHandle.cpp.s

CMakeFiles/move.dir/util.cpp.o: CMakeFiles/move.dir/flags.make
CMakeFiles/move.dir/util.cpp.o: /Users/jaeseoko/Research/src/metaball/util.cpp
CMakeFiles/move.dir/util.cpp.o: CMakeFiles/move.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build_current/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/move.dir/util.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/move.dir/util.cpp.o -MF CMakeFiles/move.dir/util.cpp.o.d -o CMakeFiles/move.dir/util.cpp.o -c /Users/jaeseoko/Research/src/metaball/util.cpp

CMakeFiles/move.dir/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/move.dir/util.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/src/metaball/util.cpp > CMakeFiles/move.dir/util.cpp.i

CMakeFiles/move.dir/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/move.dir/util.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/src/metaball/util.cpp -o CMakeFiles/move.dir/util.cpp.s

# Object files for target move
move_OBJECTS = \
"CMakeFiles/move.dir/move.cpp.o" \
"CMakeFiles/move.dir/fileHandle.cpp.o" \
"CMakeFiles/move.dir/util.cpp.o"

# External object files for target move
move_EXTERNAL_OBJECTS =

move.app/Contents/MacOS/move: CMakeFiles/move.dir/move.cpp.o
move.app/Contents/MacOS/move: CMakeFiles/move.dir/fileHandle.cpp.o
move.app/Contents/MacOS/move: CMakeFiles/move.dir/util.cpp.o
move.app/Contents/MacOS/move: CMakeFiles/move.dir/build.make
move.app/Contents/MacOS/move: public/fssimplewindow/src/libfssimplewindow.a
move.app/Contents/MacOS/move: libglutil.a
move.app/Contents/MacOS/move: public/ysclass/src/libysclass.a
move.app/Contents/MacOS/move: CMakeFiles/move.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jaeseoko/Research/build_current/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable move.app/Contents/MacOS/move"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/move.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/move.dir/build: move.app/Contents/MacOS/move
.PHONY : CMakeFiles/move.dir/build

CMakeFiles/move.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/move.dir/cmake_clean.cmake
.PHONY : CMakeFiles/move.dir/clean

CMakeFiles/move.dir/depend:
	cd /Users/jaeseoko/Research/build_current && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jaeseoko/Research/src/metaball /Users/jaeseoko/Research/src/metaball /Users/jaeseoko/Research/build_current /Users/jaeseoko/Research/build_current /Users/jaeseoko/Research/build_current/CMakeFiles/move.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/move.dir/depend

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
include public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/compiler_depend.make

# Include the progress variables for this target.
include public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/progress.make

# Include the compile flags for this target's objects.
include public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/flags.make

public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/cheaputil.cpp.o: public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/flags.make
public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/cheaputil.cpp.o: /Users/jaeseoko/Research/public/src/ir_transceiver/lib/cheaplib/cheaputil.cpp
public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/cheaputil.cpp.o: public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build_current/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/cheaputil.cpp.o"
	cd /Users/jaeseoko/Research/build_current/public/ir_transceiver/lib/cheaplib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/cheaputil.cpp.o -MF CMakeFiles/cheaplib.dir/cheaputil.cpp.o.d -o CMakeFiles/cheaplib.dir/cheaputil.cpp.o -c /Users/jaeseoko/Research/public/src/ir_transceiver/lib/cheaplib/cheaputil.cpp

public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/cheaputil.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cheaplib.dir/cheaputil.cpp.i"
	cd /Users/jaeseoko/Research/build_current/public/ir_transceiver/lib/cheaplib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/public/src/ir_transceiver/lib/cheaplib/cheaputil.cpp > CMakeFiles/cheaplib.dir/cheaputil.cpp.i

public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/cheaputil.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cheaplib.dir/cheaputil.cpp.s"
	cd /Users/jaeseoko/Research/build_current/public/ir_transceiver/lib/cheaplib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/public/src/ir_transceiver/lib/cheaplib/cheaputil.cpp -o CMakeFiles/cheaplib.dir/cheaputil.cpp.s

# Object files for target cheaplib
cheaplib_OBJECTS = \
"CMakeFiles/cheaplib.dir/cheaputil.cpp.o"

# External object files for target cheaplib
cheaplib_EXTERNAL_OBJECTS =

public/ir_transceiver/lib/cheaplib/libcheaplib.a: public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/cheaputil.cpp.o
public/ir_transceiver/lib/cheaplib/libcheaplib.a: public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/build.make
public/ir_transceiver/lib/cheaplib/libcheaplib.a: public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jaeseoko/Research/build_current/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcheaplib.a"
	cd /Users/jaeseoko/Research/build_current/public/ir_transceiver/lib/cheaplib && $(CMAKE_COMMAND) -P CMakeFiles/cheaplib.dir/cmake_clean_target.cmake
	cd /Users/jaeseoko/Research/build_current/public/ir_transceiver/lib/cheaplib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cheaplib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/build: public/ir_transceiver/lib/cheaplib/libcheaplib.a
.PHONY : public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/build

public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/clean:
	cd /Users/jaeseoko/Research/build_current/public/ir_transceiver/lib/cheaplib && $(CMAKE_COMMAND) -P CMakeFiles/cheaplib.dir/cmake_clean.cmake
.PHONY : public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/clean

public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/depend:
	cd /Users/jaeseoko/Research/build_current && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jaeseoko/Research/src/metaball /Users/jaeseoko/Research/public/src/ir_transceiver/lib/cheaplib /Users/jaeseoko/Research/build_current /Users/jaeseoko/Research/build_current/public/ir_transceiver/lib/cheaplib /Users/jaeseoko/Research/build_current/public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : public/ir_transceiver/lib/cheaplib/CMakeFiles/cheaplib.dir/depend


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
CMAKE_BINARY_DIR = /Users/jaeseoko/Research/build2

# Include any dependencies generated for this target.
include public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/compiler_depend.make

# Include the progress variables for this target.
include public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/progress.make

# Include the compile flags for this target's objects.
include public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/flags.make

public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_cpp.cpp.o: public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/flags.make
public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_cpp.cpp.o: /Users/jaeseoko/Research/public/src/yssimplesound/src/macosx/yssimplesound_macosx_cpp.cpp
public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_cpp.cpp.o: public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_cpp.cpp.o"
	cd /Users/jaeseoko/Research/build2/public/yssimplesound/src/macosx && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_cpp.cpp.o -MF CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_cpp.cpp.o.d -o CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_cpp.cpp.o -c /Users/jaeseoko/Research/public/src/yssimplesound/src/macosx/yssimplesound_macosx_cpp.cpp

public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_cpp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_cpp.cpp.i"
	cd /Users/jaeseoko/Research/build2/public/yssimplesound/src/macosx && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/public/src/yssimplesound/src/macosx/yssimplesound_macosx_cpp.cpp > CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_cpp.cpp.i

public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_cpp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_cpp.cpp.s"
	cd /Users/jaeseoko/Research/build2/public/yssimplesound/src/macosx && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/public/src/yssimplesound/src/macosx/yssimplesound_macosx_cpp.cpp -o CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_cpp.cpp.s

public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_objc.m.o: public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/flags.make
public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_objc.m.o: /Users/jaeseoko/Research/public/src/yssimplesound/src/macosx/yssimplesound_macosx_objc.m
public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_objc.m.o: public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_objc.m.o"
	cd /Users/jaeseoko/Research/build2/public/yssimplesound/src/macosx && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_objc.m.o -MF CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_objc.m.o.d -o CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_objc.m.o -c /Users/jaeseoko/Research/public/src/yssimplesound/src/macosx/yssimplesound_macosx_objc.m

public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_objc.m.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_objc.m.i"
	cd /Users/jaeseoko/Research/build2/public/yssimplesound/src/macosx && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jaeseoko/Research/public/src/yssimplesound/src/macosx/yssimplesound_macosx_objc.m > CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_objc.m.i

public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_objc.m.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_objc.m.s"
	cd /Users/jaeseoko/Research/build2/public/yssimplesound/src/macosx && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jaeseoko/Research/public/src/yssimplesound/src/macosx/yssimplesound_macosx_objc.m -o CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_objc.m.s

# Object files for target yssimplesound_macosx
yssimplesound_macosx_OBJECTS = \
"CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_cpp.cpp.o" \
"CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_objc.m.o"

# External object files for target yssimplesound_macosx
yssimplesound_macosx_EXTERNAL_OBJECTS =

public/yssimplesound/src/macosx/libyssimplesound_macosx.a: public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_cpp.cpp.o
public/yssimplesound/src/macosx/libyssimplesound_macosx.a: public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/yssimplesound_macosx_objc.m.o
public/yssimplesound/src/macosx/libyssimplesound_macosx.a: public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/build.make
public/yssimplesound/src/macosx/libyssimplesound_macosx.a: public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jaeseoko/Research/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libyssimplesound_macosx.a"
	cd /Users/jaeseoko/Research/build2/public/yssimplesound/src/macosx && $(CMAKE_COMMAND) -P CMakeFiles/yssimplesound_macosx.dir/cmake_clean_target.cmake
	cd /Users/jaeseoko/Research/build2/public/yssimplesound/src/macosx && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/yssimplesound_macosx.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/build: public/yssimplesound/src/macosx/libyssimplesound_macosx.a
.PHONY : public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/build

public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/clean:
	cd /Users/jaeseoko/Research/build2/public/yssimplesound/src/macosx && $(CMAKE_COMMAND) -P CMakeFiles/yssimplesound_macosx.dir/cmake_clean.cmake
.PHONY : public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/clean

public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/depend:
	cd /Users/jaeseoko/Research/build2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jaeseoko/Research/src/metaball /Users/jaeseoko/Research/public/src/yssimplesound/src/macosx /Users/jaeseoko/Research/build2 /Users/jaeseoko/Research/build2/public/yssimplesound/src/macosx /Users/jaeseoko/Research/build2/public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : public/yssimplesound/src/macosx/CMakeFiles/yssimplesound_macosx.dir/depend


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
include public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/compiler_depend.make

# Include the progress variables for this target.
include public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/progress.make

# Include the compile flags for this target's objects.
include public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/flags.make

public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/test.cpp.o: public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/flags.make
public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/test.cpp.o: /Users/jaeseoko/Research/public/src/yssimplesound/test/test.cpp
public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/test.cpp.o: public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build_current/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/test.cpp.o"
	cd /Users/jaeseoko/Research/build_current/public/yssimplesound/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/test.cpp.o -MF CMakeFiles/yssimplesound_test.dir/test.cpp.o.d -o CMakeFiles/yssimplesound_test.dir/test.cpp.o -c /Users/jaeseoko/Research/public/src/yssimplesound/test/test.cpp

public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yssimplesound_test.dir/test.cpp.i"
	cd /Users/jaeseoko/Research/build_current/public/yssimplesound/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/public/src/yssimplesound/test/test.cpp > CMakeFiles/yssimplesound_test.dir/test.cpp.i

public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yssimplesound_test.dir/test.cpp.s"
	cd /Users/jaeseoko/Research/build_current/public/yssimplesound/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/public/src/yssimplesound/test/test.cpp -o CMakeFiles/yssimplesound_test.dir/test.cpp.s

public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/wavedata.cpp.o: public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/flags.make
public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/wavedata.cpp.o: /Users/jaeseoko/Research/public/src/yssimplesound/test/wavedata.cpp
public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/wavedata.cpp.o: public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build_current/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/wavedata.cpp.o"
	cd /Users/jaeseoko/Research/build_current/public/yssimplesound/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/wavedata.cpp.o -MF CMakeFiles/yssimplesound_test.dir/wavedata.cpp.o.d -o CMakeFiles/yssimplesound_test.dir/wavedata.cpp.o -c /Users/jaeseoko/Research/public/src/yssimplesound/test/wavedata.cpp

public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/wavedata.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yssimplesound_test.dir/wavedata.cpp.i"
	cd /Users/jaeseoko/Research/build_current/public/yssimplesound/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/public/src/yssimplesound/test/wavedata.cpp > CMakeFiles/yssimplesound_test.dir/wavedata.cpp.i

public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/wavedata.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yssimplesound_test.dir/wavedata.cpp.s"
	cd /Users/jaeseoko/Research/build_current/public/yssimplesound/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/public/src/yssimplesound/test/wavedata.cpp -o CMakeFiles/yssimplesound_test.dir/wavedata.cpp.s

public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/prop9.cpp.o: public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/flags.make
public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/prop9.cpp.o: /Users/jaeseoko/Research/public/src/yssimplesound/test/prop9.cpp
public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/prop9.cpp.o: public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build_current/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/prop9.cpp.o"
	cd /Users/jaeseoko/Research/build_current/public/yssimplesound/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/prop9.cpp.o -MF CMakeFiles/yssimplesound_test.dir/prop9.cpp.o.d -o CMakeFiles/yssimplesound_test.dir/prop9.cpp.o -c /Users/jaeseoko/Research/public/src/yssimplesound/test/prop9.cpp

public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/prop9.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yssimplesound_test.dir/prop9.cpp.i"
	cd /Users/jaeseoko/Research/build_current/public/yssimplesound/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/public/src/yssimplesound/test/prop9.cpp > CMakeFiles/yssimplesound_test.dir/prop9.cpp.i

public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/prop9.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yssimplesound_test.dir/prop9.cpp.s"
	cd /Users/jaeseoko/Research/build_current/public/yssimplesound/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/public/src/yssimplesound/test/prop9.cpp -o CMakeFiles/yssimplesound_test.dir/prop9.cpp.s

public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/gun.cpp.o: public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/flags.make
public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/gun.cpp.o: /Users/jaeseoko/Research/public/src/yssimplesound/test/gun.cpp
public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/gun.cpp.o: public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build_current/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/gun.cpp.o"
	cd /Users/jaeseoko/Research/build_current/public/yssimplesound/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/gun.cpp.o -MF CMakeFiles/yssimplesound_test.dir/gun.cpp.o.d -o CMakeFiles/yssimplesound_test.dir/gun.cpp.o -c /Users/jaeseoko/Research/public/src/yssimplesound/test/gun.cpp

public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/gun.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yssimplesound_test.dir/gun.cpp.i"
	cd /Users/jaeseoko/Research/build_current/public/yssimplesound/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/public/src/yssimplesound/test/gun.cpp > CMakeFiles/yssimplesound_test.dir/gun.cpp.i

public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/gun.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yssimplesound_test.dir/gun.cpp.s"
	cd /Users/jaeseoko/Research/build_current/public/yssimplesound/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/public/src/yssimplesound/test/gun.cpp -o CMakeFiles/yssimplesound_test.dir/gun.cpp.s

# Object files for target yssimplesound_test
yssimplesound_test_OBJECTS = \
"CMakeFiles/yssimplesound_test.dir/test.cpp.o" \
"CMakeFiles/yssimplesound_test.dir/wavedata.cpp.o" \
"CMakeFiles/yssimplesound_test.dir/prop9.cpp.o" \
"CMakeFiles/yssimplesound_test.dir/gun.cpp.o"

# External object files for target yssimplesound_test
yssimplesound_test_EXTERNAL_OBJECTS =

public/yssimplesound/test/yssimplesound_test: public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/test.cpp.o
public/yssimplesound/test/yssimplesound_test: public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/wavedata.cpp.o
public/yssimplesound/test/yssimplesound_test: public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/prop9.cpp.o
public/yssimplesound/test/yssimplesound_test: public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/gun.cpp.o
public/yssimplesound/test/yssimplesound_test: public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/build.make
public/yssimplesound/test/yssimplesound_test: public/yssimplesound/src/libyssimplesound.a
public/yssimplesound/test/yssimplesound_test: public/fssimplewindow/src/libfssimplewindow.a
public/yssimplesound/test/yssimplesound_test: public/ysbitmapfont/src/libysbitmapfont.a
public/yssimplesound/test/yssimplesound_test: public/yssimplesound/src/macosx/libyssimplesound_macosx.a
public/yssimplesound/test/yssimplesound_test: public/ysgl/src/libysgl.a
public/yssimplesound/test/yssimplesound_test: public/yssimplesound/src/libyssimplesound.a
public/yssimplesound/test/yssimplesound_test: public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jaeseoko/Research/build_current/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable yssimplesound_test"
	cd /Users/jaeseoko/Research/build_current/public/yssimplesound/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/yssimplesound_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/build: public/yssimplesound/test/yssimplesound_test
.PHONY : public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/build

public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/clean:
	cd /Users/jaeseoko/Research/build_current/public/yssimplesound/test && $(CMAKE_COMMAND) -P CMakeFiles/yssimplesound_test.dir/cmake_clean.cmake
.PHONY : public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/clean

public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/depend:
	cd /Users/jaeseoko/Research/build_current && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jaeseoko/Research/src/metaball /Users/jaeseoko/Research/public/src/yssimplesound/test /Users/jaeseoko/Research/build_current /Users/jaeseoko/Research/build_current/public/yssimplesound/test /Users/jaeseoko/Research/build_current/public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : public/yssimplesound/test/CMakeFiles/yssimplesound_test.dir/depend


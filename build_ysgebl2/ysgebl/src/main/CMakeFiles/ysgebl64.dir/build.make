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
include ysgebl/src/main/CMakeFiles/ysgebl64.dir/depend.make

# Include the progress variables for this target.
include ysgebl/src/main/CMakeFiles/ysgebl64.dir/progress.make

# Include the compile flags for this target's objects.
include ysgebl/src/main/CMakeFiles/ysgebl64.dir/flags.make

ysgebl/src/main/ysgebl64.app/Contents/Resources/APPL.icns: /Users/jaeseoko/Research/public/src/ysgebl/src/main/macosx/APPL.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content ysgebl/src/main/ysgebl64.app/Contents/Resources/APPL.icns"
	$(CMAKE_COMMAND) -E copy /Users/jaeseoko/Research/public/src/ysgebl/src/main/macosx/APPL.icns ysgebl/src/main/ysgebl64.app/Contents/Resources/APPL.icns

ysgebl/src/main/CMakeFiles/ysgebl64.dir/ysgebl_gui_extension.cpp.o: ysgebl/src/main/CMakeFiles/ysgebl64.dir/flags.make
ysgebl/src/main/CMakeFiles/ysgebl64.dir/ysgebl_gui_extension.cpp.o: /Users/jaeseoko/Research/public/src/ysgebl/src/main/ysgebl_gui_extension.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaeseoko/Research/build_ysgebl2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ysgebl/src/main/CMakeFiles/ysgebl64.dir/ysgebl_gui_extension.cpp.o"
	cd /Users/jaeseoko/Research/build_ysgebl2/ysgebl/src/main && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ysgebl64.dir/ysgebl_gui_extension.cpp.o -c /Users/jaeseoko/Research/public/src/ysgebl/src/main/ysgebl_gui_extension.cpp

ysgebl/src/main/CMakeFiles/ysgebl64.dir/ysgebl_gui_extension.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ysgebl64.dir/ysgebl_gui_extension.cpp.i"
	cd /Users/jaeseoko/Research/build_ysgebl2/ysgebl/src/main && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaeseoko/Research/public/src/ysgebl/src/main/ysgebl_gui_extension.cpp > CMakeFiles/ysgebl64.dir/ysgebl_gui_extension.cpp.i

ysgebl/src/main/CMakeFiles/ysgebl64.dir/ysgebl_gui_extension.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ysgebl64.dir/ysgebl_gui_extension.cpp.s"
	cd /Users/jaeseoko/Research/build_ysgebl2/ysgebl/src/main && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaeseoko/Research/public/src/ysgebl/src/main/ysgebl_gui_extension.cpp -o CMakeFiles/ysgebl64.dir/ysgebl_gui_extension.cpp.s

# Object files for target ysgebl64
ysgebl64_OBJECTS = \
"CMakeFiles/ysgebl64.dir/ysgebl_gui_extension.cpp.o"

# External object files for target ysgebl64
ysgebl64_EXTERNAL_OBJECTS =

ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: ysgebl/src/main/CMakeFiles/ysgebl64.dir/ysgebl_gui_extension.cpp.o
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: ysgebl/src/main/CMakeFiles/ysgebl64.dir/build.make
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: fslazywindow/src/libfslazywindow.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: ysgebl/src/kernel/libgeblkernel.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: ysgebl/src/kernelutil/libgeblutil.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: ysgebl/src/gui/libgeblgui.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: fslazywindow/src/libfslazywindow.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: ysgebl/src/gui_foundation/libgeblgui_foundation.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: ysgebl/src/shellrender/libgeblgl.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: ysgebl/src/kernelutil/libgeblutil.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: ysgebl/src/kernel/libgeblkernel.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: ysglcpp/src/libysglcpp.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: ysclass11/src/libysclass11.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: ysglcpp/src/gl2/libysglcpp_gl2.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: fsguilib/filedialog/libfsguifiledialog.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: fsgui3d/src/libfsgui3d.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: fsguilib/src/libfsguilib.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: ysfontrenderer/src/libysfontrenderer.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: fsgui3d/src/gl2/libfsgui3d_gl2.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: fsguilib/src/gl2/libfsguilib_gl2.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: fssimplewindow/src/libfssimplewindow.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: yssystemfont/src/libyssystemfont.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: ysbitmap/src/libysbitmap.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: ysbitmapfont/src/libysbitmapfont.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: ysgl/src/libysgl.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: ysport/src/libysport.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: ysclass/src/libysclass.a
ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64: ysgebl/src/main/CMakeFiles/ysgebl64.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jaeseoko/Research/build_ysgebl2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ysgebl64.app/Contents/MacOS/ysgebl64"
	cd /Users/jaeseoko/Research/build_ysgebl2/ysgebl/src/main && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ysgebl64.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/jaeseoko/Research/build_ysgebl2/ysgebl/src/main && echo For: ysgebl64
	cd /Users/jaeseoko/Research/build_ysgebl2/ysgebl/src/main && echo Copy
	cd /Users/jaeseoko/Research/build_ysgebl2/ysgebl/src/main && echo From: /Users/jaeseoko/Research/public/src/ysgebl/src/main/../../runtime
	cd /Users/jaeseoko/Research/build_ysgebl2/ysgebl/src/main && echo To: /Users/jaeseoko/Research/build_ysgebl2/ysgebl/src/main/ysgebl64.app/Contents/MacOS/../Resources
	cd /Users/jaeseoko/Research/build_ysgebl2/ysgebl/src/main && /usr/local/Cellar/cmake/3.17.3/bin/cmake -E make_directory "/Users/jaeseoko/Research/build_ysgebl2/ysgebl/src/main/ysgebl64.app/Contents/MacOS/../Resources"
	cd /Users/jaeseoko/Research/build_ysgebl2/ysgebl/src/main && /usr/local/Cellar/cmake/3.17.3/bin/cmake -E copy_directory "/Users/jaeseoko/Research/public/src/ysgebl/src/main/../../runtime" "/Users/jaeseoko/Research/build_ysgebl2/ysgebl/src/main/ysgebl64.app/Contents/MacOS/../Resources"

# Rule to build all files generated by this target.
ysgebl/src/main/CMakeFiles/ysgebl64.dir/build: ysgebl/src/main/ysgebl64.app/Contents/MacOS/ysgebl64
ysgebl/src/main/CMakeFiles/ysgebl64.dir/build: ysgebl/src/main/ysgebl64.app/Contents/Resources/APPL.icns

.PHONY : ysgebl/src/main/CMakeFiles/ysgebl64.dir/build

ysgebl/src/main/CMakeFiles/ysgebl64.dir/clean:
	cd /Users/jaeseoko/Research/build_ysgebl2/ysgebl/src/main && $(CMAKE_COMMAND) -P CMakeFiles/ysgebl64.dir/cmake_clean.cmake
.PHONY : ysgebl/src/main/CMakeFiles/ysgebl64.dir/clean

ysgebl/src/main/CMakeFiles/ysgebl64.dir/depend:
	cd /Users/jaeseoko/Research/build_ysgebl2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jaeseoko/Research/public/src /Users/jaeseoko/Research/public/src/ysgebl/src/main /Users/jaeseoko/Research/build_ysgebl2 /Users/jaeseoko/Research/build_ysgebl2/ysgebl/src/main /Users/jaeseoko/Research/build_ysgebl2/ysgebl/src/main/CMakeFiles/ysgebl64.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ysgebl/src/main/CMakeFiles/ysgebl64.dir/depend


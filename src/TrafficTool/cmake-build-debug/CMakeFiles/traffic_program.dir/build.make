# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /cygdrive/c/Users/johnm/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/johnm/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/johnm/Desktop/TrafficTool/src/TrafficTool

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/johnm/Desktop/TrafficTool/src/TrafficTool/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/traffic_program.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/traffic_program.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/traffic_program.dir/flags.make

CMakeFiles/traffic_program.dir/DataParser.cpp.o: CMakeFiles/traffic_program.dir/flags.make
CMakeFiles/traffic_program.dir/DataParser.cpp.o: ../DataParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/johnm/Desktop/TrafficTool/src/TrafficTool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/traffic_program.dir/DataParser.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traffic_program.dir/DataParser.cpp.o -c /cygdrive/c/Users/johnm/Desktop/TrafficTool/src/TrafficTool/DataParser.cpp

CMakeFiles/traffic_program.dir/DataParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traffic_program.dir/DataParser.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/johnm/Desktop/TrafficTool/src/TrafficTool/DataParser.cpp > CMakeFiles/traffic_program.dir/DataParser.cpp.i

CMakeFiles/traffic_program.dir/DataParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traffic_program.dir/DataParser.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/johnm/Desktop/TrafficTool/src/TrafficTool/DataParser.cpp -o CMakeFiles/traffic_program.dir/DataParser.cpp.s

CMakeFiles/traffic_program.dir/TrafficDataObject.cpp.o: CMakeFiles/traffic_program.dir/flags.make
CMakeFiles/traffic_program.dir/TrafficDataObject.cpp.o: ../TrafficDataObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/johnm/Desktop/TrafficTool/src/TrafficTool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/traffic_program.dir/TrafficDataObject.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traffic_program.dir/TrafficDataObject.cpp.o -c /cygdrive/c/Users/johnm/Desktop/TrafficTool/src/TrafficTool/TrafficDataObject.cpp

CMakeFiles/traffic_program.dir/TrafficDataObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traffic_program.dir/TrafficDataObject.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/johnm/Desktop/TrafficTool/src/TrafficTool/TrafficDataObject.cpp > CMakeFiles/traffic_program.dir/TrafficDataObject.cpp.i

CMakeFiles/traffic_program.dir/TrafficDataObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traffic_program.dir/TrafficDataObject.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/johnm/Desktop/TrafficTool/src/TrafficTool/TrafficDataObject.cpp -o CMakeFiles/traffic_program.dir/TrafficDataObject.cpp.s

# Object files for target traffic_program
traffic_program_OBJECTS = \
"CMakeFiles/traffic_program.dir/DataParser.cpp.o" \
"CMakeFiles/traffic_program.dir/TrafficDataObject.cpp.o"

# External object files for target traffic_program
traffic_program_EXTERNAL_OBJECTS =

traffic_program.exe: CMakeFiles/traffic_program.dir/DataParser.cpp.o
traffic_program.exe: CMakeFiles/traffic_program.dir/TrafficDataObject.cpp.o
traffic_program.exe: CMakeFiles/traffic_program.dir/build.make
traffic_program.exe: CMakeFiles/traffic_program.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/johnm/Desktop/TrafficTool/src/TrafficTool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable traffic_program.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/traffic_program.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/traffic_program.dir/build: traffic_program.exe

.PHONY : CMakeFiles/traffic_program.dir/build

CMakeFiles/traffic_program.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/traffic_program.dir/cmake_clean.cmake
.PHONY : CMakeFiles/traffic_program.dir/clean

CMakeFiles/traffic_program.dir/depend:
	cd /cygdrive/c/Users/johnm/Desktop/TrafficTool/src/TrafficTool/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/johnm/Desktop/TrafficTool/src/TrafficTool /cygdrive/c/Users/johnm/Desktop/TrafficTool/src/TrafficTool /cygdrive/c/Users/johnm/Desktop/TrafficTool/src/TrafficTool/cmake-build-debug /cygdrive/c/Users/johnm/Desktop/TrafficTool/src/TrafficTool/cmake-build-debug /cygdrive/c/Users/johnm/Desktop/TrafficTool/src/TrafficTool/cmake-build-debug/CMakeFiles/traffic_program.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/traffic_program.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kostya/Desktop/g5/testZeroMQ

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kostya/Desktop/g5/testZeroMQ/build

# Include any dependencies generated for this target.
include _deps/zmq-build/CMakeFiles/local_lat.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/zmq-build/CMakeFiles/local_lat.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/zmq-build/CMakeFiles/local_lat.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/zmq-build/CMakeFiles/local_lat.dir/flags.make

_deps/zmq-build/CMakeFiles/local_lat.dir/perf/local_lat.cpp.o: _deps/zmq-build/CMakeFiles/local_lat.dir/flags.make
_deps/zmq-build/CMakeFiles/local_lat.dir/perf/local_lat.cpp.o: _deps/zmq-src/perf/local_lat.cpp
_deps/zmq-build/CMakeFiles/local_lat.dir/perf/local_lat.cpp.o: _deps/zmq-build/CMakeFiles/local_lat.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kostya/Desktop/g5/testZeroMQ/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/zmq-build/CMakeFiles/local_lat.dir/perf/local_lat.cpp.o"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/zmq-build/CMakeFiles/local_lat.dir/perf/local_lat.cpp.o -MF CMakeFiles/local_lat.dir/perf/local_lat.cpp.o.d -o CMakeFiles/local_lat.dir/perf/local_lat.cpp.o -c /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-src/perf/local_lat.cpp

_deps/zmq-build/CMakeFiles/local_lat.dir/perf/local_lat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/local_lat.dir/perf/local_lat.cpp.i"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-src/perf/local_lat.cpp > CMakeFiles/local_lat.dir/perf/local_lat.cpp.i

_deps/zmq-build/CMakeFiles/local_lat.dir/perf/local_lat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/local_lat.dir/perf/local_lat.cpp.s"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-src/perf/local_lat.cpp -o CMakeFiles/local_lat.dir/perf/local_lat.cpp.s

# Object files for target local_lat
local_lat_OBJECTS = \
"CMakeFiles/local_lat.dir/perf/local_lat.cpp.o"

# External object files for target local_lat
local_lat_EXTERNAL_OBJECTS =

_deps/zmq-build/bin/local_lat: _deps/zmq-build/CMakeFiles/local_lat.dir/perf/local_lat.cpp.o
_deps/zmq-build/bin/local_lat: _deps/zmq-build/CMakeFiles/local_lat.dir/build.make
_deps/zmq-build/bin/local_lat: _deps/zmq-build/lib/libzmq.so.5.2.4
_deps/zmq-build/bin/local_lat: /usr/local/lib/libsodium.so
_deps/zmq-build/bin/local_lat: _deps/zmq-build/CMakeFiles/local_lat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kostya/Desktop/g5/testZeroMQ/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/local_lat"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/local_lat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/zmq-build/CMakeFiles/local_lat.dir/build: _deps/zmq-build/bin/local_lat
.PHONY : _deps/zmq-build/CMakeFiles/local_lat.dir/build

_deps/zmq-build/CMakeFiles/local_lat.dir/clean:
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build && $(CMAKE_COMMAND) -P CMakeFiles/local_lat.dir/cmake_clean.cmake
.PHONY : _deps/zmq-build/CMakeFiles/local_lat.dir/clean

_deps/zmq-build/CMakeFiles/local_lat.dir/depend:
	cd /home/kostya/Desktop/g5/testZeroMQ/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kostya/Desktop/g5/testZeroMQ /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-src /home/kostya/Desktop/g5/testZeroMQ/build /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build/CMakeFiles/local_lat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/zmq-build/CMakeFiles/local_lat.dir/depend


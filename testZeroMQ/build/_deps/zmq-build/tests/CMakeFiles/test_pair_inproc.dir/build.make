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
include _deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/flags.make

_deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/test_pair_inproc.cpp.o: _deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/flags.make
_deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/test_pair_inproc.cpp.o: _deps/zmq-src/tests/test_pair_inproc.cpp
_deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/test_pair_inproc.cpp.o: _deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kostya/Desktop/g5/testZeroMQ/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/test_pair_inproc.cpp.o"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/test_pair_inproc.cpp.o -MF CMakeFiles/test_pair_inproc.dir/test_pair_inproc.cpp.o.d -o CMakeFiles/test_pair_inproc.dir/test_pair_inproc.cpp.o -c /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-src/tests/test_pair_inproc.cpp

_deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/test_pair_inproc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_pair_inproc.dir/test_pair_inproc.cpp.i"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-src/tests/test_pair_inproc.cpp > CMakeFiles/test_pair_inproc.dir/test_pair_inproc.cpp.i

_deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/test_pair_inproc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_pair_inproc.dir/test_pair_inproc.cpp.s"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-src/tests/test_pair_inproc.cpp -o CMakeFiles/test_pair_inproc.dir/test_pair_inproc.cpp.s

# Object files for target test_pair_inproc
test_pair_inproc_OBJECTS = \
"CMakeFiles/test_pair_inproc.dir/test_pair_inproc.cpp.o"

# External object files for target test_pair_inproc
test_pair_inproc_EXTERNAL_OBJECTS =

_deps/zmq-build/bin/test_pair_inproc: _deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/test_pair_inproc.cpp.o
_deps/zmq-build/bin/test_pair_inproc: _deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/build.make
_deps/zmq-build/bin/test_pair_inproc: _deps/zmq-build/lib/libtestutil.a
_deps/zmq-build/bin/test_pair_inproc: /usr/lib/x86_64-linux-gnu/librt.a
_deps/zmq-build/bin/test_pair_inproc: _deps/zmq-build/lib/libzmq.so.5.2.4
_deps/zmq-build/bin/test_pair_inproc: /usr/local/lib/libsodium.so
_deps/zmq-build/bin/test_pair_inproc: _deps/zmq-build/lib/libunity.a
_deps/zmq-build/bin/test_pair_inproc: _deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kostya/Desktop/g5/testZeroMQ/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/test_pair_inproc"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_pair_inproc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/build: _deps/zmq-build/bin/test_pair_inproc
.PHONY : _deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/build

_deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/clean:
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_pair_inproc.dir/cmake_clean.cmake
.PHONY : _deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/clean

_deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/depend:
	cd /home/kostya/Desktop/g5/testZeroMQ/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kostya/Desktop/g5/testZeroMQ /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-src/tests /home/kostya/Desktop/g5/testZeroMQ/build /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build/tests /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/zmq-build/tests/CMakeFiles/test_pair_inproc.dir/depend


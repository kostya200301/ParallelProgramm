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
include _deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/flags.make

_deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/test_term_endpoint.cpp.o: _deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/flags.make
_deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/test_term_endpoint.cpp.o: _deps/zeromq-src/tests/test_term_endpoint.cpp
_deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/test_term_endpoint.cpp.o: _deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kostya/Desktop/g5/testZeroMQ/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/test_term_endpoint.cpp.o"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zeromq-build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/test_term_endpoint.cpp.o -MF CMakeFiles/test_term_endpoint.dir/test_term_endpoint.cpp.o.d -o CMakeFiles/test_term_endpoint.dir/test_term_endpoint.cpp.o -c /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zeromq-src/tests/test_term_endpoint.cpp

_deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/test_term_endpoint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_term_endpoint.dir/test_term_endpoint.cpp.i"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zeromq-build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zeromq-src/tests/test_term_endpoint.cpp > CMakeFiles/test_term_endpoint.dir/test_term_endpoint.cpp.i

_deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/test_term_endpoint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_term_endpoint.dir/test_term_endpoint.cpp.s"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zeromq-build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zeromq-src/tests/test_term_endpoint.cpp -o CMakeFiles/test_term_endpoint.dir/test_term_endpoint.cpp.s

# Object files for target test_term_endpoint
test_term_endpoint_OBJECTS = \
"CMakeFiles/test_term_endpoint.dir/test_term_endpoint.cpp.o"

# External object files for target test_term_endpoint
test_term_endpoint_EXTERNAL_OBJECTS =

_deps/zeromq-build/bin/test_term_endpoint: _deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/test_term_endpoint.cpp.o
_deps/zeromq-build/bin/test_term_endpoint: _deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/build.make
_deps/zeromq-build/bin/test_term_endpoint: _deps/zeromq-build/lib/libtestutil.a
_deps/zeromq-build/bin/test_term_endpoint: /usr/lib/x86_64-linux-gnu/librt.a
_deps/zeromq-build/bin/test_term_endpoint: _deps/zeromq-build/lib/libzmq.so.5.2.4
_deps/zeromq-build/bin/test_term_endpoint: /usr/local/lib/libsodium.so
_deps/zeromq-build/bin/test_term_endpoint: _deps/zeromq-build/lib/libunity.a
_deps/zeromq-build/bin/test_term_endpoint: _deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kostya/Desktop/g5/testZeroMQ/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/test_term_endpoint"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zeromq-build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_term_endpoint.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/build: _deps/zeromq-build/bin/test_term_endpoint
.PHONY : _deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/build

_deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/clean:
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zeromq-build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_term_endpoint.dir/cmake_clean.cmake
.PHONY : _deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/clean

_deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/depend:
	cd /home/kostya/Desktop/g5/testZeroMQ/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kostya/Desktop/g5/testZeroMQ /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zeromq-src/tests /home/kostya/Desktop/g5/testZeroMQ/build /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zeromq-build/tests /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/zeromq-build/tests/CMakeFiles/test_term_endpoint.dir/depend


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
include _deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/flags.make

_deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/unittest_ip_resolver.cpp.o: _deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/flags.make
_deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/unittest_ip_resolver.cpp.o: _deps/zmq-src/unittests/unittest_ip_resolver.cpp
_deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/unittest_ip_resolver.cpp.o: _deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kostya/Desktop/g5/testZeroMQ/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/unittest_ip_resolver.cpp.o"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build/unittests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/unittest_ip_resolver.cpp.o -MF CMakeFiles/unittest_ip_resolver.dir/unittest_ip_resolver.cpp.o.d -o CMakeFiles/unittest_ip_resolver.dir/unittest_ip_resolver.cpp.o -c /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-src/unittests/unittest_ip_resolver.cpp

_deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/unittest_ip_resolver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unittest_ip_resolver.dir/unittest_ip_resolver.cpp.i"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build/unittests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-src/unittests/unittest_ip_resolver.cpp > CMakeFiles/unittest_ip_resolver.dir/unittest_ip_resolver.cpp.i

_deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/unittest_ip_resolver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unittest_ip_resolver.dir/unittest_ip_resolver.cpp.s"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build/unittests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-src/unittests/unittest_ip_resolver.cpp -o CMakeFiles/unittest_ip_resolver.dir/unittest_ip_resolver.cpp.s

# Object files for target unittest_ip_resolver
unittest_ip_resolver_OBJECTS = \
"CMakeFiles/unittest_ip_resolver.dir/unittest_ip_resolver.cpp.o"

# External object files for target unittest_ip_resolver
unittest_ip_resolver_EXTERNAL_OBJECTS =

_deps/zmq-build/bin/unittest_ip_resolver: _deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/unittest_ip_resolver.cpp.o
_deps/zmq-build/bin/unittest_ip_resolver: _deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/build.make
_deps/zmq-build/bin/unittest_ip_resolver: _deps/zmq-build/lib/libtestutil-static.a
_deps/zmq-build/bin/unittest_ip_resolver: /usr/lib/x86_64-linux-gnu/librt.a
_deps/zmq-build/bin/unittest_ip_resolver: _deps/zmq-build/lib/libzmq.a
_deps/zmq-build/bin/unittest_ip_resolver: /usr/local/lib/libsodium.so
_deps/zmq-build/bin/unittest_ip_resolver: _deps/zmq-build/lib/libunity.a
_deps/zmq-build/bin/unittest_ip_resolver: _deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kostya/Desktop/g5/testZeroMQ/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/unittest_ip_resolver"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build/unittests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unittest_ip_resolver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/build: _deps/zmq-build/bin/unittest_ip_resolver
.PHONY : _deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/build

_deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/clean:
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build/unittests && $(CMAKE_COMMAND) -P CMakeFiles/unittest_ip_resolver.dir/cmake_clean.cmake
.PHONY : _deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/clean

_deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/depend:
	cd /home/kostya/Desktop/g5/testZeroMQ/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kostya/Desktop/g5/testZeroMQ /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-src/unittests /home/kostya/Desktop/g5/testZeroMQ/build /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build/unittests /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/zmq-build/unittests/CMakeFiles/unittest_ip_resolver.dir/depend


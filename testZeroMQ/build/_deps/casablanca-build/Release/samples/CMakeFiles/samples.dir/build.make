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

# Utility rule file for samples.

# Include any custom commands dependencies for this target.
include _deps/casablanca-build/Release/samples/CMakeFiles/samples.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/casablanca-build/Release/samples/CMakeFiles/samples.dir/progress.make

_deps/casablanca-build/Release/samples/CMakeFiles/samples: _deps/casablanca-build/Release/Binaries/SearchFile
_deps/casablanca-build/Release/samples/CMakeFiles/samples: _deps/casablanca-build/Release/Binaries/BingRequest
_deps/casablanca-build/Release/samples/CMakeFiles/samples: _deps/casablanca-build/Release/Binaries/blackjackclient
_deps/casablanca-build/Release/samples/CMakeFiles/samples: _deps/casablanca-build/Release/Binaries/blackjackserver
_deps/casablanca-build/Release/samples/CMakeFiles/samples: _deps/casablanca-build/Release/Binaries/oauth1client
_deps/casablanca-build/Release/samples/CMakeFiles/samples: _deps/casablanca-build/Release/Binaries/oauth2client

samples: _deps/casablanca-build/Release/samples/CMakeFiles/samples
samples: _deps/casablanca-build/Release/samples/CMakeFiles/samples.dir/build.make
.PHONY : samples

# Rule to build all files generated by this target.
_deps/casablanca-build/Release/samples/CMakeFiles/samples.dir/build: samples
.PHONY : _deps/casablanca-build/Release/samples/CMakeFiles/samples.dir/build

_deps/casablanca-build/Release/samples/CMakeFiles/samples.dir/clean:
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-build/Release/samples && $(CMAKE_COMMAND) -P CMakeFiles/samples.dir/cmake_clean.cmake
.PHONY : _deps/casablanca-build/Release/samples/CMakeFiles/samples.dir/clean

_deps/casablanca-build/Release/samples/CMakeFiles/samples.dir/depend:
	cd /home/kostya/Desktop/g5/testZeroMQ/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kostya/Desktop/g5/testZeroMQ /home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/samples /home/kostya/Desktop/g5/testZeroMQ/build /home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-build/Release/samples /home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-build/Release/samples/CMakeFiles/samples.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/casablanca-build/Release/samples/CMakeFiles/samples.dir/depend

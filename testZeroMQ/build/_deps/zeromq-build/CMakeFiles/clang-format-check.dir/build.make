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

# Utility rule file for clang-format-check.

# Include any custom commands dependencies for this target.
include _deps/zeromq-build/CMakeFiles/clang-format-check.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/zeromq-build/CMakeFiles/clang-format-check.dir/progress.make

_deps/zeromq-build/CMakeFiles/clang-format-check:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kostya/Desktop/g5/testZeroMQ/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Checking correct formatting according to .clang-format file using clang-format"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zeromq-build && chmod +x clang-format-check.sh
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zeromq-build && ./clang-format-check.sh

clang-format-check: _deps/zeromq-build/CMakeFiles/clang-format-check
clang-format-check: _deps/zeromq-build/CMakeFiles/clang-format-check.dir/build.make
.PHONY : clang-format-check

# Rule to build all files generated by this target.
_deps/zeromq-build/CMakeFiles/clang-format-check.dir/build: clang-format-check
.PHONY : _deps/zeromq-build/CMakeFiles/clang-format-check.dir/build

_deps/zeromq-build/CMakeFiles/clang-format-check.dir/clean:
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zeromq-build && $(CMAKE_COMMAND) -P CMakeFiles/clang-format-check.dir/cmake_clean.cmake
.PHONY : _deps/zeromq-build/CMakeFiles/clang-format-check.dir/clean

_deps/zeromq-build/CMakeFiles/clang-format-check.dir/depend:
	cd /home/kostya/Desktop/g5/testZeroMQ/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kostya/Desktop/g5/testZeroMQ /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zeromq-src /home/kostya/Desktop/g5/testZeroMQ/build /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zeromq-build /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zeromq-build/CMakeFiles/clang-format-check.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/zeromq-build/CMakeFiles/clang-format-check.dir/depend

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
CMAKE_SOURCE_DIR = /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild

# Utility rule file for zmq-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/zmq-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/zmq-populate.dir/progress.make

CMakeFiles/zmq-populate: CMakeFiles/zmq-populate-complete

CMakeFiles/zmq-populate-complete: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-install
CMakeFiles/zmq-populate-complete: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-mkdir
CMakeFiles/zmq-populate-complete: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-download
CMakeFiles/zmq-populate-complete: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-update
CMakeFiles/zmq-populate-complete: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-patch
CMakeFiles/zmq-populate-complete: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-configure
CMakeFiles/zmq-populate-complete: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-build
CMakeFiles/zmq-populate-complete: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-install
CMakeFiles/zmq-populate-complete: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'zmq-populate'"
	/usr/bin/cmake -E make_directory /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/CMakeFiles
	/usr/bin/cmake -E touch /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/CMakeFiles/zmq-populate-complete
	/usr/bin/cmake -E touch /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-done

zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-update:
.PHONY : zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-update

zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-build: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'zmq-populate'"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build && /usr/bin/cmake -E echo_append
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build && /usr/bin/cmake -E touch /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-build

zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-configure: zmq-populate-prefix/tmp/zmq-populate-cfgcmd.txt
zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-configure: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'zmq-populate'"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build && /usr/bin/cmake -E echo_append
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build && /usr/bin/cmake -E touch /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-configure

zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-download: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-gitinfo.txt
zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-download: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'zmq-populate'"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps && /usr/bin/cmake -P /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/zmq-populate-prefix/tmp/zmq-populate-gitclone.cmake
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps && /usr/bin/cmake -E touch /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-download

zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-install: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'zmq-populate'"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build && /usr/bin/cmake -E echo_append
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build && /usr/bin/cmake -E touch /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-install

zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'zmq-populate'"
	/usr/bin/cmake -E make_directory /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-src
	/usr/bin/cmake -E make_directory /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build
	/usr/bin/cmake -E make_directory /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/zmq-populate-prefix
	/usr/bin/cmake -E make_directory /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/zmq-populate-prefix/tmp
	/usr/bin/cmake -E make_directory /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/zmq-populate-prefix/src/zmq-populate-stamp
	/usr/bin/cmake -E make_directory /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/zmq-populate-prefix/src
	/usr/bin/cmake -E make_directory /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/zmq-populate-prefix/src/zmq-populate-stamp
	/usr/bin/cmake -E touch /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-mkdir

zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-patch: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'zmq-populate'"
	/usr/bin/cmake -E echo_append
	/usr/bin/cmake -E touch /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-patch

zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-update:
.PHONY : zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-update

zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-test: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'zmq-populate'"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build && /usr/bin/cmake -E echo_append
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-build && /usr/bin/cmake -E touch /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-test

zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-update: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Performing update step for 'zmq-populate'"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-src && /usr/bin/cmake -P /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/zmq-populate-prefix/tmp/zmq-populate-gitupdate.cmake

zmq-populate: CMakeFiles/zmq-populate
zmq-populate: CMakeFiles/zmq-populate-complete
zmq-populate: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-build
zmq-populate: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-configure
zmq-populate: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-download
zmq-populate: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-install
zmq-populate: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-mkdir
zmq-populate: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-patch
zmq-populate: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-test
zmq-populate: zmq-populate-prefix/src/zmq-populate-stamp/zmq-populate-update
zmq-populate: CMakeFiles/zmq-populate.dir/build.make
.PHONY : zmq-populate

# Rule to build all files generated by this target.
CMakeFiles/zmq-populate.dir/build: zmq-populate
.PHONY : CMakeFiles/zmq-populate.dir/build

CMakeFiles/zmq-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zmq-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zmq-populate.dir/clean

CMakeFiles/zmq-populate.dir/depend:
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild /home/kostya/Desktop/g5/testZeroMQ/build/_deps/zmq-subbuild/CMakeFiles/zmq-populate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zmq-populate.dir/depend


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
include _deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/flags.make

_deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/Oauth1Client.cpp.o: _deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/flags.make
_deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/Oauth1Client.cpp.o: _deps/casablanca-src/Release/samples/Oauth1Client/Oauth1Client.cpp
_deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/Oauth1Client.cpp.o: _deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kostya/Desktop/g5/testZeroMQ/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/Oauth1Client.cpp.o"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-build/Release/samples/Oauth1Client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/Oauth1Client.cpp.o -MF CMakeFiles/oauth1client.dir/Oauth1Client.cpp.o.d -o CMakeFiles/oauth1client.dir/Oauth1Client.cpp.o -c /home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/samples/Oauth1Client/Oauth1Client.cpp

_deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/Oauth1Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/oauth1client.dir/Oauth1Client.cpp.i"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-build/Release/samples/Oauth1Client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/samples/Oauth1Client/Oauth1Client.cpp > CMakeFiles/oauth1client.dir/Oauth1Client.cpp.i

_deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/Oauth1Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/oauth1client.dir/Oauth1Client.cpp.s"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-build/Release/samples/Oauth1Client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/samples/Oauth1Client/Oauth1Client.cpp -o CMakeFiles/oauth1client.dir/Oauth1Client.cpp.s

# Object files for target oauth1client
oauth1client_OBJECTS = \
"CMakeFiles/oauth1client.dir/Oauth1Client.cpp.o"

# External object files for target oauth1client
oauth1client_EXTERNAL_OBJECTS =

_deps/casablanca-build/Release/Binaries/oauth1client: _deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/Oauth1Client.cpp.o
_deps/casablanca-build/Release/Binaries/oauth1client: _deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/build.make
_deps/casablanca-build/Release/Binaries/oauth1client: _deps/casablanca-build/Release/Binaries/libcpprest.so.2.10
_deps/casablanca-build/Release/Binaries/oauth1client: /usr/lib/x86_64-linux-gnu/libboost_random.so.1.74.0
_deps/casablanca-build/Release/Binaries/oauth1client: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.74.0
_deps/casablanca-build/Release/Binaries/oauth1client: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.74.0
_deps/casablanca-build/Release/Binaries/oauth1client: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.74.0
_deps/casablanca-build/Release/Binaries/oauth1client: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.74.0
_deps/casablanca-build/Release/Binaries/oauth1client: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.74.0
_deps/casablanca-build/Release/Binaries/oauth1client: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.74.0
_deps/casablanca-build/Release/Binaries/oauth1client: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.74.0
_deps/casablanca-build/Release/Binaries/oauth1client: _deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kostya/Desktop/g5/testZeroMQ/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../Binaries/oauth1client"
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-build/Release/samples/Oauth1Client && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/oauth1client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/build: _deps/casablanca-build/Release/Binaries/oauth1client
.PHONY : _deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/build

_deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/clean:
	cd /home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-build/Release/samples/Oauth1Client && $(CMAKE_COMMAND) -P CMakeFiles/oauth1client.dir/cmake_clean.cmake
.PHONY : _deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/clean

_deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/depend:
	cd /home/kostya/Desktop/g5/testZeroMQ/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kostya/Desktop/g5/testZeroMQ /home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/samples/Oauth1Client /home/kostya/Desktop/g5/testZeroMQ/build /home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-build/Release/samples/Oauth1Client /home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/casablanca-build/Release/samples/Oauth1Client/CMakeFiles/oauth1client.dir/depend


# Install script for directory: /home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pplx" TYPE FILE FILES "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/pplx/threadpool.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cpprest" TYPE FILE FILES
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/astreambuf.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/asyncrt_utils.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/base_uri.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/containerstream.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/filestream.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/http_client.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/http_compression.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/http_headers.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/http_listener.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/http_msg.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/interopstream.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/json.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/oauth1.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/oauth2.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/producerconsumerstream.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/rawptrstream.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/streams.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/uri.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/uri_builder.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/version.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/ws_client.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/ws_msg.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pplx" TYPE FILE FILES
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/pplx/pplx.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/pplx/pplxcancellation_token.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/pplx/pplxconv.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/pplx/pplxinterface.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/pplx/pplxlinux.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/pplx/pplxtasks.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/pplx/pplxwin.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cpprest/details" TYPE FILE FILES
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/details/SafeInt3.hpp"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/details/basic_types.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/details/cpprest_compat.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/details/fileio.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/details/http_constants.dat"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/details/http_helpers.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/details/http_server.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/details/http_server_api.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/details/nosal.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/details/resource.h"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src/Release/src/../include/cpprest/details/web_utilities.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcpprest.so.2.10" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcpprest.so.2.10")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcpprest.so.2.10"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-build/Release/Binaries/libcpprest.so.2.10")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcpprest.so.2.10" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcpprest.so.2.10")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcpprest.so.2.10"
         OLD_RPATH "/usr/local/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcpprest.so.2.10")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcpprest.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcpprest.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcpprest.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-build/Release/Binaries/libcpprest.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcpprest.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcpprest.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcpprest.so"
         OLD_RPATH "/usr/local/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcpprest.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/cpprestsdk" TYPE FILE FILES
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-build/Release/src/cpprestsdk-config.cmake"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-build/Release/src/cpprestsdk-config-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/cpprestsdk/cpprestsdk-targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/cpprestsdk/cpprestsdk-targets.cmake"
         "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-build/Release/src/CMakeFiles/Export/lib/cmake/cpprestsdk/cpprestsdk-targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/cpprestsdk/cpprestsdk-targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/cpprestsdk/cpprestsdk-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/cpprestsdk" TYPE FILE FILES "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-build/Release/src/CMakeFiles/Export/lib/cmake/cpprestsdk/cpprestsdk-targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/cpprestsdk" TYPE FILE FILES "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-build/Release/src/CMakeFiles/Export/lib/cmake/cpprestsdk/cpprestsdk-targets-release.cmake")
  endif()
endif()


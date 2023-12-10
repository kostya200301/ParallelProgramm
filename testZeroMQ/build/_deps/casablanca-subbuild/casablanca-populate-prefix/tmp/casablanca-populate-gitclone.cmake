
if(NOT "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-subbuild/casablanca-populate-prefix/src/casablanca-populate-stamp/casablanca-populate-gitinfo.txt" IS_NEWER_THAN "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-subbuild/casablanca-populate-prefix/src/casablanca-populate-stamp/casablanca-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-subbuild/casablanca-populate-prefix/src/casablanca-populate-stamp/casablanca-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout --config "advice.detachedHead=false" "https://github.com/microsoft/cpprestsdk.git" "casablanca-src"
    WORKING_DIRECTORY "/home/kostya/Desktop/g5/testZeroMQ/build/_deps"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/microsoft/cpprestsdk.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout v2.10.19 --
  WORKING_DIRECTORY "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'v2.10.19'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-subbuild/casablanca-populate-prefix/src/casablanca-populate-stamp/casablanca-populate-gitinfo.txt"
    "/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-subbuild/casablanca-populate-prefix/src/casablanca-populate-stamp/casablanca-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/home/kostya/Desktop/g5/testZeroMQ/build/_deps/casablanca-subbuild/casablanca-populate-prefix/src/casablanca-populate-stamp/casablanca-populate-gitclone-lastrun.txt'")
endif()


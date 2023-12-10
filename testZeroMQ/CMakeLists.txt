cmake_minimum_required(VERSION 3.10)
project(YourProjectName)

include(FetchContent)

# Загружаем ZeroMQ
FetchContent_Declare(
    ZeroMQ
    GIT_REPOSITORY https://github.com/zeromq/libzmq.git
    GIT_TAG        v4.3.4
)
FetchContent_MakeAvailable(ZeroMQ)

find_package(cpprestsdk REQUIRED)


# Убеждаемся, что библиотека ZeroMQ найдена
if (NOT TARGET libzmq-static)
    message(FATAL_ERROR "Failed to find libzmq-static. Make sure ZeroMQ is downloaded and built.")
endif()

# Убеждаемся, что библиотека Casablanca найдена
if (NOT TARGET cpprestsdk::cpprest)
    message(FATAL_ERROR "Failed to find cpprestsdk::cpprest. Make sure Casablanca is downloaded and built.")
endif()

set(SOURCES
    dealer.cpp
    RestServer.cpp
)

add_executable(dealer ${SOURCES})

target_include_directories(dealer PRIVATE
    ${ZeroMQ_SOURCE_DIR}/include
    ${Casablanca_SOURCE_DIR}/Release/include
)

target_link_libraries(dealer PRIVATE
    libzmq-static
    cpprestsdk::cpprest
    -lssl
    -lcrypto
)

target_compile_options(dealer PRIVATE -std=c++11 -Wall -Wextra)

cmake_minimum_required(VERSION 3.3)
project(IDJ201601T1)

# this will help find STL when bulding
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${IDJ201601T1_SOURCE_DIR}/cmake")

# build to this dir
set(BIN_DIR ${IDJ201601T1_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# configure g++ compiler

# set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
# debug flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
# release flags
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")

# Look up SDL2 and add the include directory to our include path
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

include_directories(game)

add_subdirectory(game)
add_subdirectory(game_test)

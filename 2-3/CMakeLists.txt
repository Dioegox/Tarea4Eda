cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
# set the project name

project(misc
VERSION 1.0
LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(test_2-3 tests/test.cpp src/23Node.cpp src/23.cpp)
target_include_directories(test_2-3 PUBLIC ${PROJECT_SOURCE_DIR}/include)



# add the executable
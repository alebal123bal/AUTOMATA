cmake_minimum_required(VERSION 3.10)  # Specify the minimum version of CMake

project(Automata VERSION 1.0)  # Project name and version

set(CMAKE_CXX_STANDARD 17)  # Use C++17 standard
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)  # Include the directory for header files

file(GLOB_RECURSE SOURCES "src/*.cpp")  # Recursively find all .cpp files in src/

add_executable(automata ${SOURCES})  # Create an executable named automata
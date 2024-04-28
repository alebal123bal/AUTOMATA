cmake_minimum_required(VERSION 3.10)
project(Automata VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# It's good practice to specify the binary and source directories explicitly
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Automatically add all source files from the src directory
set(SOURCES 
    ${CMAKE_SOURCE_DIR}/src/automata.cpp

    ${CMAKE_SOURCE_DIR}/src/basic_types/operation.cpp 
    ${CMAKE_SOURCE_DIR}/src/basic_types/parenthesis.cpp
    ${CMAKE_SOURCE_DIR}/src/basic_types/token.cpp

    ${CMAKE_SOURCE_DIR}/src/binary_tree/tree_splitter.cpp

)

# Add executable
add_executable(automata ${SOURCES})

# Optionally set verbose makefile to help debugging of build issues
set(CMAKE_VERBOSE_MAKEFILE OFF)
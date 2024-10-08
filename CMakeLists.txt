cmake_minimum_required(VERSION 3.15)
project(Automata VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Find Python 3.11
find_package(Python3 3.11 REQUIRED COMPONENTS Interpreter Development)

# Fetch pybind11
include(FetchContent)
FetchContent_Declare(
  pybind11
  GIT_REPOSITORY https://github.com/pybind/pybind11.git
  GIT_TAG        v2.11.1
)
FetchContent_MakeAvailable(pybind11)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    ${CMAKE_SOURCE_DIR}/src/poly_engine/poly_engine.cpp
    ${CMAKE_SOURCE_DIR}/src/poly_engine/Monomial.cpp
    ${CMAKE_SOURCE_DIR}/src/poly_engine/MultivariablePolynomial.cpp
    ${CMAKE_SOURCE_DIR}/src/poly_engine/MultivariablePolynomialFraction.cpp
    ${CMAKE_SOURCE_DIR}/tests/Monomial_tests.cpp
    ${CMAKE_SOURCE_DIR}/tests/MultivariablePolynomial_tests.cpp
)

# Add the main executable
add_executable(automata ${SOURCES})

# Create Python bindings
pybind11_add_module(automata_bindings ${CMAKE_SOURCE_DIR}/bindings/bindings.cpp ${SOURCES})

# Link against Python libraries if needed
target_link_libraries(automata PRIVATE Python3::Python)
target_link_libraries(automata_bindings PRIVATE Python3::Python pybind11::module)

set_target_properties(automata_bindings PROPERTIES OUTPUT_NAME "automata_bindings")

# Ensure the module is placed in the correct output directory
set_target_properties(automata_bindings PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

set(CMAKE_VERBOSE_MAKEFILE ON)

# Print some debug information
message(STATUS "Python_EXECUTABLE: ${Python3_EXECUTABLE}")
message(STATUS "Python_INCLUDE_DIRS: ${Python3_INCLUDE_DIRS}")
message(STATUS "Python_LIBRARIES: ${Python3_LIBRARIES}")

# Check if Python executable and libraries are found
if(NOT Python3_EXECUTABLE)
    message(FATAL_ERROR "Python executable not found")
endif()
if(NOT Python3_INCLUDE_DIRS)
    message(FATAL_ERROR "Python include directories not found")
endif()
if(NOT Python3_LIBRARIES)
    message(FATAL_ERROR "Python libraries not found")
endif()
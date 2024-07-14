cmake_minimum_required(VERSION 3.15)
project(Automata VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Set these variables to match your Python installation
set(PYTHON_ROOT_DIR "C:/Users/Alessandro/miniconda3/envs/computer_vision")
set(Python_EXECUTABLE "${PYTHON_ROOT_DIR}/python.exe")
set(Python_INCLUDE_DIR "${PYTHON_ROOT_DIR}/include")
set(Python_LIBRARY "${PYTHON_ROOT_DIR}/libs/python311.lib")

# Find Python before fetching pybind11
find_package(Python 3.11 REQUIRED COMPONENTS Interpreter Development)

include(FetchContent)
FetchContent_Declare(
  pybind11
  GIT_REPOSITORY https://github.com/pybind/pybind11.git
  GIT_TAG        v2.11.1  # Specify a version tag for stability
)
FetchContent_MakeAvailable(pybind11)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${Python_INCLUDE_DIRS})

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

# If you want to create Python bindings, uncomment these lines:
# pybind11_add_module(automata_bindings ${CMAKE_SOURCE_DIR}/bindings/bindings.cpp)
# target_link_libraries(automata_bindings PRIVATE ${Python_LIBRARIES})

# Link against Python libraries if needed
target_link_libraries(automata PRIVATE ${Python_LIBRARIES})

set(CMAKE_VERBOSE_MAKEFILE ON)

# Print some debug information
message(STATUS "Python_EXECUTABLE: ${Python_EXECUTABLE}")
message(STATUS "Python_INCLUDE_DIRS: ${Python_INCLUDE_DIRS}")
message(STATUS "Python_LIBRARIES: ${Python_LIBRARIES}")
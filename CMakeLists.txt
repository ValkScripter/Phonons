# CMake minimum version
cmake_minimum_required(VERSION 3.20)

# Project name and version
project(Phonons VERSION 0.1.0 LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add executables
add_executable(Phonons main.cpp)

# Add tests
include(CTest)
enable_testing()

# Add packaging
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# CMake minimum version
cmake_minimum_required(VERSION 3.20)

# Project name and version
project(Phonons VERSION 0.1.0 LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add include directories
include_directories(include)

# Add executables
add_executable(Phonons main.cpp)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add packaging
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# Add tests
include(CTest)
enable_testing()

add_executable(hello_test hello_test.cpp)
target_link_libraries(hello_test GTest::gtest GTest::gtest_main)
add_test(NAME HelloTest COMMAND hello_test)

include(GoogleTest)
gtest_discover_tests(hello_test)

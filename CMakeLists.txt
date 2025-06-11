cmake_minimum_required(VERSION 3.14)
project(DataStructures)

set(CMAKE_CXX_STANDARD 17)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

# Use INTERFACE library for header-only templates
add_library(DataStructures INTERFACE)
target_include_directories(DataStructures INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Add test executable
enable_testing()
add_executable(tests
  tests/vectorTest.cpp
)

target_link_libraries(tests
  DataStructures
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)

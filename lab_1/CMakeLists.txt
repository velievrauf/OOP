cmake_minimum_required(VERSION 3.10)

project(VowelCounter)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

add_executable(VowelCounter main_program.cpp labsf.cpp)

add_subdirectory(googletest)
include_directories(googletest/googletest/include)

add_executable(runTests test_labsf.cpp labsf.cpp)

target_link_libraries(runTests gtest gtest_main)

enable_testing()
add_test(NAME VowelCounterTests COMMAND runTests)

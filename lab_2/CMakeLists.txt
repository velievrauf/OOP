cmake_minimum_required(VERSION 3.10)

project(FourExample)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

add_executable(FourExample main_program.cpp four.cpp)

add_subdirectory(googletest)
include_directories(googletest/googletest/include)

add_executable(runTests test_four.cpp four.cpp)
target_link_libraries(runTests gtest gtest_main)

enable_testing()
add_test(NAME FourTests COMMAND runTests)

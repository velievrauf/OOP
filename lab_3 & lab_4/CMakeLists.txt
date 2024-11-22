cmake_minimum_required(VERSION 3.10)

project(FigureTests)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

add_executable(Figures main_program.cpp trapezoid.cpp rhombus.cpp pentagon.cpp)

add_executable(test_figures test_figures.cpp trapezoid.cpp rhombus.cpp pentagon.cpp)
target_link_libraries(test_figures gtest gtest_main)

add_subdirectory(googletest)
include_directories(googletest/googletest/include)

target_link_libraries(test_figures gtest gtest_main)

enable_testing()
add_test(NAME TestFigures COMMAND test_figures)

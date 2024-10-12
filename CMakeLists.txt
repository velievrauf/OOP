cmake_minimum_required(VERSION 3.10)

# назввние проекта
project(VowelCounter)

# установка стандарта C++
set(CMAKE_CXX_STANDARD 14)

# добавление исполняемого файла
add_executable(VowelCounter labsf.cpp)

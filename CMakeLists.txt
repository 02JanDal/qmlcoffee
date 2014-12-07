cmake_minimum_required(VERSION 2.8.7)

project(qmlcoffee)
enable_testing()

find_package(Qt5 REQUIRED Core)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(qmlcoffee main.h main.cpp)
qt5_use_modules(qmlcoffee Core)

add_subdirectory(tests)

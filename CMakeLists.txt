cmake_minimum_required(VERSION 3.0)

project(qmlcoffee)

find_package(Qt5 REQUIRED Core)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(qmlcoffee main.h main.cpp)
qt5_use_modules(qmlcoffee Core)

add_subdirectory(tests)

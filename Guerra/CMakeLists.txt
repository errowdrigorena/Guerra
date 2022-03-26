cmake_minimum_required (VERSION 2.6)

#Version
SET(CMAKE_CXX_STANDARD 17)

project(guerra)
include_directories(include)

file(GLOB SOURCES "src/*.cc" "src/*/*.cc" "src/*/*/*.cc" "src/*/*/*/*.cc")
add_executable(guerra ${SOURCES})
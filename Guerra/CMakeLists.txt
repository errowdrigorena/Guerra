cmake_minimum_required (VERSION 3.1)

#Version
SET(CMAKE_CXX_STANDARD 17)

project(guerra)
include_directories(include)

add_executable(Src "")
add_subdirectory(src)
#file(GLOB SOURCES "src/*.cc" "src/*/*.cc" "src/*/*/*.cc" "src/*/*/*/*.cc")
#add_executable(guerra ${Src})
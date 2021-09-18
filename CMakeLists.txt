cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Cyanite)
set(CMAKE_SUPPRESS_REGENERATION true)


set(SRC_OSX src/core/osx/Main.mm)

if(APPLE)
add_executable(Cyanite ${SRC_OSX})
endif()

cmake_minimum_required(VERSION 3.14)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++20 /await")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
    add_library(Logging Logger.hxx win32/Logger.cxx Log.hxx)
    target_include_directories(Logging PUBLIC ${CMAKE_SOURCE_DIR}/src)
endif()


cmake_minimum_required(VERSION 3.14)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++20 /await")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Events Event.hxx InputEvent.hxx MouseEvent.hxx EventQueue.hxx EventQueue.cxx)
target_include_directories(Events PUBLIC ${CMAKE_SOURCE_DIR}/src/engine/Logging})

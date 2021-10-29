cmake_minimum_required(VERSION 3.14)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++20 /await")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(Worlds World.hxx World.cxx Vector2D.hxx Vector3D.hxx Vector3D.cxx Quaternion.hxx Quaternion.cxx Matrix4x4.hxx Matrix4x4.cxx Transform.hxx)

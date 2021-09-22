cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(Worlds World.hxx World.cxx Vector2D.hxx Vector3D.hxx Vector3D.cxx Quaternion.hxx Quaternion.cxx Matrix4x4.hxx Matrix4x4.cxx Transform.hxx)

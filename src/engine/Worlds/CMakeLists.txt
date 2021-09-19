cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(Worlds World.hxx World.cxx Vector2D.hxx Vector3D.hxx Quaternion.hxx Transform.hxx)

find_package(ArrayFire)
target_link_libraries(Worlds ArrayFire::af)

target_include_directories(Worlds PUBLIC /opt/arrayfire/include)

cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Engine CyaniteEngine.hxx CyaniteEngine.cxx EntityRegistry.hxx EntityRegistry.cxx EntitySet.hxx EntitySet.cxx EntityExclusive.hxx EntityExclusive.cxx  Entity.hxx Entity.cxx Component.hxx Component.cxx Transform.hxx Transform.cxx MeshRenderer.hxx MeshRenderer.cxx Time.hxx Time.cxx)

add_subdirectory(Rendering)
add_subdirectory(Worlds)
target_include_directories(Engine PUBLIC src/core)
target_include_directories(Engine PUBLIC ${CMAKE_SOURCE_DIR}/external/GSL/include)
target_include_directories(Engine PUBLIC ${CMAKE_SOURCE_DIR}/external/stduuid/include)
target_include_directories(Engine PUBLIC ${CMAKE_SOURCE_DIR}/external/inja/include)
target_include_directories(Engine PUBLIC ${CMAKE_SOURCE_DIR}/external/inja/third_party/include)


target_link_libraries(Engine PUBLIC Rendering)
target_link_libraries(Engine PUBLIC Worlds)

cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Engine CyaniteEngine.hxx CyaniteEngine.cxx Entity.hxx Entity.cxx Time.hxx Time.cxx)

add_subdirectory(Rendering)
add_subdirectory(Worlds)
target_include_directories(Engine PUBLIC src/core/engine)
target_include_directories(Engine PUBLIC ${CMAKE_SOURCE_DIR}/external/external/stduuid/include)
target_include_directories(Engine PUBLIC src/core)
target_link_libraries(Engine PUBLIC Rendering)
target_link_libraries(Engine PUBLIC Worlds)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++20 /await")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(Engine CyaniteCore)

add_library(${Engine} SHARED CyaniteEngine.hxx CyaniteEngine.cxx EntityRegistry.hxx EntityRegistry.cxx EntitySet.hxx EntitySet.cxx EntityExclusive.hxx EntityExclusive.cxx  Entity.hxx Entity.cxx Component.hxx Component.cxx Transform.hxx Transform.cxx MeshRenderer.hxx MeshRenderer.cxx Time.hxx Time.cxx Input.hxx)
 
add_subdirectory(Rendering)
add_subdirectory(Worlds)
add_subdirectory(Events)
add_subdirectory(System)

target_include_directories(${Engine} PUBLIC ${CMAKE_SOURCE_DIR}/src/engine/Events)
target_include_directories(${Engine} PUBLIC ${CMAKE_SOURCE_DIR}/external/GSL/include)
target_include_directories(${Engine} PUBLIC ${CMAKE_SOURCE_DIR}/external/stduuid/include)
target_include_directories(${Engine} PUBLIC ${CMAKE_SOURCE_DIR}/external/eventpp/include)

find_package(SDL2 REQUIRED)

target_link_libraries(${Engine} PUBLIC SDL2::SDL2)
target_link_libraries(${Engine} PUBLIC Rendering)
target_link_libraries(${Engine} PUBLIC Worlds)
target_link_libraries(${Engine} PUBLIC Events)
target_link_libraries(${Engine} PUBLIC System)


target_compile_definitions(${Engine} PUBLIC -Dawait)

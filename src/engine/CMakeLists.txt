if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++20 /await")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Engine CyaniteEngine.hxx CyaniteEngine.cxx EntityRegistry.hxx EntityRegistry.cxx EntitySet.hxx EntitySet.cxx EntityExclusive.hxx EntityExclusive.cxx  Entity.hxx Entity.cxx Component.hxx Component.cxx Transform.hxx Transform.cxx MeshRenderer.hxx MeshRenderer.cxx Time.hxx Time.cxx Input.hxx)

add_subdirectory(Rendering)
add_subdirectory(Worlds)
add_subdirectory(Logging)
add_subdirectory(Events)


target_include_directories(Engine PUBLIC src/)
target_include_directories(Engine PUBLIC ${CMAKE_SOURCE_DIR}/src/engine/Events)
target_include_directories(Engine PUBLIC ${CMAKE_SOURCE_DIR}/external/GSL/include)
target_include_directories(Engine PUBLIC ${CMAKE_SOURCE_DIR}/external/stduuid/include)
target_include_directories(Engine PUBLIC ${CMAKE_SOURCE_DIR}/external/eventpp/include)



target_link_libraries(Engine PUBLIC Rendering)
target_link_libraries(Engine PUBLIC Worlds)
target_link_libraries(Engine PUBLIC Logging)
target_link_libraries(Engine PUBLIC Events)

target_compile_definitions(Engine PUBLIC -Dawait)

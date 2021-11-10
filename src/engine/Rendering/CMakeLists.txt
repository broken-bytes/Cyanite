if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++20 /await")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Rendering STATIC Renderer.hxx Renderer.cxx RenderBackend.hxx Scene.hxx  CommandQueue.hxx Camera.hxx Camera.cxx Light.hxx GPU.hxx Color.hxx)
find_package(Vulkan REQUIRED FATAL_ERROR)
target_include_directories(Rendering PUBLIC ${CMAKE_SOURCE_DIR}/external/dx12-headers/include)
target_sources(
    Rendering PUBLIC
    RenderBackendVulkan.hxx
    RenderBackendVulkan.cxx
    vulkan/GPU.cxx
    vulkan/DeviceInfo.hxx
    vulkan/Swapchain.hxx
    vulkan/CommandQueue.cxx
    )
target_compile_definitions(Rendering PUBLIC -Dawait)
target_link_libraries(Rendering PUBLIC Vulkan::Vulkan)

target_include_directories(Rendering
    PUBLIC
    ${CMAKE_SOURCE_DIR}/src/engine/Worlds
    ${CMAKE_SOURCE_DIR}/external/vulkanhpp
    ${CMAKE_SOURCE_DIR}/external/vulkanhpp/Vulkan-Headers/include
    ${CMAKE_SOURCE_DIR}/external/sdl/include
)


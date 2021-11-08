if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++20 /await")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Rendering Renderer.hxx Renderer.cxx RenderBackend.hxx Scene.hxx  CommandQueue.hxx Camera.hxx Camera.cxx Light.hxx GPU.hxx Color.hxx)

if(APPLE)
target_sources(Rendering PUBLIC RenderBackendMetal.h RenderBackendMetal.mm)
elseif(WIN32)
target_include_directories(Rendering PUBLIC ${CMAKE_SOURCE_DIR}/external/dx12-headers/include)
target_sources(
    Rendering PUBLIC
    RenderBackendD3D12.hxx
    RenderBackendD3D12.cxx 
    d3d12/CommandQueue.cxx 
    d3d12/FrameResource.hxx 
    d3d12/FrameResource.cxx
    RenderBackendVulkan.hxx
    RenderBackendVulkan.cxx
    vulkan/GPU.cxx
    vulkan/CommandQueue.cxx
    )
target_link_libraries(Rendering PRIVATE
    d3d12.lib
    dxgi.lib
    dxguid.lib
)
else()
target_sources(Rendering PUBLIC RenderBackendVulkan.hxx RenderBackendVulkan.cxx)
endif()
target_compile_definitions(Rendering PUBLIC -Dawait)

target_include_directories(Rendering
    PUBLIC
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/engine
    )

cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Rendering Renderer.hxx Renderer.cxx RenderBackend.hxx Color.hxx)

if(APPLE)
target_sources(Rendering PUBLIC RenderBackendMetal.h RenderBackendMetal.mm)
elseif(WIN32)
target_sources(Rendering PUBLIC RenderBackendD3D12.hxx RenderBackendD3D12.cxx)
target_link_libraries(Rendering PRIVATE
    d3d12.lib
    dxgi.lib
    dxguid.lib
)
else()
target_sources(Rendering PUBLIC RenderBackendVulkan.hxx RenderBackendVulkan.cxx)
endif()

target_include_directories(Rendering
    PUBLIC
    ${CMAKE_SOURCE_DIR}/external/bgfx/include
    ${CMAKE_SOURCE_DIR}/src/core
    )

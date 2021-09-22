add_library(Rendering Renderer.hxx Renderer.cxx RenderBackend.hxx Scene.hxx Camera.hxx Camera.cxx Light.hxx GPU.hxx Color.hxx)

if(APPLE)
target_sources(Rendering PUBLIC RenderBackendMetal.h RenderBackendMetal.mm)
elseif(WIN32)
target_sources(Rendering PUBLIC d3d12/d3dx12.h RenderBackendD3D12.hxx RenderBackendD3D12.cxx d3d12/GPU.cxx d3d12/CommandQueue.hxx d3d12/CommandQueue.cxx d3d12/FrameResource.hxx d3d12/FrameResource.cxx)
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
    ${CMAKE_SOURCE_DIR}/external/bgfx/include
    ${CMAKE_SOURCE_DIR}/src/engine
    )

#include <stdio.h>

#include <bgfx/bgfx.h>
#include "Renderer.hxx"

namespace BrokenBytes::Cyanite::Engine::Rendering {
Renderer::Renderer() {
    
}

auto Renderer::Init(Window window, uint16_t width, uint16_t height) -> void {
    auto config = bgfx::Init { };
    auto platform = bgfx::PlatformData { };
    auto resolution = bgfx::Resolution { };
    config.platformData = platform;
#if __APPLE__
    config.type = bgfx::RendererType::Metal;
#elif _W10
    config.type = bgfx::RendererType::Direct3D12;
#elif _UNIX
    config.type = bgfx::RendererType::Vulkan;
#endif
    
    config.resolution = resolution;
    platform.nwh = window;
    resolution.width = width;
    resolution.height = height;
    resolution.format = bgfx::TextureFormat::RGBA32U;
    bgfx::init(config);
}

auto Renderer::Update() -> void {
    //bgfx::frame();
}

auto Renderer::Deinit() -> void {
    
}
}

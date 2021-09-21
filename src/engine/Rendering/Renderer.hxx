#pragma once

#include <memory>
#include <stdint.h>
#include "../../core/Globals.hxx"
#include "Color.hxx"
#include "RenderBackend.hxx"


namespace BrokenBytes::Cyanite::Engine::Rendering {

enum class RendererBackendType: uint8_t {
    OpenGL,
    Vulkan,
    Direct3D12,
    Metal
};

class Renderer {
public:
    Renderer(RendererBackendType backend);
    
    auto Init(Window window, uint16_t width, uint16_t height) -> void;
    auto Update() -> void;
    auto Deinit() -> void;    
private:
    std::unique_ptr<RenderBackend> _backend;
};
}

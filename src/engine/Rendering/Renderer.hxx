#pragma once

#include <stdint.h>
#include "../../core/Globals.hxx"
#include "Color.hxx"

namespace BrokenBytes::Cyanite::Engine::Rendering {

struct PixelResource {
    uint16_t x;
    uint16_t y;
    ColorRGB<uint8_t> color;
};

enum class RendererBackend: uint8_t {
    OpenGL,
    Vulkan,
    Direct3D12,
    Metal
};

class Renderer {
public:
    Renderer();
    
    auto Init(Window window, uint16_t width, uint16_t height) -> void;
    auto Update() -> void;
    auto Deinit() -> void;
};
}

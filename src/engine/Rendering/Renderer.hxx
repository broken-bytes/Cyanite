#pragma once

#include <stdint.h>
#include "../../core/Globals.hxx"

namespace BrokenBytes::Cyanite::Engine::Rendering {
class Renderer {
public:
    Renderer();
    
    auto Init(Window window, uint16_t width, uint16_t height) -> void;
    auto Update() -> void;
    auto Deinit() -> void;
};
}

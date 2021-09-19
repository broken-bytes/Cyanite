#pragma once

#include <memory>
#include <vector>
#include <Globals.hxx>
#include "Worlds/World.hxx"
#include "Entity.hxx"

namespace BrokenBytes::Cyanite::Engine {
class CyaniteEngine {
public:
    CyaniteEngine(Window window, uint16_t width, uint16_t height);
    auto Run() -> void;
private:
    void* _renderer;
    std::vector<Entity> _entities;
};
}

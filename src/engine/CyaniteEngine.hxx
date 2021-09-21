#pragma once

#include <memory>
#include <vector>
#include <Globals.hxx>
#include "Worlds/World.hxx"
#include "Entity.hxx"
#include "EntityRegistry.hxx"

namespace BrokenBytes::Cyanite::Engine {
class CyaniteEngine {
public:
    CyaniteEngine(Window window, uint16_t width, uint16_t height);
    auto Run() -> void;
private:
    EntityRegistry _entityRegistry;
};
}

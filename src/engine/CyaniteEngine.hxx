#pragma once

#include <memory>
#include <vector>
#include <SDL.h>

#include "Worlds/World.hxx"
#include "Entity.hxx"
#include "EntityRegistry.hxx"
#include "EventQueue.hxx"
#include "Rendering/Renderer.hxx"


namespace entry {
	struct Event;
}

namespace BrokenBytes::Cyanite::Engine {
class CyaniteEngine {
public:
    CyaniteEngine(SDL_Window* window, uint16_t width, uint16_t height);
    auto AddEvent(Events::Event* e) -> void;
    auto Run() -> void;
private:
    Events::EventQueue _eventQueue;
    EntityRegistry _entityRegistry;
};
}

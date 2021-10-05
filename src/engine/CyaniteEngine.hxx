#pragma once

#include <memory>
#include <vector>
#include <eventpp/eventqueue.h>
#include <Globals.hxx>
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
    CyaniteEngine(Window window, uint16_t width, uint16_t height);
    auto AddEvent(Events::Event* e) -> void;
    auto Run() -> void;
private:
    Events::EventQueue _eventQueue;
    std::unique_ptr<Rendering::Renderer> _renderer;
    EntityRegistry _entityRegistry;
};
}

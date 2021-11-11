#include <memory>
#include <thread>
#include <mutex>
#include <iostream>
#include <SDL.h>

#include "Rendering/Renderer.hxx"
#include "CyaniteEngine.hxx"
#include "InputEvent.hxx"
#include "MouseEvent.hxx"
#include "Transform.hxx"


using namespace BrokenBytes::Cyanite::Engine;

std::unique_ptr<CyaniteEngine> engine;

#ifdef __cplusplus
extern "C" {
#endif
auto CyaniteCoreInit(SDL_Window* window, uint16_t width, uint16_t height) -> void {
    engine = std::make_unique<CyaniteEngine>(window, width, height);
}
#ifdef __cplusplus
}
#endif


namespace BrokenBytes::Cyanite::Engine {
	uint64_t count = 0;
	std::mutex mutex;
	CyaniteEngine::CyaniteEngine(SDL_Window* window, uint16_t width, uint16_t height) {
        RendererInit(window, width, height, Vulkan);
	}

	auto CyaniteEngine::AddEvent(Events::Event* e) -> void {
		_eventQueue.Push(e);
	}
	
	auto CyaniteEngine::Run() -> void {
		while (!_eventQueue.Empty()) {
			auto event = _eventQueue.Pop();
			auto result = dynamic_cast<Events::InputEvent*>(event.get()) != nullptr;
			//if(result) Log({"IS Input", "The event is an input event"});
			result = dynamic_cast<Events::MouseEvent*>(event.get()) != nullptr;
			//if (result) Log({ "IS Input", "The event is a mouse event" });
		}
		RendererUpdate();
	}
}

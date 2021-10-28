#include <memory>
#include <thread>
#include <mutex>

#include <Globals.hxx>

#include "Rendering/Renderer.hxx"
#include "CyaniteEngine.hxx"

#include <iostream>


#include "InputEvent.hxx"
#include "MouseEvent.hxx"
#include "Transform.hxx"
#include "Logging/Logger.hxx"

namespace BrokenBytes::Cyanite::Engine {
	uint64_t count = 0;
	std::mutex mutex;
	CyaniteEngine::CyaniteEngine(Window window, uint16_t width, uint16_t height) {
		CreateLogger();
#if _WIN32
		this->_renderer = std::make_unique<Rendering::Renderer>(
			window,
			width,
			height,
			Rendering::RendererBackendType::Direct3D12);
		this->_renderer->Init();
#elif __APPLE__
		auto ren = new Rendering::Renderer(Rendering::RendererBackendType::Metal);
#else
#endif
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
		this->_renderer->Update();
	}
}

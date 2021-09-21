#include <memory>
#include <thread>
#include <mutex>

#include <Globals.hxx>
#include "Rendering/Renderer.hxx"
#include "CyaniteEngine.hxx"

#include <iostream>

#include "Transform.hxx"

namespace BrokenBytes::Cyanite::Engine {
    uint64_t count = 0;
    std::mutex mutex;
CyaniteEngine::CyaniteEngine(Window window, uint16_t width, uint16_t height) {
#if _WIN32
    auto ren = new Rendering::Renderer(Rendering::RendererBackendType::Direct3D12);
#elif __APPLE__
    auto ren = new Rendering::Renderer(Rendering::RendererBackendType::Metal);
#else
#endif

    ren->Init(window, width, height);
}

	
auto CyaniteEngine::Run() -> void {
    auto ent = this->_entityRegistry.Create();
    ent.Add(Transform{});
    auto trans = ent.Component<Transform>();
    while(true) {
	    
    }
}
}

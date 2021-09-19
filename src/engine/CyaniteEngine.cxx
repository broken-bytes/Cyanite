#include <memory>
#include <thread>

#include <Globals.hxx>
#include "Rendering/Renderer.hxx"
#include "CyaniteEngine.hxx"

namespace BrokenBytes::Cyanite::Engine {
CyaniteEngine::CyaniteEngine(Window window, uint16_t width, uint16_t height) {
    auto ren = new Rendering::Renderer();
    ren->Init(window, width, height);
    this->_renderer = ren;    
}

auto CyaniteEngine::Run() -> void {
    auto renderer = reinterpret_cast<Rendering::Renderer*>(this->_renderer);
    while(true) {
        renderer->Update();
    }
    return;
}
}

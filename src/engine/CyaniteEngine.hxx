#pragma once

#include <memory>
#include <Globals.hxx>


namespace BrokenBytes::Cyanite::Engine {
class CyaniteEngine {
public:
    CyaniteEngine(Window window, uint16_t width, uint16_t height);
    auto Run() -> void;
private:
    void* _renderer;
};
}

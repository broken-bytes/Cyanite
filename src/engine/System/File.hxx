#pragma once
#include <fstream>

namespace BrokenBytes::Cyanite::Engine::System {
    auto ReadFile(const std::string& path)  -> std::vector<char>;
}

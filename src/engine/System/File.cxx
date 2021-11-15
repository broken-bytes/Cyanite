#include <fstream>
#include <vector>

#include "File.hxx"

namespace BrokenBytes::Cyanite::Engine::System {
auto ReadFile(const std::string& path)  -> std::vector<char> {
    std::ifstream str(path, std::ios::binary | std::ios::ate);
    
    if(!str.is_open()) {
        throw std::runtime_error("Could not read file");
    }
    
    size_t fileLen = str.tellg();
    std::vector<char> buffer (fileLen);
    
    str.seekg(0);
    
    str.read(buffer.data(), fileLen);
    str.close();
    return buffer;
}
}

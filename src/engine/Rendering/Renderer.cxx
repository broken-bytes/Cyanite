#include <stdio.h>

#include "Renderer.hxx"

#ifdef _WIN32
#include "RenderBackendD3D12.hxx"
#endif

namespace BrokenBytes::Cyanite::Engine::Rendering {
Renderer::Renderer(
	Window window,
	uint16_t width,
	uint16_t height,
	RendererBackendType backend) {
#ifdef _WIN32
	auto renderer = new RenderBackendD3D12(window, width, height);
	this->_backend =
		std::unique_ptr<RenderBackend>(renderer);
#endif
}

auto Renderer::Init() -> void {
}

auto Renderer::Update() -> void {

}

auto Renderer::Deinit() -> void {
    
}
}

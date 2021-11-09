#include <stdio.h>
#include <memory>
#include <iostream>

#include "Renderer.hxx"
#include "RenderBackendD3D12.hxx"
#include "RenderBackendVulkan.hxx"
#include "RenderBackend.hxx"




using namespace BrokenBytes::Cyanite::Engine::Rendering;

std::unique_ptr<RenderBackend> _backend;

	auto RendererInit(
		SDL_Window* window,
		uint32_t width,
		uint32_t height,
		RendererBackendType backend) -> uint8_t {
		switch (backend)
		{
		case Vulkan: {
			_backend =
				std::make_unique<RenderBackendVulkan>(window, width, height);
			break;
		}
		case Direct3D12: {
			
		}
		
		default:
			break;
		}

		return _backend->Init();
	}

auto RendererUpdate() -> void {

}

auto RendererDeinit() -> void {
	std::cout << "Destroy Renderer" << std::endl;
	_backend->Deinit();
}

#include <winrt/base.h>
#include "RenderBackendD3D12.hxx"
#include <SDL.h>
using namespace winrt;

namespace BrokenBytes::Cyanite::Engine::Rendering {
	RenderBackendD3D12::RenderBackendD3D12(
		SDL_Window* window,
		uint32_t width,
		uint32_t height): RenderBackend(window, width, height) {}

	RenderBackendD3D12::~RenderBackendD3D12() {}

	auto RenderBackendD3D12::Init() -> uint8_t {
		return EXIT_FAILURE;
	}

	auto RenderBackendD3D12::Update() -> void {}

	auto RenderBackendD3D12::Render() -> void {}

	auto RenderBackendD3D12::Deinit() -> void {}

	auto RenderBackendD3D12::LoadPipeline() -> void {
		
	}
	
	auto RenderBackendD3D12::LoadAssets() -> void {}
	
	auto RenderBackendD3D12::LoadContexts() -> void {}
	
	auto RenderBackendD3D12::VRAM() -> uint64_t {
		return 0;
	}
}

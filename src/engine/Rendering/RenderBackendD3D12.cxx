#include <winrt/base.h>
#include "RenderBackendD3D12.hxx"

using namespace winrt;

namespace BrokenBytes::Cyanite::Engine::Rendering {
	RenderBackendD3D12::RenderBackendD3D12(
		Window window,
		uint16_t width,
		uint16_t height): RenderBackend(window, width, height) {}

	RenderBackendD3D12::~RenderBackendD3D12() {}

	auto RenderBackendD3D12::Init() -> void {}

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

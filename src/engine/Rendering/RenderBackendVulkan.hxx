#pragma once

#include "Camera.hxx"
#include "Light.hxx"
#include "RenderBackend.hxx"

namespace BrokenBytes::Cyanite::Engine::Rendering {
	class RenderBackendVulkan : public RenderBackend {
	public:
		RenderBackendVulkan(Window window, uint16_t width, uint16_t height);
		~RenderBackendVulkan();
		auto Init() -> void override;
		auto Update() -> void override;
		auto Render() -> void override;
		auto Deinit() -> void override;
		auto VRAM() -> uint64_t override;
	private:
		void LoadPipeline();
		void LoadAssets();
	};
}

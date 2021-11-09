#pragma once

#include <vulkan/vulkan.hpp>
#include <SDL.h>
#include <set>
#include "vulkan/DeviceInfo.hxx"
#include "Camera.hxx"
#include "Light.hxx"
#include "RenderBackend.hxx"
#include <memory>


namespace BrokenBytes::Cyanite::Engine::Rendering {
	class RenderBackendVulkan : public RenderBackend {
	public:
		RenderBackendVulkan(SDL_Window* window, uint16_t width, uint16_t height);
		~RenderBackendVulkan();
		auto Init() -> uint8_t override;
		auto Update() -> void override;
		auto Render() -> void override;
		auto Deinit() -> void override;
		auto VRAM() -> uint64_t override;
	private:
		VkDevice _vDevice;
		VkPhysicalDevice _pDevice;
		VkInstance _vInstance;
		VkSurfaceKHR _vSurface;
		VkQueue _graphicsQueue;
		VkQueue _presentationQueue;
		auto LoadPipeline() -> void;
		auto LoadAssets() -> void;

		[[nodiscard]] auto CheckVulkanDeviceExtensionsSupport(VkPhysicalDevice device) -> bool;

		[[nodiscard]] auto CheckVulkanExtensionsSupport(std::vector<const char*> extensions) -> bool;
		auto CreateVkInstance() -> void;
		auto CreateVkSurface() -> void;
		auto CreateVKSwapchain() -> void;
		[[nodiscard]] auto GetDeviceInfo(const VkPhysicalDevice device)->DeviceInfo&;
		auto BindPhysicalDevice(VkPhysicalDevice device) -> void;
		[[nodiscard]] auto QueryHighPerformanceGPU() ->VkPhysicalDevice;
	};
}

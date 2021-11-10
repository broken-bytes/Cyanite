#pragma once

#include <vulkan/vulkan.hpp>
#include <SDL.h>
#include <set>
#include <memory>

#include "vulkan/DeviceInfo.hxx"
#include "vulkan/Swapchain.hxx"
#include "Camera.hxx"
#include "Light.hxx"
#include "RenderBackend.hxx"


namespace BrokenBytes::Cyanite::Engine::Rendering {
	class RenderBackendVulkan : public RenderBackend {
	public:
		RenderBackendVulkan(SDL_Window* window, uint32_t width, uint32_t height);
		~RenderBackendVulkan();
		auto Init() -> uint8_t override;
		auto Update() -> void override;
		auto Render() -> void override;
		auto Deinit() -> void override;
		auto VRAM() -> uint64_t override;
	private:
		// Vulkan instances ---- 
		VkDevice _vDevice = nullptr;
		VkPhysicalDevice _pDevice = nullptr;
		VkInstance _vInstance = nullptr;
		VkSurfaceKHR _vSurface = nullptr;
		VkSwapchainKHR _vSwapchain = nullptr;
		VkQueue _graphicsQueue = nullptr;
		VkQueue _presentationQueue = nullptr;
		std::vector<SwapchainImage> _sImages;

		// Stored props
		VkFormat _scImageFormat = {};
		VkExtent2D _scExtent = {};
		DeviceInfo _deviceInfo;

#pragma region Load
		// --- MARK: Load Methods
		auto LoadPipeline() -> void;
		auto LoadAssets() -> void;

#pragma endregion
#pragma region Checkers
		// --- MARK: Checker Methods
		[[nodiscard]] auto CheckVulkanDeviceExtensionsSupport(VkPhysicalDevice device) -> bool;
		[[nodiscard]] auto CheckVulkanExtensionsSupport(std::vector<const char*> extensions) -> bool;
#pragma endregion
#pragma region Getters
		// --- MARK: Getter Methods
		[[nodiscard]] auto GetSwapchainCapabilities(VkPhysicalDevice device, VkSurfaceKHR surface)->SwapchainCapabilities;
		[[nodiscard]] auto GetPreferedSwapchainFormat(SwapchainCapabilities& caps)->VkSurfaceFormatKHR;
		[[nodiscard]] auto GetPreferedSwapchainPresentMode(SwapchainCapabilities& caps)->VkPresentModeKHR;
		[[nodiscard]] auto GetPreferedSwapchainResolution(VkSurfaceCapabilitiesKHR& caps)->VkExtent2D;
		[[nodiscard]] auto GetDeviceInfo(const VkPhysicalDevice device)->DeviceInfo&;
		[[nodiscard]] auto QueryHighPerformanceGPU()->VkPhysicalDevice;
#pragma endregion
#pragma region Create
		// --- MARK: Create Methods
		auto CreateVkInstance() -> void;
		auto CreateVkSurface() -> void;
		auto CreateVKSwapchain(SwapchainCapabilities& config) -> void;
		auto BindPhysicalDevice(VkPhysicalDevice device) -> void;
#pragma endregion
#pragma region Create Helpers
		// --- MARK: Create Helper Methods
		[[nodiscard]] auto CreateImageView(VkImage image, VkFormat format, VkImageAspectFlags flags)->VkImageView;
#pragma endregion 
	};
}

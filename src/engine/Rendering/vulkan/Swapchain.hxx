#pragma once
#include <vulkan/vulkan.hpp>

struct SwapchainCapabilities {
	VkSurfaceCapabilitiesKHR Capabilities;
	std::vector<VkSurfaceFormatKHR> Formats;
	std::vector<VkPresentModeKHR> Modes;
};

struct SwapchainImage {
	VkImage Image;
	VkImageView View;
};
#pragma once

#include <cstdint>
#include <vulkan/vulkan.hpp>

struct DeviceInfo {
	int32_t GraphicsQueue = -1;
	int32_t PresentationQueue = -1;
	VkDeviceSize VRAM = 0;
	VkPhysicalDevice Device;
	bool Discrete = false;

	auto IsValid() -> bool {
		return GraphicsQueue >= 0 && PresentationQueue >= 0;
	}
};
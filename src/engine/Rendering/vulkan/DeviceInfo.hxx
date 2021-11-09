#pragma once

#include <cstdint>

struct DeviceInfo {
	int32_t GraphicsQueue = -1;
	int32_t PresentationQueue = -1;

	auto IsValid() -> bool {
		return GraphicsQueue >= 0 && PresentationQueue >= 0;
	}
};
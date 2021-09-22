#pragma once
#include <array>

namespace BrokenBytes::Cyanite::Engine::World {
#pragma pack(push,1)
	struct Matrix4X4 {
		std::array<std::array<float, 4>, 4> data;

	};

#pragma pack(pop)
}

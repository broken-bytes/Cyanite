#pragma once

#include <Matrix4x4.hxx>
#include "Color.hxx"

namespace BrokenBytes::Cyanite::Engine::Rendering {
#pragma pack(push, 1)
	struct Light {
		World::Matrix4X4 position;
		World::Matrix4X4 rotation;
		ColorRGBA color;
		World::Matrix4X4 fallof;
		World::Matrix4X4 view;
		World::Matrix4X4 projection;
	};
#pragma pack(pop)
}

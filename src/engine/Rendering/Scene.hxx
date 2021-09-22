#pragma once

#include <vector>
#include <../engine/Worlds/Matrix4x4.hxx>
#include "Color.hxx"
#include "Light.hxx"

namespace BrokenBytes::Cyanite::Engine::Rendering {
#pragma pack(push, 1)
	struct Scene {
		World::Matrix4X4 model;
		World::Matrix4X4 view;
		ColorRGBA ambientColor;
		bool shadows;
		bool padding[3];
		std::vector<Light> lights;
	};
#pragma pack(pop)
}

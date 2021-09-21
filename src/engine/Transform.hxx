#pragma once

#include "Component.hxx"
#include "Worlds/Quaternion.hxx"
#include "Worlds/Vector3D.hxx"

namespace BrokenBytes::Cyanite::Engine {
#pragma pack(push, 1)
	struct Transform: Component {
		Transform(): Transform({0,0,0}, {0,0,0,0}) {
		}

		Transform(World::Vector3D<float> pos, World::Quaternion<float> rot):Component(typeid(Transform).name()) {
			position = pos;
			rotation = rot;
		}

		World::Vector3D<float> position;
		World::Quaternion<float> rotation;
	};
#pragma pack(pop)
}

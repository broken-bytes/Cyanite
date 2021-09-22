#pragma once
#include "../Worlds/Quaternion.hxx"
#include "../Worlds/Vector3D.hxx"

namespace BrokenBytes::Cyanite::Engine::Rendering {
	struct Camera {
		World::Vector3D position;
		World::Quaternion rotation;
		bool isOrthographic;
		float fov;
		float cullingStart;
		float cullingEnd;

		explicit Camera(
			World::Vector3D position = World::Vector3D{ 0,0,0 },
			World::Vector3D rotation = World::Vector3D{ 0, 0, 0 },
			float fov = 60,
			bool orthographic = false,
			float cullingStart = 0.1,
			float cullingEnd = 1000
		);
		auto SetPosition(World::Vector3D position) -> void;
		auto Translate(World::Vector3D translation) -> void;
		auto SetRotation(World::Vector3D rotation) -> void;
		auto SetRotation(World::Quaternion rotation) -> void;
		auto Rotate(World::Vector3D rotation) -> void;	
	};
}

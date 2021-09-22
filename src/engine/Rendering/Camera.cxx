#include "Camera.hxx"

namespace BrokenBytes::Cyanite::Engine::Rendering {
	Camera::Camera(
		World::Vector3D position,
		World::Vector3D rotation,
		float fov,
		bool orthographic,
		float cullingStart,
		float cullingEnd) : position(position),
							fov(fov),
							isOrthographic(orthographic),
							cullingStart(cullingStart),
							cullingEnd(cullingEnd) {
		
	}

	auto Camera::SetPosition(World::Vector3D position) -> void {
		World::Quaternion q(position);
		this->rotation = q;
	}
	
	auto Camera::Translate(World::Vector3D translation) -> void {
		this->position += translation;
	}
	
	auto Camera::SetRotation(World::Vector3D rotation) -> void {
		this->rotation = World::Quaternion(rotation);
	}
	
	auto Camera::SetRotation(World::Quaternion rotation) -> void {
		this->rotation = rotation;
	}
	
	auto Camera::Rotate(World::Vector3D rotation) -> void {
		auto euler = this->rotation.Euler();
		euler += rotation;
		this->rotation = World::Quaternion(euler);
	}
}

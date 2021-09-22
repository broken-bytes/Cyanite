#pragma once

namespace BrokenBytes::Cyanite::Engine::World {
	struct Quaternion;
#pragma pack(push, 1)
	struct Vector3D {
	public:
		Vector3D();
		Vector3D(float x, float y, float z);
		auto operator+=(Vector3D& rhs)->Vector3D&;
		friend auto operator+(Vector3D lhs, Vector3D& rhs)->Vector3D;
		
		float x;
		float y;
		float z;

	private:
		friend struct Quaternion;
		auto Quaternion() const->Quaternion;
	};
#pragma pack(pop)
}

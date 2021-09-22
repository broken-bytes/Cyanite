#pragma once

namespace BrokenBytes::Cyanite::Engine::World {
    struct Vector3D;
#pragma pack(push, 1)
	struct Quaternion {
    public:
        Quaternion();
    	
        Quaternion(float w, float x, float y, float z);
        explicit Quaternion(Vector3D euler);
		
        auto Euler() const->Vector3D;

        float w;
        float x;
        float y;
        float z;
	};
#pragma pack(pop)
}

#pragma once


#include <type_traits>

namespace BrokenBytes::Cyanite::Engine::World {
#pragma pack(push, 1)
    template <
        typename T,
		typename = std::enable_if_t<std::is_arithmetic<T>::value>
	>
        struct Vector3D {
        public:
			Vector3D() {
                this->x = 0;
                this->y = 0;
                this->z = 0;
			}

            Vector3D(T x, T y, T z) {
                this->x = x;
                this->y = y;
                this->z = z;
            }
    	
            T x;
            T y;
            T z;
    };
#pragma pack(pop)
}

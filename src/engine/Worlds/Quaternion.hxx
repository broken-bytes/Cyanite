#pragma once


namespace BrokenBytes::Cyanite::Engine::World {
#pragma pack(push, 1)
    template <
        typename T,
        typename = std::enable_if_t<std::is_arithmetic<T>::value>
    >
	struct Quaternion {
    public:
    	Quaternion() {
            this->x = 0;
            this->y = 0;
            this->z = 0;
            this->q = 0;
    	}
    	
        Quaternion(T x, T y, T z, T q) {
            this->x = x;
            this->y = y;
            this->z = z;
            this->q = q;
        }

        T x;
        T y;
        T z;
        T q;
	};
#pragma pack(pop)
}

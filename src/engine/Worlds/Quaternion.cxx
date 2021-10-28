#include <cmath>
#include <numbers>

#include "Quaternion.hxx"
#include "Vector3D.hxx"

namespace BrokenBytes::Cyanite::Engine::World {
#ifdef MSVC
constexpr double PI = std::numbers::pi;
#elif __APPLE__
constexpr double PI = 3.14;
#endif

    Quaternion::Quaternion() : Quaternion(0, 0, 0, 0) {}

    Quaternion::Quaternion(float w, float x, float y, float z) {
        this->w = w;
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Quaternion::Quaternion(Vector3D euler) {
        auto q = euler.Quaternion();
        this->w = q.w;
        this->x = q.x;
        this->y = q.y;
        this->z = q.z;
    }

    auto Quaternion::Euler() const -> Vector3D {
        Vector3D euler;

        // roll (x-axis rotation)
        float sinr_cosp = 2 * (this->w * this->x + this->y * this->z);
        float cosr_cosp = 1 - 2 * (this->x * this->x + this->y * this->y);
        euler.x = std::atan2(sinr_cosp, cosr_cosp);

        // pitch (y-axis rotation)
        float sinp = 2 * (this->w * this->y - this->z * this->x);
        if (std::abs(sinp) >= 1)
            euler.y = std::copysign(PI / 2, sinp); // use 90 degrees if out of range
        else
            euler.y = std::asin(sinp);

        // yaw (z-axis rotation)
        float siny_cosp = 2 * (this->w * this->z + this->x * this->y);
        float cosy_cosp = 1 - 2 * (this->y * this->y + this->z * this->z);
        euler.z = std::atan2(siny_cosp, cosy_cosp);

        return euler;
    }
}

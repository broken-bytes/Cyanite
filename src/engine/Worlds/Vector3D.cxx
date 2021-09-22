#include <math.h>
#include <cmath>
#include <numbers>

#include "Vector3D.hxx"
#include "Quaternion.hxx"

namespace BrokenBytes::Cyanite::Engine::World {
    Vector3D::Vector3D() : Vector3D(0, 0, 0) {}

    Vector3D::Vector3D(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    auto Vector3D::operator+=(Vector3D& rhs) -> Vector3D& {
        this->x += rhs.x;
        this->y += rhs.y;
        this->z += rhs.z;

        return *this;
    }

    auto operator+(Vector3D lhs, Vector3D& rhs) -> Vector3D {
        lhs += rhs;
        return lhs;
    }

    auto Vector3D::Quaternion() const -> World::Quaternion {
        World::Quaternion q;
        float cy = cos(this->z * 0.5);
        float sy = sin(this->z * 0.5);
        float cp = cos(this->y * 0.5);
        float sp = sin(this->y * 0.5);
        float cr = cos(this->x * 0.5);
        float sr = sin(this->x * 0.5);

        q.w = cr * cp * cy + sr * sp * sy;
        q.x = sr * cp * cy - cr * sp * sy;
        q.y = cr * sp * cy + sr * cp * sy;
        q.z = cr * cp * sy - sr * sp * cy;

        return q;
    }
}

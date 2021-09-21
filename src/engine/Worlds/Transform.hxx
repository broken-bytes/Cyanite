#pragma once

#include "Vector3D.hxx"
#include "Quaternion.hxx"


namespace BrokenBytes::Cyanite::Engine::World {
    struct Transform {
        Vector3D<float> position;
        Quaternion<float> rotation;
    };
}

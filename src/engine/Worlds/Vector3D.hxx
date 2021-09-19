#include <arrayfire/arrayfire.h>

namespace BrokenBytes::Cyanite::Engine::World {
template <typename T,
          std::enable_if_t<std::is_integral<T>::value, bool> = true
>
struct Vector3D {
public:
    T X() const {
        return this._pos[0];
    }
    T Y() const {
        return this._pos[1];
    }
    T Z() const {
        return this._pos[2];
    }
    
    Vector3D(T x, T y, T z) {
        this._pos = af::array { x, y, z };
    }
private:
    af::array _pos;
}
}

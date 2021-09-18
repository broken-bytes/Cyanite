#pragma once
#include <type_traits>


namespace BrokenBytes::Cyanite::Engine::Rendering {
template <typename T,
          std::enable_if_t<std::is_integral<T>::value, bool> = true
>
struct ColorRGBA {
    T r;
    T g;
    T b;
    T a;
};

template <typename T,
          std::enable_if_t<std::is_integral<T>::value, bool> = true
>
struct ColorRGB {
    T r;
    T g;
    T b;
};
}

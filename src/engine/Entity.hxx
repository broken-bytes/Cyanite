#pragma once

#include <uuid.h>


uuid_t empty;

namespace BrokenBytes::Cyanite::Engine {

struct Entity {
public:
    uuid test2;
    uuids::uuid test;
    uuids::uuid UUID() const;
private:
};
}

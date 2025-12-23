#pragma once
#include <cstdint>
#include "Component.h"

namespace Neon::ECS {

    struct Entity {
        EntityID id;
        uint64_t signature; // Bitmask of components
    };

}

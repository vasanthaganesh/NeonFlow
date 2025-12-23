#pragma once

// Forward decl
namespace Neon::ECS { class World; }

namespace Neon::ECS {

    class ISystem {
    public:
        virtual ~ISystem() = default;
        virtual void Update(World& world, float deltaTime) = 0;
    };

}

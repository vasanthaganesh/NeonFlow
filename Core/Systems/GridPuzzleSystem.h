#pragma once
#include "../ECS/System.h"

#include "../ECS/System.h"
#include "../NeonPort.h"

namespace Neon::Systems {

    class NEON_API GridPuzzleSystem : public ECS::ISystem {
    public:
        void Update(ECS::World& world, float deltaTime) override;
    };

}

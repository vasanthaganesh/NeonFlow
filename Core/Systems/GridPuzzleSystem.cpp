#include "GridPuzzleSystem.h"
#include "../Logic/GridLogic.h"

namespace Neon::Systems {

    static Neon::Logic::GridLogic gridLogic(6, 6);

    void GridPuzzleSystem::Update(ECS::World& world, float deltaTime) {
        // 1. Handle Input (Swaps) - Buffered from InputSystem
        // gridLogic.Swap(...)

        // 2. Run Match Logic
        gridLogic.CheckMatches();
    }

}

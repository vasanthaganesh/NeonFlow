#include "MovementSystem.h"
#include "../Logic/RunnerLogic.h"
#include "../ECS/Component.h"
#include <iostream>

namespace Neon::Systems {

    // In a real engine, systems might share state via the World or a ServiceLocator.
    // For scaffolding, we'll keep a static logic instance here or assume it's passed in.
    // To keep it simple, we'll instantiate it here.
    static Neon::Logic::RunnerLogic runnerLogic;

    void MovementSystem::Update(ECS::World& world, float deltaTime) {
        // 1. Update Core Logic
        // In a real game, matchRate would come from GridSystem
        float matchRate = 0.0f; 
        runnerLogic.Update(deltaTime, matchRate);

        // 2. Sync ECS Entities (Example: Player Position)
        // Here we would iterate entities with Velocity and apply logic speed
        // float speed = runnerLogic.GetSpeed();
        
        // For Scaffolding: Just log occasionally
        // std::cout << "Speed: " << speed << std::endl;
    }

}

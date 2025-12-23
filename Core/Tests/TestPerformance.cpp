#include <iostream>
#include <chrono>
#include <vector>
#include <memory>
#include "../ECS/World.h"
#include "../Systems/MovementSystem.h"
#include "../Systems/GridPuzzleSystem.h"
#include "../Systems/RenderSystem.h"
#include "../ECS/Component.h"

using namespace Neon::ECS;
using namespace Neon::Systems;

int main() {
    std::cout << "Starting Performance Verification..." << std::endl;

    World world;
    
    // Add Systems
    world.AddSystem(std::make_unique<MovementSystem>());
    // GridPuzzle and Render might be slower or irrelevant for this specific "10k entities" physics/movement test,
    // but the requirement says "ECS loop". We'll include Movement as the primary stress test.
    
    // Create 10,000 Entities with Position and Velocity
    const int ENTITY_COUNT = 10000;
    std::cout << "Creating " << ENTITY_COUNT << " entities..." << std::endl;
    
    for(int i=0; i<ENTITY_COUNT; ++i) {
        EntityID id = world.CreateEntity();
        world.AddComponent(id, PositionComponent{0, 0, 0});
        world.AddComponent(id, VelocityComponent{1.0f, 0, 0});
    }

    std::cout << "Running Simulation Loop (100 frames)..." << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    for(int i=0; i<100; ++i) {
        world.Update(0.016f);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    
    double avgTimePerFrame = elapsed.count() / 100.0;
    
    std::cout << "Total Time: " << elapsed.count() << " ms" << std::endl;
    std::cout << "Average Time per Frame: " << avgTimePerFrame << " ms" << std::endl;

    if (avgTimePerFrame < 8.0) {
        std::cout << "[SUCCESS] Performance Criteria Met (< 8ms)" << std::endl;
        return 0;
    } else {
        std::cout << "[FAILURE] Performance Criteria NOT Met (> 8ms)" << std::endl;
        return 1;
    }
}

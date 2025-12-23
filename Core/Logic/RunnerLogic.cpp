#include "RunnerLogic.h"
#include <algorithm>
#include <random>

namespace Neon::Logic {

    RunnerLogic::RunnerLogic() : currentSpeed(10.0f), spawnTimer(0.0f), baseSpeed(10.0f) {}

    void RunnerLogic::Update(float deltaTime, float matchRate) {
        // "Flow State": Speed increases with match rate
        currentSpeed = baseSpeed + (matchRate * 5.0f);

        // Update Obstacles
        for (auto& obs : obstacles) {
            obs.zPosition += currentSpeed * deltaTime;
        }

        // Culling
        obstacles.erase(std::remove_if(obstacles.begin(), obstacles.end(), 
            [](const Obstacle& o) { return o.zPosition > 10.0f; }), // Passed camera
            obstacles.end());

        // Spawning
        spawnTimer += deltaTime * (currentSpeed / 10.0f);
        if (spawnTimer > 2.0f) {
            SpawnObstacle();
            spawnTimer = 0.0f;
        }
    }

    void RunnerLogic::SpawnObstacle() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> laneDist(0, 5); // 6 Lanes
        std::uniform_int_distribution<> typeDist(1, 3); // 3 Colors

        Obstacle obs;
        obs.zPosition = -100.0f; // Far away
        obs.lane = laneDist(gen);
        obs.type = typeDist(gen);
        obstacles.push_back(obs);
    }

}

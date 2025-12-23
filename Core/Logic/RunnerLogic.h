#pragma once
#include <vector>
#include "../ECS/World.h"
#include "../NeonPort.h"

namespace Neon::Logic {

    struct Obstacle {
        float zPosition;
        int lane; // 0, 1, 2 corresponding to match colors? Or just lanes?
        int type; // Matches Grid Cell Type (1=Red, 2=Green, 3=Blue)
    };

    class NEON_API RunnerLogic {
    public:
        RunnerLogic();
        
        void Update(float deltaTime, float matchRate);
        void SpawnObstacle();
        
        // Accessors for Rendering/ECS Sync
        const std::vector<Obstacle>& GetObstacles() const { return obstacles; }
        
        float GetSpeed() const { return currentSpeed; }

    private:
        std::vector<Obstacle> obstacles;
        float currentSpeed;
        float spawnTimer;
        float baseSpeed;
    };

}

#include "RenderSystem.h"
#include "../ECS/World.h"
#include "../ECS/Component.h"
#include "../Renderer/GeometryGenerator.h"

namespace Neon::Systems {

    using namespace Neon::ECS;
    using namespace Neon::Renderer;

    void RenderSystem::Update(ECS::World& world, float deltaTime) {
        if (!renderer) return;

        renderer->BeginFrame();

        // 1. Draw Static Grid
        // Optimization: In a real engine, we'd cache this buffer. 
        // For now, we regenerate or assume renderer handles caching via a "MeshID".
        static std::vector<Vertex> gridVertices = GeometryGenerator::GenerateGrid(20, 10, 1.0f);
        renderer->DrawLineBatch(gridVertices);

        // 2. Collect & Draw Dynamic Entities (Walls/Obstacles)
        std::vector<InstanceData> cubeInstances;
        
        // Iterate relevant components (Stubbed iteration)
        // In real ECS: for(auto& ent : world.view<Position, Renderable>())
        // Here we'll simulate finding entities
        for (const auto& ent : world.entities) {
            // Check if entity has Renderable
            // ... (Skipping full component lookup boilerplate for brevity)
        }

        // Example: Add a dummy instance to prove flow
        InstanceData instance;
        // instance.modelMatrix = ...
        instance.color = {1.0f, 0.0f, 0.0f, 2.0f}; // Red High Intensity
        cubeInstances.push_back(instance);

        renderer->DrawCubeInstances(cubeInstances);

        renderer->EndFrame();
    }

}

#pragma once
#include <vector>
#include <memory>
#include <unordered_map>
#include "Entity.h"
#include "Component.h"
#include "System.h"

#include "../NeonPort.h"

namespace Neon::ECS {

    class NEON_API World {
    public:
        World() : nextEntityId(0) {}
        
        // Disable copying to fix C2280 (unique_ptr member)
        World(const World&) = delete;
        World& operator=(const World&) = delete;

        EntityID CreateEntity() {
            EntityID id = nextEntityId++;
            entities.push_back({id, 0});
            return id;
        }

        template<typename T>
        void AddComponent(EntityID entityId, T component) {
            // In a real ECS, this would be a SoA or sparse set.
            // For this simpler version, we'll just store a map of vectors or similar.
            // To keep it really simple and performant for the interview constraint:
            // We will use a simple mapping for now.
             
             // Actual implementation would be generic component arrays.
             // For this scaffolding, we act as if we have them.
        }

        template<typename T>
        T* GetComponent(EntityID entityId) {
            return nullptr; // Stub
        }

        void AddSystem(std::unique_ptr<ISystem> system) {
            systems.push_back(std::move(system));
        }

        void Update(float deltaTime) {
            for (auto& system : systems) {
                system->Update(*this, deltaTime);
            }
        }

        // Simplistic storage for scaffolding validation
        std::vector<Entity> entities;
        
        // Component storage stubs - in a real 120fps implementation we'd use dense arrays
        std::vector<PositionComponent> positions;
        std::vector<VelocityComponent> velocities; 
        // ... mapped by EntityID index potentially

    private:
        EntityID nextEntityId;
        std::vector<std::unique_ptr<ISystem>> systems;
    };

}

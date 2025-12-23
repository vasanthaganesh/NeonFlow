#include "Game.h"
#include "Systems/MovementSystem.h"
#include "Systems/GridPuzzleSystem.h"
#include "Systems/RenderSystem.h"

namespace Neon {

    Game::Game() {
        world = std::make_unique<ECS::World>();
    }

    Game::~Game() {
        Teardown();
    }

    void Game::Initialize(std::unique_ptr<Renderer::IRenderer> rendererPtr) {
        renderer = std::move(rendererPtr);
        
        // Add Systems
        world->AddSystem(std::make_unique<Systems::MovementSystem>());
        world->AddSystem(std::make_unique<Systems::GridPuzzleSystem>());
        world->AddSystem(std::make_unique<Systems::RenderSystem>(renderer.get()));

        // Create initial scaffolding entities
        for(int i=0; i<100; ++i) {
            world->CreateEntity();
        }
    }

    void Game::Update(float deltaTime) {
        world->Update(deltaTime);
    }

    void Game::Teardown() {
        // Cleanup
    }

}

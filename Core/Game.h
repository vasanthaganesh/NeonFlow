#pragma once
#include <memory>
#include "ECS/World.h"
#include "Renderer/IRenderer.h"

#include "NeonPort.h"

namespace Neon {

    class NEON_API Game {
    public:
    public:
        Game();
        ~Game();

        // Disable copying
        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;

        void Initialize(std::unique_ptr<Renderer::IRenderer> renderer);
        void Update(float deltaTime);
        void Teardown();

    private:
        std::unique_ptr<ECS::World> world;
        std::unique_ptr<Renderer::IRenderer> renderer;
    };

}

#pragma once
#include "../ECS/System.h"
#include "../Renderer/IRenderer.h"
#include "../NeonPort.h"

namespace Neon::Systems {

    class NEON_API RenderSystem : public ECS::ISystem {
    public:
        RenderSystem(Neon::Renderer::IRenderer* renderer) : renderer(renderer) {}
        void Update(ECS::World& world, float deltaTime) override;
    private:
        Neon::Renderer::IRenderer* renderer;
    };

}

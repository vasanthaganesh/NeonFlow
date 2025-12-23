#pragma once
#include <cstdint>
#include <vector>

namespace Neon::ECS {

    using EntityID = uint32_t;

    enum class ComponentType {
        Position,
        Velocity,
        Renderable,
        GridCell,
        PlayerInput,
        Count
    };

    struct IComponent {
        virtual ~IComponent() = default;
    };

    struct PositionComponent : IComponent {
        float x, y, z;
        PositionComponent(float x=0, float y=0, float z=0) : x(x), y(y), z(z) {}
    };

    struct VelocityComponent : IComponent {
        float vx, vy, vz;
        VelocityComponent(float vx=0, float vy=0, float vz=0) : vx(vx), vy(vy), vz(vz) {}
    };

    struct RenderableComponent : IComponent {
        int meshId;
        uint32_t color; // 0xAABBGGRR
    };

    struct GridCellComponent : IComponent {
        int row, col;
        int type; // 0=Empty, 1=Red, 2=Green, 3=Blue
    };

}

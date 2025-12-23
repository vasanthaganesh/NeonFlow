#pragma once
#include <cstdint>

// Shared structures between C++ and Shaders (HLSL/GLSL/MSL equivalent)
// Use specific alignment to match std140/std430 LAYOUT_STD140

namespace Neon::Renderer {

    struct alignas(16) Float3 {
        float x, y, z;
        float padding; // standard alignment padding
    };

    struct alignas(16) Float4 {
        float x, y, z, w;
    };

    struct alignas(16) Matrix4x4 {
        float m[16];
    };

    // Vertex Format
    struct Vertex {
        Float3 position;
        Float4 color; // R, G, B, A (Intensity stored in A for Glow)
    };

    // Uniform Buffer for Global State
    struct GlobalUniforms {
        Matrix4x4 viewProjection;
        float time;
        float speed;
        float padding[2];
    };

    // Push Constants / Instance Data
    struct InstanceData {
        Matrix4x4 modelMatrix;
        Float4 color;
    };

}

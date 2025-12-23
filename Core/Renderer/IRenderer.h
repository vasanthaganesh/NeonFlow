#pragma once
#include <vector>
#include "ShaderDefinitions.h"

namespace Neon::Renderer {

    class IRenderer {
    public:
        virtual ~IRenderer() = default;
        
        virtual void Initialize() = 0;
        virtual void BeginFrame() = 0;
        virtual void EndFrame() = 0;

        virtual void UpdateGlobalUniforms(const Matrix4x4& viewParam, const Matrix4x4& projParam, float time) = 0;

        // "Neon" Style Primitives
        // Draw a set of lines (e.g., for the scrolling grid)
        virtual void DrawLineBatch(const std::vector<Vertex>& vertices) = 0;

        // Draw instanced cubes (e.g., for walls/obstacles)
        virtual void DrawCubeInstances(const std::vector<InstanceData>& instances) = 0;
    };


}

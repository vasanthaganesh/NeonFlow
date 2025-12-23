#pragma once
#include <vector>
#include "ShaderDefinitions.h"
#include "../NeonPort.h"

namespace Neon::Renderer {

    class NEON_API GeometryGenerator {
    public:
        // Generates the infinite scrolling floor lines
        static std::vector<Vertex> GenerateGrid(int rows, int cols, float spacing);
        
        // Generates a unit cube wireframe or solid mesh (for instances)
        static std::vector<Vertex> GenerateCubeUnit(); 
    };

}

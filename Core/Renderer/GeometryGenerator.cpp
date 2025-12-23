#include "GeometryGenerator.h"

namespace Neon::Renderer {

    std::vector<Vertex> GeometryGenerator::GenerateGrid(int rows, int cols, float spacing) {
        std::vector<Vertex> lines;
        float width = cols * spacing;
        float depth = rows * spacing;
        float xStart = -width / 2.0f;
        float zStart = 0.0f; // Start at 0, go negative into screen

        Float4 color = {1.0f, 0.0f, 1.0f, 1.0f}; // Neon Purple default

        // Vertical lines
        for (int i = 0; i <= cols; ++i) {
            float x = xStart + i * spacing;
            lines.push_back({{x, 0.0f, 0.0f, 0.0f}, color});
            lines.push_back({{x, 0.0f, -depth, 0.0f}, color});
        }

        // Horizontal lines
        for (int i = 0; i <= rows; ++i) {
            float z = zStart - i * spacing;
            lines.push_back({{xStart, 0.0f, z, 0.0f}, color});
            lines.push_back({{xStart + width, 0.0f, z, 0.0f}, color});
        }
        
        return lines;
    }

    std::vector<Vertex> GeometryGenerator::GenerateCubeUnit() {
        std::vector<Vertex> lines;
        Float4 color = {1.0f, 1.0f, 1.0f, 1.0f}; // White base, colored by instance

        // Define 8 corners
        // -0.5 to 0.5 range
        float v[] = {
            -0.5f, -0.5f, -0.5f, // 0
             0.5f, -0.5f, -0.5f, // 1
             0.5f,  0.5f, -0.5f, // 2
            -0.5f,  0.5f, -0.5f, // 3
            -0.5f, -0.5f,  0.5f, // 4
             0.5f, -0.5f,  0.5f, // 5
             0.5f,  0.5f,  0.5f, // 6
            -0.5f,  0.5f,  0.5f  // 7
        };

        auto addLine = [&](int i, int j) {
            lines.push_back({{v[i*3], v[i*3+1], v[i*3+2]}, color});
            lines.push_back({{v[j*3], v[j*3+1], v[j*3+2]}, color});
        };

        // Bottom Square
        addLine(0, 1); addLine(1, 2); addLine(2, 3); addLine(3, 0);
        // Top Square
        addLine(4, 5); addLine(5, 6); addLine(6, 7); addLine(7, 4);
        // Columns
        addLine(0, 4); addLine(1, 5); addLine(2, 6); addLine(3, 7);

        return lines;
    }

}

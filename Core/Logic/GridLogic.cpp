#include "GridLogic.h"

#include <algorithm>
#include <random>

namespace Neon::Logic {

    GridLogic::GridLogic(int rows, int cols) : rows(rows), cols(cols) {
        grid.resize(rows * cols, 0);
        Refill(); // Initial fill
    }

    void GridLogic::Swap(int r1, int c1, int r2, int c2) {
        if (r1 < 0 || r1 >= rows || c1 < 0 || c1 >= cols ||
            r2 < 0 || r2 >= rows || c2 < 0 || c2 >= cols) return;
        
        std::swap(grid[r1 * cols + c1], grid[r2 * cols + c2]);
    }

    void GridLogic::CheckMatches() {
        // Simple horizontal and vertical match-3 check
        // In a real game, we'd queue matches for animation
        std::vector<int> toClear;

        // Rows
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols - 2; ++c) {
                int idx = r * cols + c;
                int val = grid[idx];
                if (val == 0) continue;
                if (grid[r * cols + (c + 1)] == val && grid[r * cols + (c + 2)] == val) {
                    toClear.push_back(idx);
                    toClear.push_back(r * cols + (c + 1));
                    toClear.push_back(r * cols + (c + 2));
                }
            }
        }

        // Cols
        for (int c = 0; c < cols; ++c) {
            for (int r = 0; r < rows - 2; ++r) {
                int idx = r * cols + c;
                int val = grid[idx];
                if (val == 0) continue;
                if (grid[(r + 1) * cols + c] == val && grid[(r + 2) * cols + c] == val) {
                    toClear.push_back(idx);
                    toClear.push_back((r + 1) * cols + c);
                    toClear.push_back((r + 2) * cols + c);
                }
            }
        }

        // Clear matches
        for (int idx : toClear) {
            grid[idx] = 0; // 0 = Empty
        }

        if (!toClear.empty()) {
            Refill();
        }
    }

    void GridLogic::Refill() {
        // Drop down logic (simplified)
        for (int c = 0; c < cols; ++c) {
            int writeRow = rows - 1;
            for (int r = rows - 1; r >= 0; --r) {
                int idx = r * cols + c;
                if (grid[idx] != 0) {
                    grid[writeRow * cols + c] = grid[idx];
                    writeRow--;
                }
            }
            // Fill top with random
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distr(1, 3); // 1-3 types (Red, Green, Blue)

            while (writeRow >= 0) {
                grid[writeRow * cols + c] = distr(gen);
                writeRow--;
            }
        }
    }

}


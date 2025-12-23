#pragma once
#include <vector>

#include "../NeonPort.h"

namespace Neon::Logic {

    class NEON_API GridLogic {
    public:
        GridLogic(int rows, int cols);
        void Swap(int r1, int c1, int r2, int c2);
        void CheckMatches();
        void Refill();
        
        const std::vector<int>& GetGrid() const { return grid; }
        int GetRows() const { return rows; }
        int GetCols() const { return cols; }
    private:
        int rows, cols;
        std::vector<int> grid; // Row-major
    };

}

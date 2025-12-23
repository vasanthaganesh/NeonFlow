#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <windows.h> // For Sleep and Console API
#include "../Logic/GridLogic.h"
#include "../Logic/RunnerLogic.h"

using namespace Neon::Logic;

// ANSI Colors
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string BLUE = "\033[34m";
const std::string WHITE = "\033[37m";

std::string GetColor(int type) {
    switch (type) {
        case 1: return RED + "R" + RESET;
        case 2: return GREEN + "G" + RESET;
        case 3: return BLUE + "B" + RESET;
        default: return ".";
    }
}

void SetCursor(int x, int y) {
    COORD c = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main() {
    // Enable ANSI codes in Windows 10+
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);

    GridLogic grid(6, 6);
    RunnerLogic runner;

    std::cout << "NEON FLOW - WINDOWS CONSOLE PREVIEW" << std::endl;
    std::cout << "Press Ctrl+C to Exit" << std::endl;
    Sleep(2000);
    
    float time = 0.0f;

    while (true) {
        // Logic Update
        runner.Update(0.1f, 0.5f); // 0.5 match rate simulation
        grid.CheckMatches(); // Just static check for now

        // Render
        SetCursor(0, 0);
        std::cout << "========================================" << std::endl;
        std::cout << " Speed: " << runner.GetSpeed() << " | Time: " << (int)time << std::endl;
        std::cout << "========================================" << std::endl;

        // Draw Lanes (Endless Runner)
        // View distance 0 to 20
        for (int z = 20; z >= 0; --z) {
            std::string laneStr = "| ";
            
            // Check for obstacles at this Z
            bool found[6] = {false};
            for (const auto& obs : runner.GetObstacles()) {
                if ((int)obs.zPosition == z && obs.lane >= 0 && obs.lane < 6) {
                    found[obs.lane] = true;
                }
            }

            for(int l=0; l<6; ++l) {
               laneStr += (found[l] ? "[#]" : " . ");
            }
            laneStr += " |";
            std::cout << laneStr << std::endl;
        }

        std::cout << "========================================" << std::endl;
        std::cout << " MATCH-3 GRID" << std::endl;
        std::cout << "========================================" << std::endl;

        const auto& cells = grid.GetGrid();
        int rows = grid.GetRows();
        int cols = grid.GetCols();

        for(int r=0; r<rows; ++r) {
            std::cout << " ";
            for(int c=0; c<cols; ++c) {
                std::cout << " " << GetColor(cells[r*cols+c]) << " ";
            }
            std::cout << std::endl;
        }

        time += 0.1f;
        Sleep(100); // 10 FPS for console
    }

    return 0;
}

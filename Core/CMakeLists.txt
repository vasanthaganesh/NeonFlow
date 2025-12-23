add_library(NeonCore SHARED
    Game.cpp
    Game.h
    ECS/World.h
    ECS/Entity.h
    ECS/Component.h
    ECS/System.h
    Systems/MovementSystem.cpp
    Systems/MovementSystem.h
    Systems/GridPuzzleSystem.cpp
    Systems/GridPuzzleSystem.h
    Systems/RenderSystem.cpp
    Systems/RenderSystem.h
    Logic/GridLogic.cpp
    Logic/GridLogic.h
    Logic/RunnerLogic.cpp
    Logic/RunnerLogic.h
    Renderer/IRenderer.h
    Renderer/GeometryGenerator.cpp
    Renderer/GeometryGenerator.h
    Renderer/ShaderDefinitions.h
)

target_include_directories(NeonCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(NeonCore PRIVATE NEON_EXPORTS)


if(ANDROID)
    target_link_libraries(NeonCore log android)
endif()

# Test Executable (Headless Performance)
add_executable(TestPerformance Tests/TestPerformance.cpp)
target_link_libraries(TestPerformance PRIVATE NeonCore)

# Test Executable (Windows Console Visualizer)
add_executable(TestVisual Tests/TestVisual.cpp)
target_link_libraries(TestVisual PRIVATE NeonCore)

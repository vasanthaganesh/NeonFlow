# Neon Flow 🌊🟦🟥

**Neon Flow** is a high-performance, native C++ mobile game built from scratch without a game engine. It targets **120 FPS** on iOS (Metal) and Android (Vulkan/GLES), featuring a unique "Vector Neon" aesthetic and a hybrid Endless Runner + Match-3 gameplay loop.

![Visualizer Preview](https://via.placeholder.com/800x400?text=Neon+Flow+Console+Visualizer)
*(Placeholder for actual gameplay screenshot)*

## 🚀 Features

*   **Engine-less Architecture**: Built on a custom C++23 Core (`NeonCore`) for maximum performance and battery life.
*   **Cross-Platform Core**: Shared logic for Physics, ECS, and Rendering across iOS and Android.
*   **Entity-Component-System (ECS)**: Custom lightweight ECS for managing thousands of entities efficiently.
*   **Procedural Generation**: Infinite "Tron-like" grid world generated on the fly.
*   **Hybrid Gameplay**: 
    *   **Runner**: Dodge obstacles in a 3-lane tunnel.
    *   **Puzzle**: Match-3 mechanics on the grid to gain speed and score.

## 🛠️ Architecture

The project is structured into three main layers:

1.  **Core (`/Core`)**: 
    *   **ECS**: System, World, Entity, Component definitions.
    *   **Logic**: Game rules (`RunnerLogic`, `GridLogic`).
    *   **Renderer**: Abstract `IRenderer` interface and geometry generation.
    *   **Tests**: Windows Console Visualizer and Headless Performance tests.
2.  **Platform (`/Platform`)**:
    *   **iOS**: Swift `ViewController` bridging to C++ via Objective-C++. Uses **Metal** for rendering.
    *   **Android**: Kotlin `MainActivity` bridging via JNI. Uses **Vulkan** (planned) for rendering.
3.  **Build System**: CMake 3.25+ orchestrating the build for all platforms.

## 📦 Building & Verification

### Prerequisites
*   **CMake** (3.25 or newer)
*   **Visual Studio 2022** (Windows) with C++ Desktop Development credentials.
*   **Android Studio** (for Android deployment).
*   **Xcode** (for iOS deployment, macOS only).

### Run the Windows Visualizer
To verify the build and see the game logic in action on Windows (ASCII Visualizer):

1.  Open `verify_build.bat` in a terminal (or double-click it).
2.  This script will:
    *   Generate VS Solution files.
    *   Compile `NeonCore` and Test executables.
    *   Run a Performance Benchmark (validating < 8ms frame time for 10k entities).
    *   Launch the **ASCII Console Preview**.

```cmd
verify_build.bat
```

## 📱 Deployment

### Android
Open `Platform/Android` in **Android Studio**. The build scripts (`settings.gradle`, `build.gradle`) are configured to build the C++ library automatically via CMake.

### iOS
Generate the Xcode project using CMake:
```bash
mkdir ios_build && cd ios_build
cmake .. -G Xcode -DCMAKE_SYSTEM_NAME=iOS
```
Open the generated `.xcodeproj` file.

## 🤝 Contributing
This project is a demonstration of high-performance native mobile development. PRs optimizing the ECS or adding new render backends are welcome!

## 📜 License
MIT License.

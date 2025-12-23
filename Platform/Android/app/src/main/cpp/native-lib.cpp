#include <jni.h>
#include <string>
#include <android/native_window_jni.h>
#include <android/asset_manager_jni.h>
#include "../../../../Core/Game.h"

// Global Game Instance
static std::unique_ptr<Neon::Game> gameInstance;

extern "C" JNIEXPORT void JNICALL
Java_com_antigravity_neonflow_MainActivity_nativeInit(
        JNIEnv* env,
        jobject /* this */,
        jobject assetManager,
        jobject surface) {
    
    // ANativeWindow* window = ANativeWindow_fromSurface(env, surface);
    // Neon::Renderer::VulkanRenderer renderer(window);
    
    // gameInstance = std::make_unique<Neon::Game>();
    // gameInstance->Initialize(std::move(renderer));
}

extern "C" JNIEXPORT void JNICALL
Java_com_antigravity_neonflow_MainActivity_nativeRender(
        JNIEnv* env,
        jobject /* this */) {

    if (gameInstance) {
        gameInstance->Update(0.016f); // Assume 60fps for now
    }
}

extern "C" JNIEXPORT void JNICALL
Java_com_antigravity_neonflow_MainActivity_nativeTouch(
        JNIEnv* env,
        jobject /* this */,
        jfloat x,
        jfloat y) {
            
    // Pass input to game
}

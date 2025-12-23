package com.antigravity.neonflow

import android.app.Activity
import android.os.Bundle
import android.view.SurfaceHolder
import android.view.SurfaceView
import android.view.MotionEvent

class MainActivity : Activity(), SurfaceHolder.Callback {

    init {
        System.loadLibrary("NeonCore")
    }

    private external fun nativeInit(assetManager: Any, surface: Any)
    private external fun nativeResize(width: Int, height: Int)
    private external fun nativeRender()
    private external fun nativeTouch(x: Float, y: Float)

    private lateinit var surfaceView: SurfaceView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        
        surfaceView = SurfaceView(this)
        surfaceView.holder.addCallback(this)
        setContentView(surfaceView)
    }

    override fun surfaceCreated(holder: SurfaceHolder) {
        nativeInit(assets, holder.surface)
        // Start Render Loop (Thread)
        Thread {
            while (true) {
                nativeRender()
            }
        }.start()
    }

    override fun surfaceChanged(holder: SurfaceHolder, format: Int, width: Int, height: Int) {
        nativeResize(width, height)
    }

    override fun surfaceDestroyed(holder: SurfaceHolder) {
        // nativeCleanup()
    }

    override fun onTouchEvent(event: MotionEvent): Boolean {
        if (event.action == MotionEvent.ACTION_DOWN) {
            nativeTouch(event.x, event.y)
        }
        return true
    }
}

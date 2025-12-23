import UIKit
import MetalKit

// Bridge to C++ Core (Simulated Import)
// import NeonCore

class ViewController: UIViewController, MTKViewDelegate {
    
    var mtkView: MTKView!
    var displayLink: CADisplayLink?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Setup Metal View
        mtkView = MTKView(frame: self.view.bounds)
        mtkView.device = MTLCreateSystemDefaultDevice()
        mtkView.delegate = self
        mtkView.preferredFramesPerSecond = 120 // Target 120Hz
        self.view.addSubview(mtkView)
        
        // Initialize C++ Game
        // NeonGame.initialize(mtkView.device)
        print("Neon Flow: iOS Initialized")
    }
    
    func mtkView(_ view: MTKView, drawableSizeWillChange size: CGSize) {
        // NeonGame.resize(width: size.width, height: size.height)
    }
    
    func draw(in view: MTKView) {
        // Main Game Loop Hook
        // let deltaTime = 1.0 / 120.0
        // NeonGame.update(deltaTime)
    }
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        guard let touch = touches.first else { return }
        let location = touch.location(in: self.view)
        // NeonGame.onTouchDown(x: Float(location.x), y: Float(location.y))
    }
}

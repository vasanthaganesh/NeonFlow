#version 450

// Neon Glow Fragment Shader (GLSL Reference)
// Concept:
// 1. Render Scene to HDR Framebuffer (Color Attachment 0)
// 2. Extract High Brightness (Threshold) -> Blur (Ping-Pong) -> Additive Blend

layout(location = 0) in vec4 inColor;
layout(location = 0) out vec4 outFragColor;

// Uniforms
layout(binding = 0) uniform GlobalUniforms {
    mat4 viewProejction;
    float time;
    float speed; // Used for "pulsating" glow
};

void main() {
    // Base Color from Vertex Interpolation
    vec4 baseColor = inColor;

    // "Pulsate" the intensity based on time
    float pulse = 0.8 + 0.2 * sin(time * 5.0);
    
    // Intensity is stored in Alpha channel of the vertex color for efficiency
    float intensity = baseColor.a * 2.0; 

    // Final Output Color
    // RGB = Color * Pulse * Intensity
    // A = 1.0 (Opaque geometry)
    vec3 glowingColor = baseColor.rgb * pulse * intensity;

    outFragColor = vec4(glowingColor, 1.0);
}

/* 
   POST-PROCESS BLUR SHADER (Conceptual):
   
   vec4 blur() {
       vec2 tex_offset = 1.0 / textureSize(image, 0); 
       vec4 result = texture(image, TexCoords) * weight[0]; 
       for(int i = 1; i < 5; ++i) {
            result += texture(image, TexCoords + vec2(tex_offset.x * i, 0.0)) * weight[i];
            result += texture(image, TexCoords - vec2(tex_offset.x * i, 0.0)) * weight[i];
       }
       return result;
   }
*/

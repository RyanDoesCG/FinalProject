#version 120

// varying is shared between shaders
varying vec2 textureCoordinate_vary;
varying vec3 normal_vary;

// uniform is a variable shared between CPU and GPU
uniform sampler2D diffuse;

/** 
 *  basicShader.frag
 *
 *  
 */
void main (void) {
    // unified device coordinates
    gl_FragColor = vec4(0.6, 0.6, 0.6, 1.0) //texture2D(diffuse, textureCoordinate_vary)
        * clamp(dot(-vec3(0, 0, 1), normal_vary), 0.0, 1.0);
    
    // lambertian lighting
    // negative for reflection simulation
    // clamped to prevent ridiculous lighting
    // vec3 represents light direction
}

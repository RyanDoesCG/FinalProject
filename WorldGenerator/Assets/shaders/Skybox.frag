#version 330 core
out vec4 color;
in vec4 worldPosition;
uniform vec3 objectColour;

/**
 * CREDIT:
 *  http://byteblacksmith.com/improvements-to-the-canonical-one-liner-glsl-rand-for-opengl-es-2-0/
 */
mediump float rand(vec2 co) {
    highp float a = 12.9898;
    highp float b = 78.233;
    highp float c = 43758.5453;
    highp float dt= dot(co.xy ,vec2(a,b));
    return fract(sin(dt) * c);
}


void main (void) {
    float rnd = rand(vec2(worldPosition.y, worldPosition.x));
    
    if (rnd < 0.000005) {
        color = vec4(1.0, 1.0, 1.0, 0.8 + rnd);
    } else {
        color = vec4(objectColour, 1.0f);
    }
}

#version 330 core

layout (location = 0) in vec4 position;

// Transformation Matrices
uniform mat4  modelMat;
uniform mat4  viewMat;
uniform mat4  projectionMat;

// User Interaction
uniform vec3 mousePos;

// RNG
uniform float time;
highp float rand(vec2 co);

// PASS THROUGH
out vec4  FRAG_position;
out float FRAG_colorID;
out float FRAG_mouseX;
out float FRAG_mouseY;

void main (void) {
    // PASS THROUGH
    FRAG_position = projectionMat * viewMat * modelMat * vec4(
        position.x + (rand(vec2(position.y, time)) / 20),
        position.y + (rand(vec2(time, position.z)) / 20),
        position.z + (rand(vec2(position.x, time)) / 20),
        1.0f
    );
    
    FRAG_colorID = position.w;
    
    FRAG_mouseX = (projectionMat * viewMat * modelMat * vec4(
        mousePos.x,
        mousePos.y,
        mousePos.z,
        1.0f
    )).x;
    
    FRAG_mouseY = (projectionMat * viewMat * modelMat * vec4(
        mousePos.x,
        mousePos.y,
        mousePos.z,
        1.0f
    )).y;
    
    // VERT CODE
    gl_Position = projectionMat * viewMat * modelMat * vec4(
        position.x + (rand(vec2(position.y, time)) / 20),
        position.y + (rand(vec2(time, position.z)) / 20),
        position.z + (rand(vec2(position.x, time)) / 20),
        1.0f
    );
}

/**
 * CREDIT: 
 *  http://byteblacksmith.com/improvements-to-the-canonical-one-liner-glsl-rand-for-opengl-es-2-0/
 */
highp float rand(vec2 co) {
    highp float a = 12.9898;
    highp float b = 78.233;
    highp float c = 43758.5453;
    highp float dt= dot(co.xy ,vec2(a,b));
    highp float sn= mod(dt,3.14);
    return fract(sin(sn) * c);
}

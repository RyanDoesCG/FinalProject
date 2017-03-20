#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uvs;

uniform float seaLevel;
uniform float time;
uniform mat4 model;

const float PI = 3.141592653589;
const float AMPLITUDE = 0.00060;

/**
 *  CREDIT: https://www.youtube.com/watch?v=r2hue52wLF4
 *  adapted by Ryan Needham
 */
float generateHeight(){
    float component1 = sin(2.0 * PI * (time * 0.75) + (position.x * 24.0)) * AMPLITUDE;
    float component2 = sin(2.0 * PI * (time * 0.75) + (position.y * position.x * 12.0)) * AMPLITUDE;
    return component1 + component2;
}

void main() {
    float height = generateHeight();
    
    // set position
    gl_Position = model * vec4(position.x, position.y +     height, position.z, 1.0f);
    
}

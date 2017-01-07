#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 texCoords;

uniform float time;
uniform mat4 model;

const float PI = 3.141592653589;
const float AMPLITUDE = 0.00130;

out vec3 vertexColour;

/**
 *  CREDIT: https://www.youtube.com/watch?v=r2hue52wLF4
 *  adapted by Ryan Needham
 */
float generateHeight(){
    float component1 = sin(2.0 * PI * (time * 0.75) + (position.x * 64.0)) * AMPLITUDE;
    float component2 = sin(2.0 * PI * (time * 0.75) + (position.y * position.x * 32.0)) * AMPLITUDE;
    return component1 + component2;
}

void main() {
    float height = 0.02 + generateHeight();
    // set position
    gl_Position = model * vec4(position.x, position.y + height, position.z, 1.0f);
    
    // pass through
    if      (texCoords.x == 1) { vertexColour = vec3(0.2, 0.4, 0.45); }
    else if (texCoords.x == 2) { vertexColour = vec3(0.22, 0.42, 0.47); }
    else                       { vertexColour = vec3(0.24, 0.44, 0.49); }
    
}


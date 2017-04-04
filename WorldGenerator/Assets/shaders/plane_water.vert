#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uvs;

uniform float renderDistance;
uniform float seaLevel;
uniform float time;
uniform mat4 model;
uniform vec4 colour;
uniform vec3 viewPosition;

const float PI = 3.141592653589;
const float AMPLITUDE = 0.00060;

out vec4 vertexColour;

/**
 *  CREDIT: https://www.youtube.com/watch?v=r2hue52wLF4
 *  adapted by Ryan Needham
 */
float generateHeight(){
    float component1 = sin(2.0 * PI * (time * 0.45) + (position.x * 24.0)) * AMPLITUDE;
    float component2 = sin(2.0 * PI * (time * 0.45) + (position.y * position.x * 12.0)) * AMPLITUDE;
    return component1 + component2;
}

float rand      (vec2 c) { return fract(sin(dot(c.xy ,vec2(12.9898,78.233))) * 43758.5453); }
float magnitude (vec3 v) { return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)); }

void main() {
    float height =  generateHeight() + (rand(vec2(time * AMPLITUDE, (model * vec4(position, 1.0)).z)) * 0.00008);
    
    // set position
    gl_Position = model * vec4(position.x, position.y + height, position.z, 1.0f);
    
    vec4 worldPos = model * vec4(position.x, (position.y + height) * 0.5, position.z, 1.0f);
    float ting = rand(vec2(worldPos.x, worldPos.y));
    
    // PASS THROUGH
    vertexColour = colour * 1.0;
    
    if      (ting > 0.33) vertexColour *=  0.95;
    else if (ting > 0.33 && ting < 0.66) vertexColour *= 1.0;
    else vertexColour = vertexColour *= 1.05;
    
    vertexColour.a = 0.75;
    
    if (magnitude(viewPosition - vec3(worldPos.xyz)) > renderDistance) {
        vertexColour.a -= (magnitude(viewPosition - vec3(worldPos.xyz)) - renderDistance) * 0.25;
    }
}

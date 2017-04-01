#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

// Transforms
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

// Height Data
uniform sampler2D tex;

// Runtime Variables
uniform vec4 colour;
uniform vec3 viewPosition;
uniform float renderDistance;
uniform float seaLevel;
uniform float amp;


float magnitude (vec3 v) { return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)); }
float rand      (vec2 c) { return fract(sin(dot(c.xy ,vec2(12.9898,78.233))) * 43758.5453); }

void main (void) {
    float lift = -0.04 + abs((texture(tex, uv).r) * amp);
    
    gl_Position =  vec4(position.x, position.y + lift, position.z, 1.0);
}

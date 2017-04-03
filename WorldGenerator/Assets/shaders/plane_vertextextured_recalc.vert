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
uniform float smoothing;
uniform float amp;

flat out float alpha;

float magnitude (vec3 v) { return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)); }
float rand      (vec2 c) { return fract(sin(dot(c.xy ,vec2(12.9898,78.233))) * 43758.5453); }

void main (void) {
    float lift = -0.04 + (0.5 * abs((texture(tex, uv).r) * amp)) + (rand (vec2(position.x, position.z)) * smoothing);
    
    gl_Position =  vec4(position.x, position.y + lift, position.z, 1.0);
    
    alpha = 1;
    
        vec4 worldPos = model * vec4(position.x, (position.y + lift), position.z, 1.0f);
    if (magnitude(viewPosition - vec3(worldPos.xyz)) > renderDistance) {
        alpha -= (magnitude(viewPosition - vec3(worldPos.xyz)) - renderDistance) * 0.5;
    }

}

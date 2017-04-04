#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

out vec3 frag_worldPos;
out vec4 frag_colour;
out vec3 frag_normal;
out vec2 frag_uv;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec4 colour;
uniform vec3 viewPosition;
uniform sampler2D tex;

uniform float renderDistance;
uniform float seaLevel;
uniform float amp;

float magnitude (vec3 v) { return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)); }

float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

void main (void) {
    
    /** COMPUTE ALTITUDE */
    vec4 objectWorldPos = model * vec4(0.0, 0.0, 0.0, 1.0);
    float height = -121 + abs((texture(tex, vec2(objectWorldPos.x / 20, -1 * (objectWorldPos.z / 20))).r) * (amp * 248));
    if (height < -100) { height = -10000; }
    
    /** PROCEDURAL VARIATION */
    
    vec4 worldPos = model * vec4(position.xyz, 1.0f);
    
    
    gl_Position = projection * view * model * vec4(
        position.x + mod(rand(vec2(worldPos.x, worldPos.y)), 0.20f),
        position.y + mod(rand(vec2(worldPos.z, worldPos.x)), 0.32f) + height,
        position.z + mod(rand(vec2(worldPos.x, worldPos.z)), 0.20f),
        1.0f
    );
    
    /** PASS THROUGH */
    frag_worldPos = vec3(worldPos.xyz);
    frag_colour = colour;
    vec4 worldPosition = model * vec4(position.x, position.y + height, position.z, 1.0);
    if (magnitude(viewPosition - vec3(worldPosition.xyz)) > renderDistance) {
        frag_colour.a = frag_colour.a - (magnitude(viewPosition - vec3(worldPosition.xyz)) - renderDistance) * 0.25;
    }
    frag_normal = normal;
    frag_uv     = uv;
}

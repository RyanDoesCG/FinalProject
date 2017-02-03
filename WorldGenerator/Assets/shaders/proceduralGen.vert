#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 tc;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 worldPosition;
out vec3 norm;
out vec2 fragTc;

float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

void main (void) {
    vec4 worldPos = model * vec4(position.xyz, 1.0f);
    
    gl_Position = projection * view * model * vec4(
        position.x + mod(rand(vec2(worldPos.x, worldPos.y)), 0.25f),
        position.y + mod(rand(vec2(worldPos.z, worldPos.y)), 0.32f),
        position.z + mod(rand(vec2(worldPos.x, worldPos.z)), 0.25f),
        1.0f
    );
    
        // pass through
    worldPosition = vec3(model * vec4(position, 1.0f));
    norm = normal;//mat3(transpose(inverse(model))) * normal;
    fragTc = tc;
}

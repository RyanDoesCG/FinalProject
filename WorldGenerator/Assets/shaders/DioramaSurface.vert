#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 tc;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 objectColour;

// height map
uniform sampler2D heightMap;

out vec3 vertexColour;

float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

void main (void) {
    vec4 heightData = texture(heightMap, tc);

    gl_Position = model * vec4(
        position.x,
        position.y + rand(vec2(position.x, position.z)), //+ heightData.r + heightData.g + heightData.b + heightData.a,
        position.z,
        1.0f
    );
    
    // pass through
    vertexColour = objectColour;
}

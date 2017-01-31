#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 objectColour;

out vec3 vertexColour;

//out vec3 worldPosition;
//out vec3 norm;

float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

void main (void) {
    gl_Position = model * vec4(
        position.x,
        position.y + rand(vec2(position.z, position.x)),
        position.z,
        1.0f
    );
    
    // pass through
    vertexColour = objectColour;
    
    //worldPosition = vec3(model * vec4(position, 1.0f));
    //norm = mat3(transpose(inverse(model))) * normal;
}

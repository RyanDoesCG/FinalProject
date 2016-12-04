#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 texCoords;

out vec3 worldPosition;
out vec3 vertexColour;
out vec3 norm;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main() {


    // set position
    gl_Position = projection * view * model * vec4(position, 1.0f);
    
    // pass through
    if (texCoords.x == 1) {
        vertexColour = vec3(0.4, 0.4, 0.85) * 0.75;
    }
    else if (texCoords.x == 2) {
        vertexColour = vec3(0.4, 0.4, 0.85) * 0.85;
    }
    else {
        vertexColour = vec3(0.4, 0.4, 0.85) * 0.95;
    }
    
    worldPosition = vec3(model * vec4(position, 1.0f));
    norm = mat3(transpose(inverse(model))) * normal;
}


#version 330 core

layout (location = 0) in vec3 position;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projectionMat;

out vec3  FRAG_position;

void main (void) {
    gl_Position = modelMat *vec4(
        position.x,
        position.y,
        position.z,
        1.0f
    );
    
    FRAG_position = position;
}

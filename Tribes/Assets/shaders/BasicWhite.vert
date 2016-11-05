#version 330 core

layout (location = 0) in vec3 position;
//layout (location = 1) in vec3 color;
//layout (location = 2) in vec2 textureCoord;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projectionMat;

out vec4 FRAG_pos;

void main (void) {
    gl_Position = FRAG_pos = modelMat *vec4(
        position.x,
        position.y,
        position.z,
        1.0f
    );
}

#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 textureCoord;

out vec3 FRAG_position;
out vec2 FRAG_textureCoord;
out vec3 FRAG_color;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projectionMat;

void main (void) {
    gl_Position = projectionMat * viewMat * modelMat * vec4(position, 1.0f);
    FRAG_textureCoord = textureCoord;
    FRAG_position     = position;
    FRAG_color        = color;
}

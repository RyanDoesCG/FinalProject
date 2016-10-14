#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 tc;

out vec3 pos;
out vec2 textCoord;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projectionMat;

void main (void) {
    gl_Position = projectionMat * viewMat * modelMat * vec4(position, 1.0f);
    textCoord   = tc;
    pos         = position;
}

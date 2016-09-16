#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 tc;

uniform vec4 proceduralColor;

out vec4 procColor;
out vec2 textCoord;

void main (void) {
    gl_Position = vec4 (position, 1.0f);
    procColor = color;
    textCoord = tc;
    
}
#version 330 core

layout (location = 0) in vec3 position;
layout (location = 2) in vec3 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec4 FRAG_pos;

void main (void) {
    gl_Position = FRAG_pos = projection * view * model * vec4(position, 1.0f);
}

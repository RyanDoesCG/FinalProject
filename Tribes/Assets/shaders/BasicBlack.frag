#version 330 core

in vec3 FRAG_position;
in vec2 FRAG_textureCoord;
in vec3 FRAG_color;

out vec4 color;

// simple solid black
void main (void) { color = vec4(0.22, 0.22, 0.22, 1.0f); }

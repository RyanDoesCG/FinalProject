#version 330 core

uniform int selected;

in vec4 FRAG_pos;
out vec4 color;

void main (void) {
    if (selected == 0)
        color = vec4(0.1, 0.1, 0.1, 1.0f);
    else
        color = vec4(0.3, 0.3, 0.3, 1.0);
}
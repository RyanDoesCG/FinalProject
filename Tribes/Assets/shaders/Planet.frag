#version 330 core

in vec3 FRAG_position;

out vec4 color;

void main (void) {
    color = vec4(0.55, 0.55, 0.55, 1.0f) * vec4(FRAG_position.x - 0.2, FRAG_position.x - 0.2 , FRAG_position.x - 0.2,  1.0f);
}

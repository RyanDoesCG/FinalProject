#version 330 core

in vec3 FRAG_position;
in vec2 FRAG_textureCoord;
in vec3 FRAG_color;

out vec4 color;

// solid black
void main (void) {
    color = vec4(0.0f, 0.0f, 0.0f, 1.0f) ;//* (FRAG_position.x / 2);
}

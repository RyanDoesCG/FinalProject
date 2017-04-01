#version 330 core

in vec2 frag_uvs;
out vec4 color;

uniform sampler2D tex;
uniform vec3 col;

void main (void) {
    vec4 samp = vec4 (1.0, 1.0, 1.0, texture(tex, frag_uvs).r);
    color = vec4 (col, 1.0) * samp;
}

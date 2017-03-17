#version 330 core
in vec2  uvs;
out vec4 color;

uniform sampler2D text;
uniform vec3 colour;

void main() {
    vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, uvs).r);
    color = vec4(colour, 1.0) * sampled;
}

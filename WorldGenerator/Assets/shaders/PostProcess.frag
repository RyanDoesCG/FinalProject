#version 330 core

in vec2 frag_texCoords;

out vec4 color;

uniform sampler2D screenTexture;

void main() {
    color = texture(screenTexture, frag_texCoords);
}
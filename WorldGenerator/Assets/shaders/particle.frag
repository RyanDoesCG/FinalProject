#version 330 core

in vec2 frag_texCoords;

out vec4 color;

uniform sampler2D screenTexture;
uniform vec3 objectColour;

void main() {
    color = vec4(objectColour.rgb, 1.0f);//texture(screenTexture, frag_texCoords);
}

#version 330 core

in vec3 procColor;
in vec2 textCoord;

out vec4 color;

uniform sampler2D tex;

void main (void) {
    // Varying blue value
    color = texture(tex, texCoord);
}

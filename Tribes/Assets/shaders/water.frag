#version 330 core

in vec3  finalColour;
out vec4 color;

void main (void) {
    color = vec4(finalColour, 0.8f);
}

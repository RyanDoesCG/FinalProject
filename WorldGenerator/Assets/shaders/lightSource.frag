#version 330 core
out vec4 color;

uniform vec3 objectColour;

void main (void) {
    color = vec4(objectColour, 1.0f);
}

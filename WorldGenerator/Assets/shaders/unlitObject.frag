#version 330 core

uniform vec3 objectColour;

out vec4 color;

void main (void) {

    color = vec4(objectColour.xyz, 1.0f);
}

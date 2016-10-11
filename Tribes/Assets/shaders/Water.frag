#version 330 core

in  vec2 textCoord;
out vec4 color;

uniform sampler2D tex;

void main (void) {
    // Varying blue value
//    color = texture(tex, textCoord); // use texture

    color = vec4(0.67, 0.61, 0.71, 1.0);
}

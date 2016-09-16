#version 330 core

out vec4 color;

//uniform vec4 randomColor;

void main (void) {
    // random from CPU
    //color = randomColor;

    // cool green
    color = vec4(0.52f, 0.64f, 0.49f, 1.0f);

    // black
    //color = vec4(0.0f, 0.0f, 0.0f, 1.0f);
}

#version 330 core

layout (location=0) out vec4 vFragColor;	//fragment shader output

void main() {
    //output solid white color as fragment output
    vFragColor = vec4(0, 0, 0, 1);
}

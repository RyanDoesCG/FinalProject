#version 330 core

in vec4 frag_colour;
in vec3 frag_normal;
in vec2 frag_uv;

out vec4 color;

uniform sampler2D tex;

void main (void) {
    color = texture(tex, frag_uv);//vec4(0.21, 0.21, 0.21, 1.0);
}

#version 330 core

in vec4 frag_colour;
in vec3 frag_normal;
in vec2 frag_uv;

out vec4 color;

uniform vec4 colour;
uniform sampler2D tex;

void main (void) {
    color = vec4(texture(tex, frag_uv).rgb, frag_colour.a);
}

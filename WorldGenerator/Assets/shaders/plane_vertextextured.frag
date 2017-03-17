#version 330 core

in vec4 frag_colour;
in vec3 frag_normal;
in vec2 frag_uv;

out vec4 color;

uniform sampler2D tex;

float magnitude (vec3 v) { return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)); }

void main (void) {
    color = vec4(frag_colour.rgb, frag_colour.a) * texture(tex, frag_uv);
}

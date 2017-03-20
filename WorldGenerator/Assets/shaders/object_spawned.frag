#version 330 core

in vec3 frag_worldPos;
in vec4 frag_colour;
in vec3 frag_normal;
in vec2 frag_uv;

out vec4 color;

uniform sampler2D tex;

float rand (vec2 c) { return fract(sin(dot(c.xy ,vec2(12.9898,78.233))) * 43758.5453); }

void main (void) {
    color = vec4((frag_colour * ((rand(vec2(frag_worldPos.x, frag_worldPos.z))) + 0.75) * 0.5).rgb, frag_colour.a);
}

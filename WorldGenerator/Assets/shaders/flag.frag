#version 330 core

in vec4 frag_colour;
in vec3 frag_normal;
in vec2 frag_uv;

out vec4 color;

uniform vec4 colour;
uniform sampler2D tex;

float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

void main (void) {
    if (vec4(texture(tex, frag_uv).rgb, frag_colour.a) ==
        vec4(0.0, 0.0, 0.0, frag_colour.a)) {
        color = colour * vec4(rand(vec2(colour.r, colour.g)) * 10, rand(vec2(colour.r, colour.g)) * 10, rand(vec2(colour.r, colour.g)) * 10, frag_colour.a);
    } else {
        color = colour * vec4(texture(tex, frag_uv).rgb, frag_colour.a);
    }
}

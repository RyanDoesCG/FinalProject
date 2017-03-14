#version 330 core

in vec4 frag_position;
in vec4 frag_colour;
in vec3 frag_normal;
in vec2 frag_uv;

out vec4 color;

uniform sampler2D tex;

void main (void) {
    vec4 fadex = vec4(abs(1.0 - frag_position.x), abs(1.0 - frag_position.x), abs(1.0 - frag_position.x), 1.0);
    vec4 fadey = vec4(abs(1.0 - frag_position.y), abs(1.0 - frag_position.y), abs(1.0 - frag_position.y), 1.0);

    color = texture(tex, frag_uv) * fadex * fadey;
}

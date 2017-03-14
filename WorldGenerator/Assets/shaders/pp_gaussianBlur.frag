#version 330 core

in vec4 frag_position;
in vec4 frag_colour;
in vec3 frag_normal;
in vec2 frag_uv;

out vec4 color;

uniform sampler2D tex;

const float offset = 1.0 / 300;

void main (void) {

    vec2 offsets[9] = vec2[] (
        vec2 (-offset, offset),
        vec2 (0.0f,    offset),
        vec2 (offset,  offset),
        vec2 (-offset, 0.0f),
        vec2 (0.0f,    0.0f),
        vec2 (offset,  0.0f),
        vec2 (-offset, -offset),
        vec2 (0.0f,    -offset),
        vec2 (offset,  -offset)
    );
    
    float kernel [9] = float [] (
        1.0 / 16, 2.0 / 16, 1.0 / 16,
        2.0 / 16, 4.0 / 16, 2.0 / 16,
        1.0 / 16, 2.0 / 16, 1.0 / 16
    );
    
    vec3 sampleTexture [9];
    for (int i = 0; i < 9; i++)
        sampleTexture[i] = vec3(texture(tex, frag_uv.st + offsets[i]));

    vec3 col = vec3(0.0);
    for (int i = 0; i < 9; i++)
        col += sampleTexture[i] * kernel[i];
    
    color = vec4(col, 1.0);
}

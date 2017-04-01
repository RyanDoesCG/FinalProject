#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

out vec4 frag_colour;
out vec3 frag_normal;
out  vec2 frag_uv;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec4 colour;
uniform vec3 viewPosition;
uniform sampler2D tex;
uniform float renderDistance;
uniform float seaLevel;
uniform float amp;

float magnitude (vec3 v) { return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)); }
float rand      (vec2 c) { return fract(sin(dot(c.xy ,vec2(12.9898,78.233))) * 43758.5453); }

const float offset = 1.0 / 300;

void main (void) {
   // float lift = -0.04 + abs((texture(tex, uv).r) * amp);
    
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
        sampleTexture[i] = vec3(texture(tex, uv.st + offsets[i]) * amp);
    
    vec3 pos = vec3(0.0);
    for (int i = 0; i < 9; i++)
        pos += sampleTexture[i] * kernel[i];
    
    float lift = -0.05 + abs(pos.r);
    
    gl_Position = projection * view * model * vec4(position.x, position.y + lift, position.z, 1.0);
    
    // fade out of view
    frag_colour = colour;
  
    /*
    float num = rand(uv);
    if      (num < 0.3)              { frag_colour = vec4(frag_colour.rgb * 0.95, frag_colour.a); }
    else if (num > 0.3 && num < 0.6) { frag_colour = vec4(frag_colour.rgb * 1.00, frag_colour.a); }
    else                             { frag_colour = vec4(frag_colour.rgb * 1.05, frag_colour.a); }
    */
    
    vec4 worldPosition = model * vec4(position.x, position.y + lift, position.z, 1.0);
    if (magnitude(viewPosition - vec3(worldPosition.xyz)) > renderDistance) {
        frag_colour.a = frag_colour.a - (magnitude(viewPosition - vec3(worldPosition.xyz)) - renderDistance) * 0.25;
    }
    
    frag_normal = normal;
    frag_uv     = uv;
}

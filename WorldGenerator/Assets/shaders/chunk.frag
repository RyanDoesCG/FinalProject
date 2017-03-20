#version 330 core

in vec4 frag_worldPos;
in vec4 frag_colour;
in vec3 frag_normal;
in vec2 frag_uv;

uniform vec3 viewPosition;
const float renderDistance = 5;

out vec4 color;

float magnitude (vec3 v) { return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)); }

void main (void) {
    vec4 col = frag_colour;
    
    if (magnitude(viewPosition - vec3(frag_worldPos.xyz)) > renderDistance) {
        col.a = col.a - (magnitude(viewPosition - vec3 (frag_worldPos.xyz)) * 0.75);
    }
    
    color = col;
}

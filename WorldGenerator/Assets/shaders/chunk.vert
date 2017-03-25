#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

out vec4 frag_worldPos;
out vec4 frag_colour;
out vec3 frag_normal;
out vec2 frag_uv;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec4 colour;

float rand (vec2 c) { return /*fract(sin(dot(c.xy ,vec2(12.9898,78.233))) * 43758.5453)*/ 0; }

void main (void) {
    gl_Position = projection * view * model * vec4(position.x, position.y + (0.05 * rand (vec2(position.x, position.z))), position.z, 1.0);
    
    frag_worldPos = model * vec4(position.x, position.y, position.z, 1.0);
    frag_colour = colour;
    frag_normal = normal;
    frag_uv     = uv;
}

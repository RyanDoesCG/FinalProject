#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

out vec4 frag_position;
out vec4 frag_colour;
out vec3 frag_normal;
out vec2 frag_uv;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec4 colour;

void main (void) {
    gl_Position = projection * view * model * vec4(position.x, position.y, position.z, 1.0);
    
    frag_position = vec4 (position.xyz, 1.0);
    frag_colour = colour;
    frag_normal = normal;
    frag_uv     = uv;
}

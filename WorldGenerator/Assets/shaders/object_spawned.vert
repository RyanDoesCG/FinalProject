#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

out vec4 frag_colour;
out vec3 frag_normal;
out vec2 frag_uv;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec4 colour;

uniform sampler2D tex;

void main (void) {
    vec4 worldPos = model * vec4(0.0, 0.0, 0.0, 1.0);
    float height = -100 + (texture(tex, vec2(worldPos.x / 20, -1 * (worldPos.z / 20))).r * 75);

    gl_Position = projection * view * model * vec4(position.x, position.y + height, position.z, 1.0);
    
    frag_colour = colour;
    frag_normal = normal;
    frag_uv     = uv;
}

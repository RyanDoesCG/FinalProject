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
uniform vec3 viewPosition;
uniform sampler2D tex;

float magnitude (vec3 v) { return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)); }

void main (void) {
    vec4 worldPos = model * vec4(0.0, 0.0, 0.0, 1.0);
    float height = -112 + (texture(tex, vec2(worldPos.x / 20, -1 * (worldPos.z / 20))).r * 98);

    if (height < -90) { height = -1000; }
    
    gl_Position = projection * view * model * vec4(position.x, position.y + height, position.z, 1.0);
    
        // fade out of view
    frag_colour = colour;
    vec4 worldPosition = model * vec4(position.x, position.y + height, position.z, 1.0);
    
    if (magnitude(viewPosition - vec3(worldPosition.xyz)) > 8) {
        frag_colour.a = frag_colour.a - (magnitude(viewPosition - vec3(worldPosition.xyz)) - 8) * 0.75;
    }
    
    frag_normal = normal;
    frag_uv     = uv;
}

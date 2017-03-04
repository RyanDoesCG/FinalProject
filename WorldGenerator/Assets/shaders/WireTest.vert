#version 330 core

layout (location = 0) in vec3 vVertex;

uniform mat4        model;
uniform mat4        view;
uniform mat4        proj;

uniform ivec2        HALF_TERRAIN_SIZE;
uniform sampler2D    heightMapTexture;
uniform float        scale;
uniform float        half_scale;

void main() {
    float height = texture(heightMapTexture, vVertex.xz).r*scale - half_scale;
    vec2 pos     = (vVertex.xz*2.0-1)*HALF_TERRAIN_SIZE;
    
    
    gl_Position = model * view * proj * vec4(pos.x, pos.y, pos.z, 1);
}

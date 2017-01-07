#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 noise;
layout (location = 3) in float biome;

out vec3 vertexColour;

uniform vec3 objectColour;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform int generationType;

mediump float rand(vec2 co);

void main() {
    float lift = (noise.x + noise.y + noise.z);
    //float lift = biome + (noise.x + noise.y + noise.z);

    gl_Position = model * vec4(position.x, position.y + lift, position.z, 1.0f);
    
    // pass through
    vertexColour = objectColour * biome;
}

/**
 * CREDIT:
 *  http://byteblacksmith.com/improvements-to-the-canonical-one-liner-glsl-rand-for-opengl-es-2-0/
 */
mediump float rand(vec2 co) {
    highp float a = 12.9898;
    highp float b = 78.233;
    highp float c = 43758.5453;
    highp float dt= dot(co.xy ,vec2(a,b));
    return fract(sin(dt) * c);
}

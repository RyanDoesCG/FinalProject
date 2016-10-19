#version 330 core

layout (location = 0) in vec3 position;

out vec4 FRAG_position;

uniform mat4  modelMat;
uniform mat4  viewMat;
uniform mat4  projectionMat;
uniform float time;

highp float rand(vec2 co);

void main (void) {
    gl_Position = projectionMat * viewMat * modelMat * vec4(
        position.x + (rand(vec2(position.y, time)) / 10),
        position.y + (rand(vec2(time, position.z)) / 10),
        position.z + (rand(vec2(position.x, time)) / 10),
        1.0f
    );
    
    FRAG_position = projectionMat * viewMat * modelMat * vec4(
        position.x,
        position.y,
        position.z,
        1.0f
    );
}

// CREDIT: http://byteblacksmith.com/improvements-to-the-canonical-one-liner-glsl-rand-for-opengl-es-2-0/
highp float rand(vec2 co) {
    highp float a = 12.9898;
    highp float b = 78.233;
    highp float c = 43758.5453;
    highp float dt= dot(co.xy ,vec2(a,b));
    highp float sn= mod(dt,3.14);
    return fract(sin(sn) * c);
}

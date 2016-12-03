#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;

out vec3 worldPosition;
out vec3 norm;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

highp float rand(vec2 co);

void main() {

    vec3 a = vec3(0.0f, 0.0f, 0.0f);    // origin
    vec3 b = position;                  // point to normalise
    

    // set position
    gl_Position = projection * view * model * vec4(b, 1.0f);
    
    // pass through
    worldPosition = vec3(model * vec4(b, 1.0f));
    norm = mat3(transpose(inverse(model))) * normal;
}

/**
 * CREDIT:
 *  http://byteblacksmith.com/improvements-to-the-canonical-one-liner-glsl-rand-for-opengl-es-2-0/
 */
highp float rand(vec2 co) {
    highp float a = 12.9898;
    highp float b = 78.233;
    highp float c = 43758.5453;
    highp float dt= dot(co.xy ,vec2(a,b));
    highp float sn= mod(dt,3.14);
    return fract(sin(sn) * c);
}

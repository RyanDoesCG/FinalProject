#version 330 core

layout (location = 0) in vec3 position;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projectionMat;

uniform float wave;

out vec3  FRAG_position;

highp float rand(vec2 co) {
    highp float a = 12.9898;
    highp float b = 78.233;
    highp float c = 43758.5453;
    highp float dt= dot(co.xy ,vec2(a,b));
    highp float sn= mod(dt,3.14);
    return fract(sin(sn) * c);
}

void main (void) {
    gl_Position = modelMat * vec4(position.x, position.y, position.z, 1.0f);

/*
    float len = 0.94 + (rand(vec2(wave, position.z)) / 200);
    
    vec3 a = vec3(0.0, 0.0, 0.0);
    vec3 b = position;
    
    float distX = b.x - a.x;
    float distY = b.y - a.y;
    float distZ = b.z - a.z;
    
    float a_b = sqrt(distX * distX + distY * distY + distZ * distZ);
    
    distX = distX * len / a_b;
    distY = distY * len / a_b;
    distZ = distZ * len / a_b;
    
    gl_Position = modelMat * vec4 (
        a.x + distX,
        a.y + distY,
        a.z + distZ,
        1.0f
    );
    
    FRAG_position = position;
*/
}

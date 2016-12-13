#version 330 core

layout (location = 0) in vec3 position;

out vec3  FRAG_position;
out float FRAG_time;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projectionMat;

uniform float time;

void main (void) {
    gl_Position = projectionMat * viewMat * modelMat * vec4(position, 1.0f);
    
    // pass through
    FRAG_position     = position;
    FRAG_time         = time;
}

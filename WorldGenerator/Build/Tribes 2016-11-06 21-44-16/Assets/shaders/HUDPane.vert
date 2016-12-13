#version 330 core

layout (location = 0) in vec3 position;

out vec4 FRAG_pos;

void main (void) {
    gl_Position = FRAG_pos = vec4(
        position.x,
        position.y,
        position.z,
        1.0f
    );
}

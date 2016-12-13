#version 330 core

layout (location = 0) in vec3 position;

// to fragment shader
//out vec4 vertexColor;

void main (void) {
    gl_Position = vec4 (
        position.x,
        position.y,
        position.z,
        1.0
    );
    
//    vertexColor = vec4(position, 1.0);
}

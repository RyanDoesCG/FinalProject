#version 330 core

// http://www.geeks3d.com/20130905/exploring-glsl-normal-visualizer-with-geometry-shaders-shader-library/

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

out vec3 geom_normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec4 colour;

void main (void) {
    gl_Position = vec4(position.x, position.y, position.z, 1.0);
    
    geom_normal   = normal;
}

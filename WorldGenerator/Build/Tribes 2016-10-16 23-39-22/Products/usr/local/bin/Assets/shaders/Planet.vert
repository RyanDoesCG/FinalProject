#version 430

// attributes come from mesh
attribute vec3  position;
attribute vec2  textureCoordinate;
attribute vec3  normal;

// varying is shared between shaders
varying   vec2  textureCoordinate_vary;
varying   vec3  normal_vary;

// uniform are shared state between GPU/CPU
uniform   mat4  transform;

void main (void) {
    gl_Position = transform * vec4(position, 1.0);
    
    textureCoordinate_vary = textureCoordinate;
    normal_vary            = (transform * vec4(normal, 0.0)).xyz;
}

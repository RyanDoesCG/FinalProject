#version 330 core

layout (triangles) in;
layout (line_strip, max_vertices = 6) out;

in vec3 geom_normal[];

out vec4 colour;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main(void){
    for (int i = 0; i < gl_in.length(); i++) {
        vec3 position = gl_in[i].gl_Position.xyz;
        vec3 normal = geom_normal[i];
        
        // draw point
        gl_Position = projection * view * model * vec4(position.xyz, 1.0);
        colour = vec4(0.0, 0.0, 1.0, 1.0);
        EmitVertex();
        
        // draw its normal
        gl_Position = projection * view * model * vec4(position * normal, 1.0);
        colour = vec4(0.0, 0.0, 1.0, 1.0);
        EmitVertex();
        
        EndPrimitive();
    }
    
}

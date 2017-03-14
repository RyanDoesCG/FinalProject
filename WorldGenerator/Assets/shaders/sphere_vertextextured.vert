#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

out vec4 frag_colour;
out vec3 frag_normal;
out  vec2 frag_uv;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec4 colour;

uniform sampler2D tex;

void main (void) {
    float lift = 0.9 + (texture(tex, uv).r * 0.25);
    
    vec3 a = vec3(0, 0, 0);
    vec3 b = position;
    
    // get the distance between the center of the structure
    // and the point on the x, y and z axes.
    float distX = b.x - a.x;
    float distY = b.y - a.y;
    float distZ = b.z - a.z;
    
    float a_b = sqrt(distX * distX + distY * distY + distZ * distZ);
    
    distX = distX * lift / a_b;
    distY = distY * lift / a_b;
    distZ = distZ * lift / a_b;
    
    b.x = (a.x + distX);
    b.y = (a.y + distY);
    b.z = (a.z + distZ);
    
    gl_Position = projection * view * model * vec4(b, 1.0);
    
    frag_colour = colour;
    frag_normal = normal;
    frag_uv     = uv;
}

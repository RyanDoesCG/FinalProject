#version 330 core

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

in vec3 vertexColour[];

out vec4 worldPos;
out vec3 finalColour;
out vec3 norm;

uniform mat4 projection;
uniform mat4 view;
uniform vec3 cameraPosition;
uniform vec3 lightColour;
uniform vec3 lightPosition;

const float ambientLighting = 0.24;

vec3 calculateTriangleNormal(){
    vec3 a = gl_in[0].gl_Position.xyz;
    vec3 b = gl_in[1].gl_Position.xyz;
    vec3 c = gl_in[2].gl_Position.xyz;
    
    return normalize(cross(b - a, c - a));
}

void main(void){
    
    vec4 worldPosition  = gl_in[0].gl_Position;
    vec3 normal         = calculateTriangleNormal();
    vec3 lightDirection = normalize(vec3(worldPosition.xyz) - lightPosition);
    float brightness    = max(dot(-lightDirection, normal), ambientLighting);
    vec3 colour         = vertexColour[0] * brightness;
    
    gl_Position = projection * view * worldPosition;
    worldPos    = projection * view * worldPosition;
    finalColour = colour;
    norm        = normal;
    EmitVertex();
    
    worldPosition   = gl_in[1].gl_Position;
    normal          = calculateTriangleNormal();
    lightDirection  = normalize(vec3(worldPosition.xyz) - lightPosition);
    brightness      = max(dot(-lightDirection, normal), ambientLighting);
    colour          = vertexColour[0] * brightness;
    
    gl_Position = projection * view * worldPosition;
    worldPos    = projection * view * worldPosition;
    finalColour = colour;
    norm        = normal;
    EmitVertex();
    
    worldPosition   = gl_in[2].gl_Position;
    normal          = calculateTriangleNormal();
    lightDirection  = normalize(vec3(worldPosition.xyz) - lightPosition);
    brightness      = max(dot(-lightDirection, normal), ambientLighting);
    colour          = vertexColour[0] * brightness;
    
    gl_Position = projection * view * worldPosition;
    worldPos    = projection * view * worldPosition;
    finalColour = colour;
    norm        = normal;
    EmitVertex();
    
    EndPrimitive();
    
}

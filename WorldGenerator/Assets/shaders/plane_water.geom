#version 330 core

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

flat in vec4 vertexColour[];

out vec4 worldPos;
flat out vec4 finalColour;
out vec3 norm;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;
uniform vec3 cameraPosition;
uniform vec3 lightColour;
uniform vec3 lightPosition;
uniform vec4 colour;

const float ambientLighting = 0.8;

vec3 calculateTriangleNormal(){
    vec3 tangent = gl_in[1].gl_Position.xyz - gl_in[0].gl_Position.xyz;
    vec3 bitangent = gl_in[2].gl_Position.xyz - gl_in[0].gl_Position.xyz;
    vec3 normal = cross(tangent, bitangent);
    return normalize(mat3(transpose(inverse(model))) * normal);
}

void main(void){
    
    vec4 worldPosition  = gl_in[0].gl_Position;
    vec3 normal         = calculateTriangleNormal();
    vec3 lightDirection = normalize(vec3(worldPosition.xyz) - lightPosition);
    float brightness    = 1.0; //max(dot(-lightDirection, normal), ambientLighting);
    vec3 colour         = vec3(colour) * brightness;
    
    gl_Position = projection * view * worldPosition;
    worldPos    = worldPosition;
    finalColour = vertexColour[0];
    norm        = normal;
    EmitVertex();
    
    worldPosition   = gl_in[1].gl_Position;
    normal          = calculateTriangleNormal();
    lightDirection  = normalize(vec3(worldPosition.xyz) - lightPosition);
    brightness      = 1; // max(dot(-lightDirection, normal), ambientLighting);
    colour          = vec3(colour) * brightness;
    
    gl_Position = projection * view * worldPosition;
    worldPos    = worldPosition;
    finalColour = vertexColour[1];
    norm        = normal;
    EmitVertex();
    
    worldPosition   = gl_in[2].gl_Position;
    normal          = calculateTriangleNormal();
    lightDirection  = normalize(vec3(worldPosition.xyz) - lightPosition);
    brightness      = 1; //max(dot(-lightDirection, normal), ambientLighting);
    colour          = vec3(colour) * brightness;
    
    gl_Position = projection * view * worldPosition;
    worldPos    = worldPosition;
    finalColour = vertexColour[2];
    norm        = normal;
    EmitVertex();
    
    EndPrimitive();
    
}

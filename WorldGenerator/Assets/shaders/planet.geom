#version 330 core

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

flat in float alpha[];

flat out float f_alpha;
out vec4 worldPos;
out vec3 norm;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

uniform vec3 viewPosition;
uniform vec3 lightColour;
uniform vec3 lightPosition;

const float ambientLighting = 0.42;

vec3 calculateTriangleNormal(){
    vec3 tangent = gl_in[1].gl_Position.xyz - gl_in[0].gl_Position.xyz;
    vec3 bitangent = gl_in[2].gl_Position.xyz - gl_in[0].gl_Position.xyz;
    vec3 normal = cross(tangent, bitangent);
    return normalize(mat3(transpose(inverse(model))) * normal);
}

void main(void){
    
    vec4 worldPosition  = model * gl_in[0].gl_Position;
    vec3 normal         = calculateTriangleNormal();
    vec3 lightDirection = normalize(lightPosition - vec3(worldPosition.xyz));
    float brightness    = max(dot(-lightDirection, normal), ambientLighting);
    
    gl_Position = projection * view * worldPosition;
    f_alpha = alpha[0];
    worldPos    = worldPosition;
    norm        = normal;
    EmitVertex();
    
    worldPosition   = model * gl_in[1].gl_Position;
    normal          = calculateTriangleNormal();
    lightDirection  = normalize(lightPosition - vec3(worldPosition.xyz));
    brightness      = max(dot(-lightDirection, normal), ambientLighting);
    
    gl_Position = projection * view * worldPosition;
    f_alpha = alpha[1];
    worldPos    =  worldPosition;
    norm        = normal;
    EmitVertex();
    
    worldPosition   = model * gl_in[2].gl_Position;
    normal          = calculateTriangleNormal();
    lightDirection  = normalize(lightPosition - vec3(worldPosition.xyz));
    brightness      = max(dot(-lightDirection, normal), ambientLighting);
    
    gl_Position = projection * view * worldPosition;
    f_alpha = alpha[2];
    worldPos    = worldPosition;
    norm        = normal;
    EmitVertex();
    
    EndPrimitive();
    
}
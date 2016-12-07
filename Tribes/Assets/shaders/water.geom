#version 330 core

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

in vec3 vertexColour[];

out vec3 finalColour;

uniform mat4 projection;
uniform mat4 view;
uniform vec3 cameraPosition;
uniform vec3 lightColour;
uniform vec3 lightPosition;

const float reflectivity = 0.32;
const float shineDamper = 16.0;
const float ambientLighting = 0.24;

vec3 calculateTriangleNormal(){
    vec3 a = gl_in[1].gl_Position.xyz;
    vec3 b = gl_in[0].gl_Position.xyz;
    vec3 c = gl_in[2].gl_Position.xyz;
    
    return normalize(cross(b - a, c - a));
}

/**
 *  CREDIT: https://www.youtube.com/watch?v=r2hue52wLF4
 *  adapted by Ryan Needham
 */
vec3 calculateSpecular(vec4 worldPosition, vec3 normal){
    vec3 lightDirection = normalize(lightPosition - vec3(worldPosition.xyz));
    vec3 viewVector = normalize(cameraPosition - worldPosition.xyz);
    vec3 reflectedLightDirection = reflect(-lightDirection, normal);
    float specularFactor = dot(reflectedLightDirection, viewVector);
    specularFactor = max(pow(specularFactor, shineDamper), 0.0);
    return lightColour * specularFactor * reflectivity;
}

void main(void){
    
    vec4 worldPosition  = gl_in[0].gl_Position;
    vec3 normal         = calculateTriangleNormal();
    vec3 lightDirection = normalize(lightPosition - vec3(worldPosition.xyz));
    float brightness    = max(dot(-lightDirection, normal), ambientLighting);
    vec3 colour         = vertexColour[0] * brightness;
    
    gl_Position = projection * view * worldPosition;
    finalColour = colour + calculateSpecular(worldPosition, normal);
    EmitVertex();
    
    worldPosition   = gl_in[1].gl_Position;
    normal          = calculateTriangleNormal();
    lightDirection  = normalize(lightPosition - vec3(worldPosition.xyz));
    brightness      = max(dot(-lightDirection, normal), ambientLighting);
    colour          = vertexColour[0] * brightness;
    
    gl_Position = projection * view * worldPosition;
    finalColour = colour + calculateSpecular(worldPosition, normal);
    EmitVertex();
    
    worldPosition   = gl_in[2].gl_Position;
    normal          = calculateTriangleNormal();
    lightDirection  = normalize(lightPosition - vec3(worldPosition.xyz));
    brightness      = max(dot(-lightDirection, normal), ambientLighting);
    colour          = vertexColour[0] * brightness;
    
    gl_Position = projection * view * worldPosition;
    finalColour = colour + calculateSpecular(worldPosition, normal);
    EmitVertex();
    
    EndPrimitive();
    
}

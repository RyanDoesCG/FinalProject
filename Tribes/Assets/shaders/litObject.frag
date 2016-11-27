#version 330 core

in vec3 worldPosition; // position in world coorinates for lighting calculations
in vec3 norm;

uniform vec3 objectColour;

uniform vec3 lightPosition;
uniform vec3 lightColour;

out vec4 color;

void main (void) {
    vec3 specular;
    vec3 diffuse;
    vec3 ambient;
    
    // diffuse lighting
    vec3 normal = normalize(norm);
    vec3 lightDirection = normalize(lightPosition - worldPosition);
    
    float diffuseImpact = max(dot(norm, lightDirection), 0.0f);
    diffuse = diffuseImpact * lightColour;
    
    // ambient lighting
    float strength = 0.1f;
    ambient = strength * lightColour;
    
    // stacked result
    vec3 result = (ambient + diffuse) * objectColour;
    color = vec4(result, 1.0f);
}

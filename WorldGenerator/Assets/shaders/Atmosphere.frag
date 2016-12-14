#version 330 core

struct Material {
    vec3  ambient;
    vec3  diffuse;
    vec3  specular;
    float shine;
};

in vec3 worldPosition; // position in world coorinates for lighting calculations
in vec3 norm;

uniform Material material;

uniform vec3 objectColour;
uniform vec3 viewPosition;
uniform vec3 lightPosition;
uniform vec3 lightColour;

out vec4 color;

void main (void) {
    
        // ambient lighting
    float ambStrength = 0.15f;
    vec3  ambient     = ambStrength * lightColour;
    
        // diffuse lighting
    vec3  normal         = normalize(norm);
    vec3  lightDirection = normalize(lightPosition - worldPosition);
    float diffStrength   = max(dot(norm, lightDirection), 0.0f);
    vec3  diffuse        = diffStrength * lightColour;
    
        // specular lighting
    float specStrength        = 0.5f;
    vec3  viewDirection       = normalize(viewPosition - worldPosition);
    vec3  reflectionDirection = reflect(-lightDirection, norm);
    float spec                = pow(max(dot(viewDirection, reflectionDirection), 0.0), 32);
    vec3  specular            = specStrength * spec * lightColour;
    
        // stacked result
    vec3 result = (ambient + diffuse + specular) * objectColour;
    
    float largest = 0;
    
    if (result.x > largest) {
        largest = result.x;
    } else if (result.y > largest) {
        largest = result.y;
    } else if (result.z > largest) {
        largest = result.z;
    }
    
    float alpha = 0;
    if (largest > 0.1) {alpha = largest * 0.05;}
    
    
    color = vec4(result, alpha);
}

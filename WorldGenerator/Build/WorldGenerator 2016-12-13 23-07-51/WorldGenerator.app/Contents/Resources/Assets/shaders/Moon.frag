#version 330 core

in vec3 worldPosition;
in vec3 norm;

uniform vec3 objectColour;
uniform vec3 viewPosition;
uniform vec3 lightPosition;
uniform vec3 lightColour;

out vec4 color;

void main (void) {
    
        // ambient lighting
    float ambStrength = 0.55f;
    vec3  ambient     = ambStrength * lightColour;
    
        // diffuse lighting
    vec3  normal         = normalize(norm);
    vec3  lightDirection = normalize(lightPosition - worldPosition);
    float diffStrength   = max(dot(norm, lightDirection), 0.1f);
    vec3  diffuse        = diffStrength * lightColour;
    
        // specular lighting
    float specStrength        = 0.02f;
    vec3  viewDirection       = normalize(viewPosition - worldPosition);
    vec3  reflectionDirection = reflect(-lightDirection, norm);
    float spec                = pow(max(dot(viewDirection, reflectionDirection), 0.0), 0.6);
    vec3  specular            = specStrength * spec * lightColour;
    
        // stacked result
    vec3 result = (ambient + specular) * objectColour;
    color = vec4(result, 1.0f);
}

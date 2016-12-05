#version 330 core

in vec3  finalColour;

/*
in vec3  worldPosition;
in vec3  norm;

uniform vec3 viewPosition;
uniform vec3 lightPosition;
uniform vec3 lightColour;
*/

out vec4 color;

/**
 *  CREDIT: https://www.youtube.com/watch?v=r2hue52wLF4
 *  adapted by Ryan Needham
 */
void main (void) {
/*
    vec3 objectColour = vec3(0.52f, 0.64f, 0.94f);
    
    
        // ambient lighting
    float ambStrength = 0.15f;
    vec3  ambient     = ambStrength * lightColour;
    
        // diffuse lighting
    vec3  normal         = normalize(norm);
    vec3  lightDirection = normalize(lightPosition - worldPosition);
    float diffStrength   = max(dot(norm, lightDirection), 0.0f);
    vec3  diffuse        = (diffStrength*0.5) * lightColour;
    
        // specular lighting
    float specStrength        = 0.05f;
    vec3  viewDirection       = normalize(viewPosition - worldPosition);
    vec3  reflectionDirection = reflect(-lightDirection, norm);
    float spec                = pow(max(dot(viewDirection, reflectionDirection), 0.0), 16);
    vec3  specular            = specStrength * spec * lightColour;
    
        // stacked result
    vec3 result = (ambient + diffuse + specular) * vertexColour;
 */
    color = vec4(finalColour, 0.75f);
}

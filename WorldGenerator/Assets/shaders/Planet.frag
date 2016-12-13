#version 330 core

in vec4 worldPos;
in vec3 finalColour;
in vec3 norm;

uniform vec3 objectColour;
uniform vec3 viewPosition;
uniform vec3 lightPosition;
uniform vec3 lightColour;

uniform mat4 model;

out vec4 color;

void main (void) {
    vec3 normal = normalize(norm);
    
    // ambient lighting
    float ambStrength = 0.30f;
    vec3  ambient     = ambStrength * lightColour;
    
    // diffuse lighting
    vec3  lightDirection = normalize(lightPosition - vec3(worldPos.xyz));
    float diffStrength   = max(dot(normal, lightDirection), 0.0f);
    vec3  diffuse        = diffStrength * lightColour;
    
    // specular lighting
    float specStrength        = 0.4f;
    vec3  viewDirection       = normalize(viewPosition - vec3(worldPos.xyz));
    vec3  reflectionDirection = reflect(-lightDirection, normal);
    float spec                = pow(max(dot(viewDirection, reflectionDirection), 0.2), 8);
    vec3  specular            = specStrength * spec * lightColour;
    
    // stacked result
    vec3 result = (ambient + diffuse + specular) * finalColour;
    color = vec4(result, 1.0f);
}

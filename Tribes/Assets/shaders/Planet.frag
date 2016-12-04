#version 330 core

in vec3 worldPosition;
in vec3 vertexColour;
in vec3 norm;

uniform vec3 objectColour;
uniform vec3 viewPosition;
uniform vec3 lightPosition;
uniform vec3 lightColour;

out vec4 color;

highp float unitRand(vec2 co);

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
    float specStrength        = 0.2f;
    vec3  viewDirection       = normalize(viewPosition - worldPosition);
    vec3  reflectionDirection = reflect(-lightDirection, norm);
    float spec                = pow(max(dot(viewDirection, reflectionDirection), 0.0), 26);
    vec3  specular            = specStrength * spec * lightColour;
    
    // stacked result
    vec3 result = (ambient + diffuse + specular) * vertexColour;
    color = vec4(result, 1.0f);
}

highp float unitRand(vec2 co) {
    highp float a = 12.9898;
    highp float b = 78.233;
    highp float c = 43758.5453;
    highp float dt= dot(co.xy ,vec2(a,b));
    highp float sn= mod(dt,3.14);
    return mod(fract(sin(sn) * c), 100);
}

#version 330 core

in vec3 frag_worldPos;
in vec4 frag_colour;
in vec3 frag_normal;
in vec2 frag_uv;

uniform vec3 viewPosition;
uniform vec3 lightPosition;
uniform vec3 lightColour;

out vec4 color;

void main (void) {
    
    // ambient lighting
    float ambStrength = 0.15f;
    vec3  ambient     = ambStrength * lightColour;
    
    // diffuse lighting
    vec3  normal         = normalize(frag_normal);
    vec3  lightDirection = normalize(lightPosition - frag_worldPos);
    float diffStrength   = max(dot(frag_normal, lightDirection), 0.0f);
    vec3  diffuse        = diffStrength * lightColour;
    
    // specular lighting
    float specStrength        = 0.5f;
    vec3  viewDirection       = normalize(viewPosition - frag_worldPos);
    vec3  reflectionDirection = reflect(-lightDirection, frag_normal);
    float spec                = pow(max(dot(viewDirection, reflectionDirection), 0.0), 32);
    vec3  specular            = specStrength * spec * lightColour;
    
    // stacked result
    vec3 result = (ambient + diffuse + specular) * vec3(frag_colour);
    color = vec4(result, frag_colour.a);
}

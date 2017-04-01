
#version 330 core

in vec4 worldPos;
in vec3 finalColour;
in vec3 norm;

uniform vec4 colour;
uniform vec3 viewPosition;
uniform vec3 lightPosition;
uniform vec3 lightColour;
uniform float renderDistance;

out vec4 color;

float magnitude (vec3 v) { return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)); }

void main (void) {
    vec3 normal = normalize(norm);
    /*
    // ambient lighting
    float ambStrength = 0.35f;
    vec3  ambient     = ambStrength * lightColour;
    
    // diffuse lighting
    vec3  lightDirection = normalize(lightPosition - vec3(worldPos.xyz));
    float diffStrength   = max(dot(normal, lightDirection), 0.8f);
    vec3  diffuse        = diffStrength * lightColour;
    
    // specular lighting
    float specStrength        = 0.45f;
    vec3  viewDirection       = normalize(viewPosition - vec3(worldPos.xyz));
    vec3  reflectionDirection = reflect(-lightDirection, normal);
    float spec                = pow(max(dot(viewDirection, reflectionDirection), 0.4), 32);
    vec3  specular            = specStrength * spec * lightColour;
    
    // stacked result
    vec3 result = (ambient + diffuse + specular) * finalColour;
    */
    
    vec4 col = vec4(finalColour, 0.25);
    if (magnitude(viewPosition - vec3(worldPos.xyz)) > renderDistance) {
        col.a = col.a - (magnitude(viewPosition - vec3(worldPos.xyz)) - renderDistance) * 0.25;
    }
    
    color = col;
}

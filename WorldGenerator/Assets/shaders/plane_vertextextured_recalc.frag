#version 330 core

flat in float f_alpha;
in vec4 worldPos;
in vec3 norm;

uniform vec4 colour;

uniform vec3 viewPosition;
uniform vec3 lightPosition;
uniform vec3 lightColour;
uniform float renderDistance;

out vec4 color;

vec3 defaultNorm = vec3(0, 1, 0);

float magnitude (vec3 v) { return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)); }

float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

void main (void) {
    vec3 normal = normalize(norm);
    
        // ambient lighting
    float ambStrength = 0.40f;
    vec3  ambient     = ambStrength * lightColour;
    
        // diffuse lighting
    vec3  lightDirection = normalize(lightPosition - vec3(worldPos.xyz));
    float diffStrength   = max(dot(norm, lightDirection), 0.0f);
    vec3  diffuse        = diffStrength * lightColour;
    
        // specular lighting
    float specStrength        = 0.2f;
    vec3  viewDirection       = normalize(viewPosition - vec3(worldPos.xyz));
    vec3  reflectionDirection = reflect(-lightDirection, normal);
    float spec                = pow(max(dot(viewDirection, reflectionDirection), 0.1), 64);
    vec3  specular            = specStrength * spec * lightColour;
    
        // stacked result
    vec3 result = (ambient + diffuse + specular) * vec3(colour);
    
    
    vec4 col = vec4(result.rgb, f_alpha);
    
    /*
    if (magnitude(viewPosition - vec3(worldPos.xyz)) > renderDistance) {
        //col.a = col.a - (magnitude(viewPosition - vec3(worldPos.xyz)) - renderDistance) * 0.25;
    }
    */
    
    
    color = vec4(col);
}

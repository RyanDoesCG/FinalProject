#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

// Transforms
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

// Height Data
uniform sampler2D tex;

// Runtime Variables
uniform vec4 colour;
uniform vec3 viewPosition;
uniform float renderDistance;
uniform float seaLevel;
uniform float smoothing;
uniform float amp;

uniform float mode;

flat out float alpha;

float magnitude (vec3 v) { return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)); }
float rand      (vec2 c) { return fract(sin(dot(c.xy ,vec2(12.9898,78.233))) * 43758.5453); }

void main (void) {
    float lift = 0.865;// + (0.5 * abs((texture(tex, uv).r) * amp));
    
    if (mode == 0.0) {
         lift += ((cos(rand(vec2(position.y * 100 * amp, position.z * 24753)))) * (amp * 2.5));
    }
    
    if (mode == 1.0) {
        lift += ((sqrt(rand(vec2(position.y * 100 * amp, position.z * 24753)))) * (amp * 2.5));
    }
    
    if (mode == 2.0) {
        lift += ((acos(rand(vec2(position.y * 100 * amp, position.z * 24753)))) * (amp * 2.5));
    }
    
    if (mode == 3.0) {
         lift += ((tan(rand(vec2(position.y * 100 * amp, position.z * 24753)))) * (amp * 2.5));
    }
    
    vec3 a = vec3(0, 0, 0);
    vec3 b = position;
    
    // get the distance between the center of the structure
    // and the point on the x, y and z axes.
    float distX = b.x - a.x;
    float distY = b.y - a.y;
    float distZ = b.z - a.z;
    
    float a_b = sqrt(distX * distX + distY * distY + distZ * distZ);
    
    distX = distX * lift / a_b;
    distY = distY * lift / a_b;
    distZ = distZ * lift / a_b;
    
    b.x = (a.x + distX);
    b.y = (a.y + distY);
    b.z = (a.z + distZ);
    
    gl_Position = vec4(b, 1.0);
    
    alpha = 1;
    
    /*
    vec4 worldPos = model * vec4(position.x, (position.y + lift), position.z, 1.0f);
    if (magnitude(viewPosition - vec3(worldPos.xyz)) > renderDistance) {
        alpha -= (magnitude(viewPosition - vec3(worldPos.xyz)) - renderDistance) * 0.5;
    }
    */
}

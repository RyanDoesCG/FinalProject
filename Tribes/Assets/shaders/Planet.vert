#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;

out vec3 worldPosition;
out vec3 norm;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

highp float rand(vec2 co);

void main() {
    
    float lift = 0.9 + 0.1 * (sin(rand(vec2(position.y * 1000, position.z * 24753))));
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
    
    // set position
    gl_Position = projection * view * model * vec4(b, 1.0f);
    
    // pass through
    worldPosition = vec3(model * vec4(b, 1.0f));
    norm = mat3(transpose(inverse(model))) * normal;
}

/**
 * CREDIT:
 *  http://byteblacksmith.com/improvements-to-the-canonical-one-liner-glsl-rand-for-opengl-es-2-0/
 */
highp float rand(vec2 co) {
    highp float a = 12.9898;
    highp float b = 78.233;
    highp float c = 43758.5453;
    highp float dt= dot(co.xy ,vec2(a,b));
    highp float sn= mod(dt,3.14);
    return fract(sin(sn) * c);
}

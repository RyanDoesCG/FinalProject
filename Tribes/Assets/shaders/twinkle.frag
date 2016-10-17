#version 330 core

in vec3 FRAG_position;
in vec2 FRAG_textureCoord;
in vec3 FRAG_color;
in float FRAG_time;

out vec4 color;

/** 
 * CREDIT: http://byteblacksmith.com/improvements-to-the-canonical-one-liner-glsl-rand-for-opengl-es-2-0/
 */
highp float rand(vec2 co) {
    highp float a = 12.9898;
    highp float b = 78.233;
    highp float c = 43758.5453;
    highp float dt= dot(co.xy ,vec2(a,b));
    highp float sn= mod(dt,3.14);
    return fract(sin(sn) * c);
}

// solid black
void main (void) {
    float twinkle = rand(vec2(FRAG_position.y, FRAG_position.z));
    
    color = vec4(
        1.0f * twinkle,
        1.0f * twinkle,
        1.0f * twinkle,
        1.0f
    ); //cos(FRAG_position.x / FRAG_position.y);
}

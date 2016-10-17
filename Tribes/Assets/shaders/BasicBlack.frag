#version 330 core

in vec3 FRAG_position;
in vec2 FRAG_textureCoord;
in vec3 FRAG_color;

out vec4 color;

// solid black
void main (void) {
    color = vec4(0.25, 0.25, 0.25, 1.0f) ;//* (FRAG_position.x / 2);
}

/**
 *  Nice Colours:
 *      - r: 0.52 g: 0.64 b: 0.49
 *      - r: 0.64 g: 0.1  b: 0.24
 *      - r: 0.67 g: 0.61 b: 0.71
 *      - r: 0.8 g: 0.69 b: 0.57
 *      r: 0.82 g: 0.54 b: 0.15
 */

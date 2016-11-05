#version 330 core

out vec4 color;

// solid black
void main (void) {
    color = vec4(0.55, 0.55, 0.55, 1.0f);// * vec4(FRAG_position, 1.0f);
}

/**
 *  Nice Colours:
 *      - r: 0.52 g: 0.64 b: 0.49
 *      - r: 0.64 g: 0.1  b: 0.24
 *      - r: 0.67 g: 0.61 b: 0.71
 *      - r: 0.8 g: 0.69 b: 0.57
 *      r: 0.82 g: 0.54 b: 0.15
 */

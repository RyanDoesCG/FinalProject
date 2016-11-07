#version 330 core

/**
 *  Nice Colours:
 *      - r: 0.52 g: 0.64 b: 0.49
 *      - r: 0.64 g: 0.1  b: 0.24
 *      - r: 0.67 g: 0.61 b: 0.71
 *      - r: 0.8 g: 0.69 b: 0.57
 *      r: 0.82 g: 0.54 b: 0.15
 */
uniform vec3 proceduralColour;

in vec3  FRAG_position;
out vec4 color;

void main (void) {
    //if (FRAG_index > 75) color = vec4(0.53, 0.34, 0.2, 1.0f);
    //else color = vec4(0.67, 0.61, 0.71, 1.0f);
    
    // procedural colour from game
    color = vec4(proceduralColour.r, proceduralColour.g, proceduralColour.b, 1.0);

    // hard coded color from me
    //color = vec4(0.29, 0.07, 0.13, 1.0);
}


#version 330 core

in vec4 FRAG_position;
in vec4 FRAG_color;

out vec4 color;

#define col 2

void main (void) {
    
    // Color-splosion
    if (col == 0) {
        color = FRAG_color *
                vec4(FRAG_position.x, FRAG_position.x, FRAG_position.x,  1.0f) +
                vec4(0.45, 0.0, 0.0, 1.0);
    }
    
    // orange
    else if (col == 1) {
        color = vec4(0.8, 0.45, 0, 1.0f) *
                vec4(FRAG_position.x/2, FRAG_position.x/2, FRAG_position.x/2,  1.0f) +
                vec4(0.25, 0.0, 0.0, 1.0);
    }
    
    // orangey green
    else if (col == 2) {
        color = vec4(0.36, 1.0, 0.75, 1.0f) *
                vec4(FRAG_position.x/2, FRAG_position.x/2, FRAG_position.x/2,  1.0f) +
                vec4(0.25, 0.0, 0.0, 1.0);
    }
    
    // Color-splosion II
    else if (col == 3) {
        color = FRAG_color *
                vec4(FRAG_position.x/2, FRAG_position.x/2, FRAG_position.x/2,  1.0f); +
                vec4(0.25, 0.25, 0.25, 1.0);
    }
}

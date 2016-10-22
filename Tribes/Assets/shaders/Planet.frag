#version 330 core

in vec4 FRAG_position;
in vec4 FRAG_color;

out vec4 color;

void main (void) {
    int col = 0;
    
    if (col == 0) {
        // Color-splosion
        color = FRAG_color * vec4(FRAG_position.x/2, FRAG_position.x/2, FRAG_position.x/2,  1.0f) +
        vec4(0.30, 0.0, 0.0, 1.0);
    }
    
    else if (col == 1) {
        // orange
        color = vec4(0.8, 0.45, 0, 1.0f) *
                vec4(FRAG_position.x/2, FRAG_position.x/2, FRAG_position.x/2,  1.0f) +
                vec4(0.25, 0.0, 0.0, 1.0);
    }
    
    else if (col == 2) {
        // orangey green
        color = vec4(0.36, 1.0, 0.75, 1.0f) *
                vec4(FRAG_position.x/2, FRAG_position.x/2, FRAG_position.x/2,  1.0f) +
                vec4(0.25, 0.0, 0.0, 1.0);
    }
    
    else if (col == 3) {
        // Color-splosion
        color = FRAG_color *
                vec4(FRAG_position.x/2, FRAG_position.x/2, FRAG_position.x/2,  1.0f); +
                vec4(0.25, 0.25, 0.25, 1.0);
    }
}

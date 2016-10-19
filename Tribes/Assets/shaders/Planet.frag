#version 330 core

in vec4 FRAG_position;

out vec4 color;

void main (void) {
    color = vec4(0.36, 1.0, 0.75, 1.0f) *
            vec4(FRAG_position.x/2, FRAG_position.x/2, FRAG_position.x/2,  1.0f) +
            vec4(0.25, 0.0, 0.0, 1.0);
}

// orange
//    color = vec4(0.8, 0.45, 0, 1.0f) *
//            vec4(FRAG_position.x/2, FRAG_position.x/2, FRAG_position.x/2,  1.0f) +
//            vec4(0.25, 0.0, 0.0, 1.0);

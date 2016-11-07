#version 330 core

in vec4  FRAG_position;
in float FRAG_colorID;

in float FRAG_mouseX;
in float FRAG_mouseY;

out vec4 color;

#define col 2

void main (void) {

    
    // ornge
    if (col == 1) {
        if (FRAG_position.x < FRAG_mouseX && FRAG_position.x < FRAG_mouseY) {
            color = vec4(0.54, 0.0, 0.54, 1);
        }
        
        else {
            color = vec4 (0.8, 0.45, 0, 1.0f) *
                    vec4 (FRAG_position.x, FRAG_position.x, FRAG_position.x,  1.0f) +
                    vec4 (0.25, 0.0, 0.0, 1.0);
        }
    }
    
    // orangey green
    else if (col == 2) {
        color = vec4 (0.36, 1.0, 0.75, 1.0f) *
                vec4 (FRAG_position.x/2, FRAG_position.x/2, FRAG_position.x/2,  1.0f) +
                vec4 (0.25, 0.0, 0.0, 1.0);
    }
    

/*
    vec4 snow     = vec4(0.92, 0.92, 0.92, 1);    // white
    vec4 desert   = vec4(1.0,  0.89, 0.49, 1);    // yellow
    vec4 volcanic = vec4(0.24, 0.24, 0.24, 1);    // red
    vec4 forrest  = vec4(0.54, 0.76, 0.28, 1);    // green
    vec4 error    = vec4(0.54, 0.0, 0.54, 1);
    
    //color = vec4(1.0f, 0.0f, 0.0f, 1.0f);
    
    if      (FRAG_colorID <= 1.0f) color = volcanic;
    else if (FRAG_colorID <= 2.0f) color = desert;
    else if (FRAG_colorID <= 3.0f) color = snow;
    else if (FRAG_colorID >= 4.0f) color = forrest;
    else color = error;
    
    if (FRAG_position.x > FRAG_mouseX && FRAG_position.y > FRAG_mouseY) {
        color = error;
    }
*/
}

// https://material.google.com/style/color.html#color-color-palette
// snow:        #EEEEEE    /    rgba(238, 238, 238, 1)  /   rgba(0.92, 0.92, 0.92, 1)
// desert:      #FFE57F    /    rgba(255, 229, 127, 1)  /   rgba(1.0,  0.89, 0.49, 1)
// volcanic:    #FF3D00    /    rgba(255, 61, 0, 1)     /   rgba(1.0,  0.23, 0.0,  1)
// forrest:     #8BC34A    /    rgba(139, 195, 74, 1)   /   rgba(0.54, 0.76, 0.28, 1)
// error:       #D500F9    /

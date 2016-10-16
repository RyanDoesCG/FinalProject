#version 330 core

in vec3 FRAG_position;
in vec2 FRAG_textureCoord;
in vec3 FRAG_color;

out vec4 color;

uniform sampler2D tex;

void main (void) {
    // Varying blue value
    color = vec4(FRAG_color, 1.0f) + texture(tex, FRAG_textureCoord);  // use texture

    //color = vec4(0.67, 0.61, 0.71, 1.0) + vec4(pos.y/3, pos.y/3, pos.y/3, 1.0f);
    
    // unified device coordinates
    //color = vec4(FRAG_color, 1.0f) //texture2D(diffuse, textureCoordinate_vary)
    //* clamp(dot(-vec3(0, 0, 1), normal_vary), 0.0, 1.0);
    
    // lambertian lighting
    // negative for reflection simulation
    // clamped to prevent ridiculous lighting
    // vec3 represents light direction
}

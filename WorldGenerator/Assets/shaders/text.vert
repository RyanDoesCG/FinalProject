#version 330 core

//layout (location = 0) in vec2 pos;
//layout (location = 1) in vec2 uvs;

layout (location = 0) in vec4 pos; // <pos x, posy, u, v>

out vec2 frag_uvs;

uniform mat4 projection;

void main (void) {
    gl_Position = projection * vec4(pos.xy, 0.0, 1.0);
    frag_uvs = pos.zw;
    
  //  gl_Position = projection * vec4(pos.xy, 0.0, 1.0);
  //  frag_uvs = uvs;
}

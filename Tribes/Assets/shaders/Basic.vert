#version 120
//#extension GL_ARB_explicit_attrib_location : require
/** 
 *  Why i can't draw a triangle:
 *
 *      intel doesn't support the passing of attributes
 *      over "layout (location = 0)" sooooo
 */
//layout (location = 0) in vec3 position;   // seems unsupported

attribute vec3 position;

void main () {
    gl_Position = vec4 (
        position.x,
        position.y,
        position.z,
        1.0
    );
}
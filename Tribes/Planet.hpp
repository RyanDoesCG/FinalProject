/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Planet.hpp
 *  Tribes
 *
 *  Created by ryan needham on 01/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 *   - build octahedron (https://en.wikipedia.org/wiki/Octahedron )
 *
 *   - recursively break up each triangle into a collection 
 *     of smaller triangles (to a set level of detail)
 *
 *   - normalize each point vector [vec(centre, point)] so
 *     they are all a constant distance from the center
 *
 *   http://stackoverflow.com/questions/7687148/drawing-sphere-in-opengl-without-using-glusphere
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Planet_hpp
#define Planet_hpp

//      /\
//     /  \
//     \  /
//      \/

// MAKE COMPONENT BASED

#include "Shader.hpp"
#include "Mesh.hpp"

#include <iostream>
#include <Vector>

class Planet {
    public:
        Planet  ();
        ~Planet ();
    
        void generatePlanet ();
        void render ();
        
    private:
        Mesh*  planetMesh;
        Shader* landShader;
        Shader* waterShader;
    
};
#endif /* Planet_hpp */

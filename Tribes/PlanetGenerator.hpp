/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PlanetGenerator.hpp
 *  Tribes
 *
 *  Created by ryan needham on 01/09/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef PlanetGenerator_hpp
#define PlanetGenerator_hpp

#include "Mesh.hpp"

#include <iostream>
#include <Vector>

class PlanetGenerator {
    public:
        PlanetGenerator  ();
        ~PlanetGenerator ();

    private:
        std::vector<glm::vec3> points;
};

#endif /* PlanetGenerator_hpp */

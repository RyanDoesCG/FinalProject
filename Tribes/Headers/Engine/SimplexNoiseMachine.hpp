/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  SimplexNoiseMachine.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 02/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef SimplexNoiseMachine_hpp
#define SimplexNoiseMachine_hpp

#include "Vertex.hpp"
#include <vector>

class SimplexNoiseMachine {
    public:
        static void initialise ();
    
        static double noise (double xin, double yin);
        static double noise (double xin, double yin, double zin);
        static double noise (double xin, double yin, double zin, double win);
    
    private:
        static std::vector<glm::vec3> grad3;
        static std::vector<glm::vec4> grad4;
        static std::vector<short>     p;
        static short                  perm[512];
        static short                  permMod12[512];
    
        // Skewing and unskewing factors for 2, 3, and 4 dimensions
        static const double F2;
        static const double G2;
        static const double F3;
        static const double G3;
        static const double F4;
        static const double G4;
    
        static int fastFloor (double x);

        static double dot (glm::vec2 g, double x, double y);
        static double dot (glm::vec3 g, double x, double y, double z);
        static double dot (glm::vec4 g, double x, double y, double z, double w);
};

#endif /* SimplexNoiseMachine_hpp */

//
//  GraphicsEngine.hpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef GraphicsEngine_hpp
#define GraphicsEngine_hpp
#include "GraphicsObject.hpp"
#include <vector>

class GraphicsEngine {
    public:
        GraphicsEngine ();
       ~GraphicsEngine ();
    
        void render();
    
    private:
        std::vector<GraphicsObject*> scene;
};

#endif /* GraphicsEngine_hpp */

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
#include "Camera.hpp"
#include <vector>

class GraphicsEngine {
    public:
        GraphicsEngine (float width, float height);
       ~GraphicsEngine ();
    
        void render();
    
        void add (GraphicsObject* object);
    
    private:
        std::vector<GraphicsObject*> scene;
    
        Camera* camera;
};

#endif /* GraphicsEngine_hpp */

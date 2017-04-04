//
//  RockSpawner.hpp
//  WorldGenerator
//
//  Created by user on 18/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef RockSpawner_hpp
#define RockSpawner_hpp

#include "ObjectSpawner.hpp"

class RockSpawner: public ObjectSpawner {
    public:
        RockSpawner (
            GraphicsEngine* graph,
            std::string     path,
            HeightMap*      map,
            glm::vec4       col,
            glm::vec3       scl,
            int             count
        );
    
       ~RockSpawner ();
    
    private:
    
        GraphicsEngine* engine;
};

#endif /* RockSpawner_hpp */

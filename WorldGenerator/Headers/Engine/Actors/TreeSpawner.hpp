//
//  TreeSpawner.hpp
//  WorldGenerator
//
//  Created by user on 18/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef TreeSpawner_hpp
#define TreeSpawner_hpp

#include "ObjectSpawner.hpp"

class TreeSpawner: public ObjectSpawner {
    public:
        TreeSpawner (
            GraphicsEngine* graph,
            std::string     path,
            HeightMap*      map,
            glm::vec4       col,
            glm::vec3       scl,
            int count
        );
    
       ~TreeSpawner ();
};

#endif /* TreeSpawner_hpp */

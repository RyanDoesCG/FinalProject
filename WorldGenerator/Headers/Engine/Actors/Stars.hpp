//
//  Stars.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 01/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Stars_hpp
#define Stars_hpp

#include "Actor.hpp"
#include "Cube.hpp"

class Stars : public Actor {
    public:
        Stars();
       ~Stars();
    
        virtual void draw   (SceneCamera* camera) override;
        virtual void update (GameState state) override;
    
        void addLightSource (Actor* light) {
            star.setLightSource(light);
        }
    
    private:
        Cube star;
        std::vector<glm::vec3> starFlyweightTransforms;
        int starCount;

        Actor* lightSource;
};

#endif /* Stars_hpp */

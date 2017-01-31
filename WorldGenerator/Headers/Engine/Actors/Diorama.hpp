/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Diorama.hpp
 *  WorldGenerator
 *
 *  Created by Ryan Needham on 31/01/2017.
 *  Copyright © 2017 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Diorama_hpp
#define Diorama_hpp

#include "GridPlane.hpp"
#include "Model.hpp"
#include "Actor.hpp"

class Diorama : public Actor {
    public:
        Diorama();
        ~Diorama();
    
        virtual void draw(SceneCamera* camera) override;
        virtual void update(GameState state) override;
    
        void setLightSource (Actor* light) {
            surface.setLightSource(light);
            base.setLightSource(light);
            tree.setLightSource(light);
        }
    
    private:
        GridPlane surface;
        Model     base;
    
        // trees
        Model     tree;
        std::vector<glm::vec3> treeFlyweightTransforms;
    
        // model
        Model     rock;
        std::vector<glm::vec3> rockFlyweightTransforms;
};

#endif /* Diorama_hpp */

//
//  GridPlane.hpp
//  WorldGenerator
//
//  Created by user on 31/01/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef GridPlane_hpp
#define GridPlane_hpp

#include "Actor.hpp"
#include "MeshComponent.hpp"
#include "ShaderComponent.hpp"

class GridPlane : public Actor {
    public:
        GridPlane(float width, float height);
    
        GridPlane();
        ~GridPlane();
    
        virtual void draw (SceneCamera* camera) override;
        virtual void update (GameState state) override;
    
        void setLightSource (Actor* light) {lightSource = light;}
    
    private:
        MeshComponent* mesh;
        ShaderComponent* shader;
    
        Actor* lightSource;
};

#endif /* GridPlane_hpp */

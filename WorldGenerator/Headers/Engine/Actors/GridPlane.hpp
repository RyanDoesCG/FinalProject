//
//  GridPlane.hpp
//  WorldGenerator
//
//  Created by user on 31/01/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef GridPlane_hpp
#define GridPlane_hpp


/* * * * *
 *  NEEDS TEXTURE COORDINATES FOR VERTEX HEIGHT AND DIP MAPS
 */

#include "../../FastNoise/FastNoise.h"
#include "Actor.hpp"
#include "MeshComponent.hpp"
#include "ShaderComponent.hpp"

class GridPlane : public Actor {
    public:
        GridPlane(float w, float h);
    
        GridPlane();
        ~GridPlane();
    
        void distort(FastNoise* noiseMachine);
    
        virtual void draw (SceneCamera* camera) override;
        virtual void update (GameState state) override;
    
        void updateShader() {shader->update();}
    
        void setLightSource (Actor* light) {lightSource = light;}
    
    private:
        float width;
        float height;
        float startX;
        float endZ;
    
        MeshComponent* mesh;
        ShaderComponent* shader;
    
        Actor* lightSource;
};

#endif /* GridPlane_hpp */

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

#include "../../FastNoise/FastNoise.h"
#include "GridPlane.hpp"
#include "Model.hpp"
#include "Actor.hpp"

#include "Biome.hpp"

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
            rock.setLightSource(light);
        }
    
    private:
    
        // main diorama
        Biome     biome;
        GridPlane surface;
        Model     base;
    
        GLuint heightMapTextureID;   // hills & mountains
        GLuint dipMapTextureID;      // rivers & lakes
    
        void generateHeightMap();
        void generateDipMap();
    
        // trees
        Model     tree;
        std::vector<glm::vec3> treeFlyweightTransforms;
    
        // model
        Model     rock;
        std::vector<glm::vec3> rockFlyweightTransforms;

        // Noise Library
        FastNoise noiseMachine;
};

#endif /* Diorama_hpp */

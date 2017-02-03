//
//  ProceduralShowcase.hpp
//  WorldGenerator
//
//  Created by user on 03/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef ProceduralShowcase_hpp
#define ProceduralShowcase_hpp

#include "Actor.hpp"

class ProceduralShowcase : public Actor {
    private:
        Model model;
        std::vector<glm::vec3> flyweightTransforms;
    
        int width = 5;
        int height = 5;

    public:
        ProceduralShowcase(std::string path) {
            model = Model(path);
            model.setShader("proceduralGen", BASIC);
            model.setColour(glm::vec3(0.50, 0.50, 0.50));
            model.setScale(0.42);
            
            for (int x = 0; x < width; x += 1) {
                for (int y = 0; y < height; y += 1) {
                    flyweightTransforms.push_back(glm::vec3(x, y, 0));
                }
            }
        }
    
        ~ProceduralShowcase() {}
    
        void setLightSource(Actor* light) { model.setLightSource(light); }
    
        void draw(SceneCamera* camera) override {
            for (int i = 0; i < flyweightTransforms.size(); i++) {
                model.setPosition(flyweightTransforms.at(i));
                model.update(RUNNING_FREEMODE);
                model.draw(camera);
            }
        }
    
        void update(GameState state) override {
        
        }
    
    
};

#endif /* ProceduralShowcase_hpp */

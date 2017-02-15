//
//  Pyramid.hpp
//  WorldGenerator
//
//  Created by user on 15/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Pyramid_hpp
#define Pyramid_hpp

#include "../Components/ShaderComponent.hpp"
#include "../Components/MeshComponent.hpp"
#include "Actor.hpp"
#include <iostream>

class Pyramid : public Actor {
public:
    Pyramid();
    ~Pyramid();
    
    virtual void draw (SceneCamera* camera) override;
    virtual void update (GameState state) override;
    
    void setShader      (std::string path, ProgramType type);
    void setLightSource (Actor* light) {lightSource = light;}
    
    void resize (float size) {
        vec3 conversion = vec3(size, size, size);
        Actor::scale = conversion;
    }
    
protected:
    MeshComponent* mesh;
    ShaderComponent* shader;
    
    Actor* lightSource = nullptr;
};

#endif /* Pyramid_hpp */

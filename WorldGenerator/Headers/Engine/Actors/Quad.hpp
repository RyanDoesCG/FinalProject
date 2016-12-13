/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Quad.hpp
 *  Tribes
 *
 *  Created by ryan needham on 30/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Quad_hpp
#define Quad_hpp

#include "Actor.hpp"
#include "../Components/MeshComponent.hpp"
#include "../Components/ShaderComponent.hpp"

class Quad : public Actor {
    public:
        Quad();
       ~Quad();
    
       virtual void update (GameState state, SceneCamera* camera) override;
    
        ShaderComponent* getShader() {return shader;}
    
        void setShader (std::string name);
        void setTexture (GLuint tex);
    
    protected:
        MeshComponent* mesh;
        ShaderComponent* shader;
    
    
        GLuint texture;
};

#endif /* Quad.hpp */

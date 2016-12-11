#ifndef Quad_hpp
#define Quad_hpp

#include "Actor.hpp"
#include "MeshComponent.hpp"
#include "ShaderComponent.hpp"

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

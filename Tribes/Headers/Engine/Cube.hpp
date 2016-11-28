/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Cube.hpp
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Cube_hpp
#define Cube_hpp

#include "ShaderComponent.hpp"
#include "MeshComponent.hpp"
#include "Actor.hpp"

class Cube : public Actor {
    public:
        Cube();
       ~Cube();
    
        virtual void update(GameState state, SceneCamera* camera) override;
    
        void setLightSource (Actor* light) {lightSource = light;}
    
    protected:
        MeshComponent* mesh;
        ShaderComponent* shader;
    
        Actor* lightSource;
};

#endif

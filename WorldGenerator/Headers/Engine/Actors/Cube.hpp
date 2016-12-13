/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Cube.hpp
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Cube_hpp
#define Cube_hpp

#include "../Components/ShaderComponent.hpp"
#include "../Components/MeshComponent.hpp"
#include "Actor.hpp"

class Cube : public Actor {
    public:
        Cube();
       ~Cube();
    
        virtual void update(GameState state, SceneCamera* camera) override;
    
        void setLightSource (Actor* light) {lightSource = light;}
    
        void resize (float size) {
            vec3 conversion = vec3(size, size, size);
            Actor::scale = conversion;
        }
    
    protected:
        MeshComponent* mesh;
        ShaderComponent* shader;
    
        Actor* lightSource;
};

#endif

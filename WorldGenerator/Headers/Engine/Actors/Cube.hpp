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
#include <iostream>

class Cube : public Actor {
    public:
        Cube();
       ~Cube();
    
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

#endif

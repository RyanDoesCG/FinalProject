/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *  SceneCamera
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef SceneCamera_hpp
#define SceneCamera_hpp

#include "../../glew/glew.h"
#include "../../glm/glm.hpp"
#include "../../glm/gtc/matrix_transform.hpp"

#include "Actor.hpp"

using namespace glm;

class SceneCamera: public Actor {
    public:
        SceneCamera(GLfloat width, GLfloat height);
       ~SceneCamera();

        void moveLeft () override;
        void moveRight () override;
    
        void moveForward   () override;
        void moveForwardAt (float speed);
    
        void moveBackward   () override;
        void moveBackwardAt (float speed);
    
        bool orbiting;
    
        virtual void draw (SceneCamera* camera) override;
        virtual void update (GameState state) override;
    
        void reset ();
    
        mat4 getProjectionTransform ();
        mat4 getViewTransform       ();
    
        GLfloat movementSpeed;
        GLfloat sensitivity;
    
        GLfloat pitch;
        GLfloat roll;
        GLfloat yaw;
    
    private:
        vec3 relativeFront; // Where we are looking
        vec3 relativeRight; // right from the camera
        vec3 relativeUp;    // up from the camrea
        vec3 worldUp;       // up in world space

        mat4 projection;    // Projection Matrix for Shaders
        mat4 view;          // View Matrix for Shaders

};

#endif

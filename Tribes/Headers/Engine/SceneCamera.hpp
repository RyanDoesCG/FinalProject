/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef SCENECAMERA_HPP
#define SCENECAMERA_HPP
#include "../GL/glew.h"
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"

#include "Actor.hpp"

using namespace glm;

class SceneCamera: public Actor {
    public:
        SceneCamera(GLfloat width, GLfloat height);
       ~SceneCamera();

        void moveLeft     ();
        void moveRight    ();
        void moveForward  ();
        void moveBackward ();
    
        void speedUp  ();
        void slowDown ();
        void idle     (double animationTimer);
    
        virtual void update (GameState state) override;
    
        mat4 getProjectionTransform ();
        mat4 getViewTransform       ();
        vec3 getPosition            ();
    
        GLfloat movementSpeed;
        GLfloat sensitivity;
        GLfloat pitch;
        GLfloat yaw;
    
    private:
    
        vec3 position;      // in world space
        vec3 target;        // Where we want to look
        vec3 relativeFront; // Where we are looking
        vec3 relativeRight; // right from the camera
        vec3 relativeUp;    // up from the camrea
        vec3 worldUp;       // up in world space

        mat4 projection;    // Projection Matrix for Shaders
        mat4 view;          // View Matrix for Shaders
};

#endif

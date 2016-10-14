/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  GraphicsComponent.hpp
 *  Tribes
 *
 *  Created by ryan needham on 05/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef GraphicsComponent_hpp
#define GraphicsComponent_hpp

#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "Mesh.hpp"

#include <iostream>

class GraphicsComponent {
    public:
        GraphicsComponent() {
            modelMatrix      = glm::rotate(modelMatrix, (GLfloat)0.08, glm::vec3(1.0f, 0.0f, 0.0f));
        }
    
        ~GraphicsComponent () {}
        
        void draw() {
            objectShaders.at(0)->bind ();
            
            // calculate transformations
            modelMatrix      = glm::rotate(modelMatrix, (GLfloat)0.02, glm::vec3(0.0f, 1.0f, 0.0f));

            viewMatrix       = glm::translate(viewMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
            projectionMatrix = glm::mat4();//glm::perspective(45.0f, (GLfloat)720 / (GLfloat)390, 0.1f, 100.0f);
            
            // Pass them to the shaders
            glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
            glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMatrix));
            glUniformMatrix4fv(glGetUniformLocation(objectShaders.at(0)->getProgramID(), "projectionMat"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));   // Note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
            
            objectTexture->bind       ();
            objectMesh->draw          ();
        }

    protected:
        std::vector<Shader*> objectShaders;
        Texture*             objectTexture;
        Mesh*                objectMesh;
    
        // Transformations
        glm::mat4 modelMatrix;
        glm::mat4 viewMatrix;
        glm::mat4 projectionMatrix;
    
};

#endif /* GraphicsComponent_hpp */

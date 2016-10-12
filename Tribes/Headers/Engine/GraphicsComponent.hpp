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
        GraphicsComponent  () {}
        ~GraphicsComponent () {}
    
        void addShader(Shader* s) {
            objectShaders.push_back(s);
        }
        
        void draw() {
            objectShaders.at(0)->bind ();
            objectTransform = glm::translate(objectTransform, glm::vec3(0.0f, 0.0f, 0.0f));
            objectTransform = glm::rotate(objectTransform, (GLfloat)cos((GLfloat)glfwGetTime()), glm::vec3(0.0f, 0.0f, 1.0f));
            
            // transform uniform to GPU
            glUniformMatrix4fv (
                glGetUniformLocation(objectShaders.at(0)->getProgramID(),
                "transform"),
                1,
                GL_FALSE,
                glm::value_ptr(objectTransform)
            );
            
            objectTexture->bind       ();
            objectMesh->draw          ();
        }

    protected:
        std::vector<Shader*> objectShaders;
        glm::mat4            objectTransform;
        Texture*             objectTexture;
        Mesh*                objectMesh;
    
};

#endif /* GraphicsComponent_hpp */

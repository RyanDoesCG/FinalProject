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

#include "../GLM/gtc/matrix_transform.hpp"
#include "../GLM/gtc/type_ptr.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "Mesh.hpp"
#include "MathsToolkit.hpp"

#include <iostream>

class GraphicsComponent {
    public:
        GraphicsComponent() {
           
        }
    
        ~GraphicsComponent () {}
        
        virtual void draw() {
            std::cout << "draw not impemented" << std::endl;
        }
    
        virtual void rotateLeft () {
            modelMatrix = glm::rotate(modelMatrix, (GLfloat)-0.05, glm::vec3(0.0f, 1.0f, 0.0f));
        }
    
        virtual void rotateRight () {
            modelMatrix = glm::rotate(modelMatrix, (GLfloat)0.04, glm::vec3(0.0f, 1.0f, 0.0f));
        }
    
        virtual void grow () {
            modelMatrix = glm::scale(modelMatrix, glm::vec3(1.01, 1.01, 1.01));
        }
    
        virtual void shrink () {
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.99, 0.99, 0.99));
        }
    
    protected:
        // mesh
        std::vector<GLfloat>  vertices;
    
        // OpenGL stuff
        std::vector<Shader*>  objectShaders;
        std::vector<Texture*> objectTexture;
        Mesh*                 objectMesh;
    
        // Transformations
        glm::mat4 modelMatrix;
        glm::mat4 viewMatrix;
        glm::mat4 projectionMatrix;
    
};

#endif /* GraphicsComponent_hpp */

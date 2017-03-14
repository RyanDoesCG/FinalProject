//
//  GraphicsObject.hpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#ifndef GraphicsObject_hpp
#define GraphicsObject_hpp

#include "matrix_transform.hpp"
#include "type_ptr.hpp"
#include "Geometry.hpp"
#include "Material.hpp"
#include "Camera.hpp"
#include "glm.hpp"

class GraphicsObject {
    public:
        GraphicsObject (Geometry* geom, Material* mat): geometry(geom), material(mat) {}
       ~GraphicsObject () {}
    
        void draw (Camera* cam) {
            material->bind();
            
            // Lighting data to GPU
            glm::vec3 viewPos = cam->position;
            glUniform3fv(glGetUniformLocation(material->getProgramID(), "viewPosition"), 1, glm::value_ptr(viewPos));
            if (isLit) {
                glm::vec3 lightPosition = lightsource->position;
                glm::vec4 lightColour   = lightsource->colour;
                
                glUniform3fv(glGetUniformLocation(material->getProgramID(), "lightPosition"), 1, glm::value_ptr(lightPosition));
                glUniform4fv(glGetUniformLocation(material->getProgramID(), "lightColour"), 1, glm::value_ptr(lightColour));
            }
            
            // upload colour to shader
            glUniform4fv(glGetUniformLocation(material->getProgramID(), "colour"), 1, glm::value_ptr(colour));
            
            // Give camera transforms to shader
            glm::mat4 view = cam->getViewMatrix();
            glm::mat4 projection = cam->getProjectionMatrix();
            glUniformMatrix4fv(glGetUniformLocation(material->getProgramID(), "view"), 1, GL_FALSE,       glm::value_ptr(view));
            glUniformMatrix4fv(glGetUniformLocation(material->getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
            
            // Give model transform to shader
            model = glm::translate(glm::mat4(), position);
            model = glm::rotate (model, rotation.x, glm::vec3(1.0, 0.0, 0.0));
            model = glm::rotate (model, rotation.y, glm::vec3(0.0, 1.0, 0.0));
            model = glm::rotate (model, rotation.z, glm::vec3(0.0, 0.0, 1.0));
            model = glm::scale  (model, scale);
            glUniformMatrix4fv(glGetUniformLocation(material->getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
            
            geometry->render();
            
            // EXTERNAL WIREFRAME
            if (geometry->wireframe) {
                // upload colour to shader
                glm::vec4 col = glm::vec4(1.0, 1.0, 1.0, 1.0);
                glUniform4fv(glGetUniformLocation(material->getProgramID(), "colour"), 1, glm::value_ptr(col));
                
                // Give model transform to shader
                model = glm::translate(glm::mat4(), position);
                model = glm::rotate (model, rotation.x, glm::vec3(1.0, 0.0, 0.0));
                model = glm::rotate (model, rotation.y, glm::vec3(0.0, 1.0, 0.0));
                model = glm::rotate (model, rotation.z, glm::vec3(0.0, 0.0, 1.0));
                model = glm::scale  (model, scale + glm::vec3(0.01));
                glUniformMatrix4fv(glGetUniformLocation(material->getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
                
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                    geometry->render();
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            }
        }
    
        void wireframe (bool b) { geometry->wireframe = b; }
    
        Geometry* geometry;
        Material* material;
    
        glm::vec3 position = glm::vec3(0.00, 0.00, 0.00);
        glm::vec3 rotation = glm::vec3(0.00, 0.00, 0.00);
        glm::vec4 colour   = glm::vec4(0.21, 0.21, 0.21, 1.0);
        glm::vec3 scale    = glm::vec3(1.00, 1.00, 1.00);
    
        glm::mat4 model;
    
        void setLightSource(GraphicsObject* light) { lightsource = light; isLit = true; }
    
    private:
        GraphicsObject* lightsource;
        bool isLit = false;
    
};

#endif /* GraphicsObject_hpp */

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
        GraphicsObject (Geometry geom, Material mat): geometry(geom), material(mat) {}
       ~GraphicsObject () {}
    
        void draw (Camera* cam) {
            material.bind();
            
            // upload colour to shader
            glUniform4fv(glGetUniformLocation(material.getProgramID(), "colour"), 1, glm::value_ptr(colour));
            
            // Give camera transforms to shader
            glm::mat4 view = cam->getViewMatrix();
            glm::mat4 projection = cam->getProjectionMatrix();
            glUniformMatrix4fv(glGetUniformLocation(material.getProgramID(), "view"), 1, GL_FALSE,       glm::value_ptr(view));
            glUniformMatrix4fv(glGetUniformLocation(material.getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
            
            // Give model transform to shader
            model = glm::translate(glm::mat4(), position);
            model = glm::rotate (model, rotation.x, glm::vec3(1.0, 0.0, 0.0));
            model = glm::rotate (model, rotation.y, glm::vec3(0.0, 1.0, 0.0));
            model = glm::rotate (model, rotation.z, glm::vec3(0.0, 0.0, 1.0));
            model = glm::scale  (model, scale);
            glUniformMatrix4fv(glGetUniformLocation(material.getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
            
            geometry.render();
        }
    
        void wireframe (bool b) {geometry.wireframe = b;}
    
        Geometry geometry;
        Material material;
    
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec4 colour;
        glm::vec3 scale;
    
        glm::mat4 model;
    
};

#endif /* GraphicsObject_hpp */

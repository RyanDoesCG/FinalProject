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
#include <vector>
#include <utility>

typedef std::pair<std::string, GLfloat> uniform1f;

class GraphicsObject {
    public:
        GraphicsObject (Geometry* geom, Material* mat): geometry(geom), material(mat) {}
       ~GraphicsObject () { delete geometry; delete material; }
    
        void setID (int x) { id = x; }
        const int getID () const { return id; }
    
        bool isCursor = false;
    
        void addUniform1f (std::string title, GLfloat value) { uniforms.push_back(uniform1f(title, value)); }
        
        virtual void draw (Camera* cam) {
            if (drawable) {
                material->bind();
                
                // custom uniforms to gpu
                for (uniform1f u : uniforms) glUniform1f(glGetUniformLocation(material->getProgramID(), u.first.c_str()), u.second);
                uniforms.clear();
                
                // Lighting data to GPU
                glm::vec3 viewPos = cam->position;
                glUniform3fv(glGetUniformLocation(material->getProgramID(), "viewPosition"), 1, glm::value_ptr(viewPos));
                if (isLit) {
                    glm::vec3 lightPosition = lightsource->position;
                    glm::vec3 lightColour   = glm::vec3(lightsource->colour.r, lightsource->colour.g, lightsource->colour.b);
                    
                    glUniform3fv(glGetUniformLocation(material->getProgramID(), "lightPosition"), 1, glm::value_ptr(lightPosition));
                    glUniform3fv(glGetUniformLocation(material->getProgramID(), "lightColour"), 1, glm::value_ptr(lightColour));
                } else {
                    glm::vec3 lightPosition = glm::vec3(0.0, 0.0, 0.0);
                    glm::vec3 lightColour   = glm::vec3(1.0, 1.0, 1.0);
                    
                    glUniform3fv(glGetUniformLocation(material->getProgramID(), "lightPosition"), 1, glm::value_ptr(lightPosition));
                    glUniform3fv(glGetUniformLocation(material->getProgramID(), "lightColour"), 1, glm::value_ptr(lightColour));
                }
                
                // upload colour to shader
                glUniform4fv(glGetUniformLocation(material->getProgramID(), "colour"), 1, glm::value_ptr(colour));
                
                // Give camera transforms to shader
                glm::mat4 view = cam->getViewMatrix();
                glm::mat4 projection = cam->getProjectionMatrix();
                glUniformMatrix4fv(glGetUniformLocation(material->getProgramID(), "view"), 1, GL_FALSE,       glm::value_ptr(view));
                glUniformMatrix4fv(glGetUniformLocation(material->getProgramID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
                
                // Give model transform to shader
                model = glm::translate(model, position);
                model = glm::rotate (model, rotation.x, glm::vec3(1.0, 0.0, 0.0));
                model = glm::rotate (model, rotation.y, glm::vec3(0.0, 1.0, 0.0));
                model = glm::rotate (model, rotation.z, glm::vec3(0.0, 0.0, 1.0));
                model = glm::scale  (model, scale);
                glUniformMatrix4fv(glGetUniformLocation(material->getProgramID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
                
                if (nocull) glDisable(GL_CULL_FACE);
                
                // EXTERNAL WIREFRAME
                if (geometry->wireframe) {
                    // upload colour to shader
                    //glm::vec4 col = glm::vec4(0, 0, 0, 1.0);
                    //glUniform4fv(glGetUniformLocation(material->getProgramID(), "colour"), 1, glm::value_ptr(col));
                    
                    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                    geometry->render();
                    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                } else if (geometry->pointcloud) {
                    glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
                    glPointSize(10);
                    geometry->render();
                    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                } else {
                    geometry->render();
                }

                model = glm::mat4();   
            }
        }
    
        void wireframe  (bool b) { geometry->wireframe = b; }
        void pointcloud (bool b) { geometry->pointcloud = b; }
        virtual void shouldDraw (bool b) { drawable = b; }
        virtual void shouldntCull (bool b) { nocull = b; }
    
    
        Geometry* geometry;
        Material* material;
    
        glm::vec3 position = glm::vec3(0.00, 0.00, 0.00);
        glm::vec3 rotation = glm::vec3(0.00, 0.00, 0.00);
        glm::vec4 colour   = glm::vec4(0.21, 0.21, 0.21, 1.0);
        glm::vec3 scale    = glm::vec3(1.00, 1.00, 1.00);
    
        glm::mat4 model;
    
        void setLightSource(GraphicsObject* light) { lightsource = light; isLit = true; }
    
    protected:
        GraphicsObject* lightsource;
        bool isLit = false;
    
    private:
        std::vector<uniform1f> uniforms;
        bool drawable = false;
        bool nocull   = false;
        int id;
};

#endif /* GraphicsObject_hpp */

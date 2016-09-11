/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Transform.hpp
 *  ShaderToy
 *
 *  Created by ryan needham on 17/08/2016.
 *  Copyright © 2016 Personal Project. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Transform_hpp
#define Transform_hpp

#include "GLM/gtx/transform.hpp"
#include "GLM/glm.hpp"

class Transform {
    public:
        Transform (const glm::vec3& pos   = glm::vec3(0.0f, 0.0f, 0.0f),
                   const glm::vec3& rot   = glm::vec3(0.0f, 0.0f, 0.0f),
                   const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f)) {
            this->pos   = pos;
            this->rot   = rot;
            this->scale = scale;
        }
    
        ~Transform () {
        
        }
    
        inline glm::mat4 getModel () const {
            glm::mat4 posMatrix   = glm::translate (this->pos);
            glm::mat4 rotXMatrix  = glm::rotate    (this->rot.x, glm::vec3(1, 0, 0));
            glm::mat4 rotYMatrix  = glm::rotate    (this->rot.y, glm::vec3(0, 1, 0));
            glm::mat4 rotZMatrix  = glm::rotate    (this->rot.z, glm::vec3(0, 0, 1));
            glm::mat4 scaleMatrix = glm::scale     (this->scale);
            
            // matrices can be combined by multiplying them
            glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;
            return posMatrix * rotMatrix * scaleMatrix;
        }
    
        // getters
        inline glm::vec3& getPosition (void) { return pos; }
        inline glm::vec3& getRotation (void) { return rot; }
        inline glm::vec3& getScale    (void) { return scale; }

        // setters
        inline void setPosition (const glm::vec3& pos) { this->pos = pos; }
        inline void setRotation (const glm::vec3& rot) { this->rot = rot; }
        inline void setScale    (const glm::vec3& scale) { this->scale = scale; }

    private:
        glm::vec3 pos;
        glm::vec3 rot;
        glm::vec3 scale;
};

#endif /* Transform_hpp */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Vertex.hpp
 *  ShaderToy
 *
 *
 *  Created by ryan needham on 08/08/2016.
 *  Copyright © 2016 Personal Project. All rights reserved.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Vertex_hpp
#define Vertex_hpp

#include "glm/vec2.hpp"
#include "glm/vec3.hpp"

class Vertex {
    public:
        Vertex (
            const glm::vec3& positionCoordinates,
            const glm::vec2& textureCoordinates,
            const glm::vec3& normal = glm::vec3(0.5, 0.5, 0.5)
        );
    
        ~Vertex ();
    
        void pushValue(int x, int y);
    
        inline glm::vec3* getPositionCoordinates () { return &this->positionCoordinates; }
        inline glm::vec2* getTextureCoordinates  () { return &this->textureCoordinates; }
        inline glm::vec3* getNormal              () { return &this->normal; }
    
    private:
        glm::vec3 positionCoordinates;
        glm::vec2 textureCoordinates; // coordinates within the texture
        glm::vec3 normal;
};

#endif /* Vertex_hpp */

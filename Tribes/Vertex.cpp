/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Vertex.cpp
 *  ShaderToy
 *
 *
 *  Created by ryan needham on 08/08/2016.
 *  Copyright © 2016 Personal Project. All rights reserved.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Vertex.hpp"

/** 
 *  Vertex Constructor
 *
 *  @param positionCoordinates  the x, y, z coordinates of this vertex
 *  @param textureCoordinates   the x, y, z coordinates of this vertex
 *
 *  Constructs a Vertex object with the x, y, z values
 &  passed in as a gl mathematics library vector 3
 */
Vertex::Vertex (const glm::vec3& positionCoordinates,
                const glm::vec2& textureCoordinates,
                const glm::vec3& normal) {
    this->positionCoordinates = positionCoordinates;
    this->textureCoordinates  = textureCoordinates;
    this->normal              = normal;
}

/** 
 *  Vertex Destructor
 *
 *
 */
Vertex::~Vertex () {

}

/** 
 *  pushValue
 *
 *  @param x    The x value to be assigned to the vertex
 *  @param y    The y value to be assigned to the vertex
 *
 *  Takes two integer values and assigns them to the 
 *  Vertex's state.
 */
void Vertex::pushValue(int x, int y) {
    this->positionCoordinates.x = x;
    this->positionCoordinates.y = y;
}

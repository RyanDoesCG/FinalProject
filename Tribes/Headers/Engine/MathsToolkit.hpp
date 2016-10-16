/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  MathsToolkit.hpp
 *  Tribes
 *
 *  Created by user on 14/10/2016.
 *    Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef MathsToolkit_hpp
#define MathsToolkit_hpp

#include "../GLM/glm.hpp"
#include <iostream>
#include <vector>

/**
 *  MathsToolkit Class
 *
 */
static class MathsToolkit {
    public:
        MathsToolkit  () {}
        ~MathsToolkit ()  {}
    
        /**
         *  Given two points, returns the 3D coordinate of the point
         *  directly between the given points.
         */
        static glm::vec3 getMidPoint (glm::vec3 a, glm::vec3 b) {
            return glm::vec3(
                (a.x + b.x) / 2,
                (a.y + b.y) / 2,
                (a.z + b.z) / 2
            );
        }
    
        static void parseOctohedron (std::vector<GLfloat>* vertices, int lod) {
            int structureSize = vertices->size(); // snapshot initial size
            
            for (int i = 0; i < structureSize; i += 9) {
                parseTriangle (
                    glm::vec3(vertices->at(i + 0),  vertices->at(i + 1),  vertices->at(i + 2)),
                    glm::vec3(vertices->at(i + 3),  vertices->at(i + 4),  vertices->at(i + 5)),
                    glm::vec3(vertices->at(i + 6),  vertices->at(i + 7),  vertices->at(i + 8)),
                    vertices,
                    lod
                );
            }
        }
    
        static void parseTriangle (glm::vec3 a, glm::vec3 b, glm::vec3 c, std::vector<GLfloat>* vertices, int lod) {
            glm::vec3 d = getMidPoint (a, b);
            glm::vec3 f = getMidPoint (b, c);
            glm::vec3 e = getMidPoint (a, c);
            
            vertices->push_back(d.x); vertices->push_back(d.y); vertices->push_back(d.z);
            vertices->push_back(e.x); vertices->push_back(e.y); vertices->push_back(e.z);
            vertices->push_back(f.x); vertices->push_back(f.y); vertices->push_back(f.z);
            
            if (lod > 0) {
                parseTriangle (a, d, e, vertices, lod - 1);
                parseTriangle (d, b, f, vertices, lod - 1);
                parseTriangle (d, e, f, vertices, lod - 1);
                parseTriangle (e, f, c, vertices, lod - 1);
            }
        }
    
        //
        // SOMETHING HERE IS BROKEN
        //
        static void normalizeOctohedron (std::vector<GLfloat>* vertices, int length) {
            for (int i = 0; i < vertices->size(); i += 3) {
                glm::vec3 a = glm::vec3(0, 0, 0);
                glm::vec3 b = glm::vec3(vertices->at(i + 0), vertices->at(i + 1), vertices->at(i + 2));
                
                // get the distance between a and b along the x and y axes
                GLfloat distX = a.x - b.x;
                GLfloat distY = a.y - b.y;
                GLfloat distZ = a.z - b.z;
                
                // right now, sqrt(dx^2 + dy^2) = distance(a,b).
                // we want to modify them so that sqrt(dx^2 + dy^2) = the given length.
                distX = distX * length / sqrt((distX * distX) + (distY * distY) + (distZ * distZ));
                distY = distY * length / sqrt((distX * distX) + (distY * distY) + (distZ * distZ));
                distZ = distZ * length / sqrt((distX * distX) + (distY * distY) + (distZ * distZ));
                
                vertices->at(i + 0) = a.x + distX;
                vertices->at(i + 1) = a.y + distY;
                vertices->at(i + 2) = a.z + distZ;
            }
        }
    
        static void distanceBetween () {
        
        }
};

#endif /* MathsToolkit_hpp */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  MathsToolkit.hpp
 *  Tribes
 *
 *  Created by user on 14/10/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
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
 *  ISSUE:
 *      Parsing code pushes new vertices onto end of vector.
 *      It should expand the vector and insert the new points 
 *      reletive to their parent points position in the structure.
 *
 *
 */
static class MathsToolkit {
    public:
        MathsToolkit  () {}
        ~MathsToolkit () {}
    
        /**
         *  Given two points, returns the 3D coordinate of the point
         *  directly between the given points.
         */
        static glm::vec4 getMidPoint (glm::vec4 a, glm::vec4 b) {
            return glm::vec4(
                (a.x + b.x) / 2,
                (a.y + b.y) / 2,
                (a.z + b.z) / 2,
                b.w
            );
        }
    
    
        /** 
         *  Bug in which triangles are passed to the parseTriangle method?
         */
        static void parseOctohedron (std::vector<GLfloat>* oldVertices, int lod) {
            std::vector<GLfloat> newVertices = {};
            
            for (int i = 0; i < oldVertices->size(); i += 12) {
                parseTriangle (
                    glm::vec4(oldVertices->at(i + 0),  oldVertices->at(i + 1),  oldVertices->at(i + 2),  oldVertices->at(i + 3)),
                    glm::vec4(oldVertices->at(i + 4),  oldVertices->at(i + 5),  oldVertices->at(i + 6),  oldVertices->at(i + 7)),
                    glm::vec4(oldVertices->at(i + 8),  oldVertices->at(i + 9),  oldVertices->at(i + 10), oldVertices->at(i + 11)),
                    &newVertices,
                    lod
                );
            }
            
            //std::cout << std::endl << "NEW SIZE: " << newVertices.size() << std::endl;
            //std::cout << "OLD SIZE: " << oldVertices->size() << std::endl << std::endl;

            oldVertices->clear();            
            oldVertices->insert(oldVertices->begin(), newVertices.begin(), newVertices.end());
        }
    
        /** 
         *  FIX THIS. VERTICES ARE TOO MANY AND SEEM TO BE IN THE WRONG PLACE
         */
        static void parseTriangle (glm::vec4 a, glm::vec4 b, glm::vec4 c, std::vector<GLfloat>* newVertices, int lod) {
        
            glm::vec4 d = getMidPoint (a, b);
            glm::vec4 e = getMidPoint (a, c);
            glm::vec4 f = getMidPoint (b, c);
            
            // Add to new newVertices structure in correct order
            //  a, d, e | e, c, f | d, e, f | b, d, f
            newVertices->push_back(a.x); newVertices->push_back(a.y); newVertices->push_back(a.z); newVertices->push_back(a.w);
            newVertices->push_back(d.x); newVertices->push_back(d.y); newVertices->push_back(d.z); newVertices->push_back(a.w);
            newVertices->push_back(e.x); newVertices->push_back(e.y); newVertices->push_back(e.z); newVertices->push_back(a.w);
            
            newVertices->push_back(e.x); newVertices->push_back(e.y); newVertices->push_back(e.z); newVertices->push_back(e.w);
            newVertices->push_back(c.x); newVertices->push_back(c.y); newVertices->push_back(c.z); newVertices->push_back(e.w);
            newVertices->push_back(f.x); newVertices->push_back(f.y); newVertices->push_back(f.z); newVertices->push_back(e.w);
            
            newVertices->push_back(d.x); newVertices->push_back(d.y); newVertices->push_back(d.z); newVertices->push_back(d.w);
            newVertices->push_back(e.x); newVertices->push_back(e.y); newVertices->push_back(e.z); newVertices->push_back(d.w);
            newVertices->push_back(f.x); newVertices->push_back(f.y); newVertices->push_back(f.z); newVertices->push_back(d.w);
            
            newVertices->push_back(b.x); newVertices->push_back(b.y); newVertices->push_back(b.z); newVertices->push_back(b.w);
            newVertices->push_back(d.x); newVertices->push_back(d.y); newVertices->push_back(d.z); newVertices->push_back(b.w);
            newVertices->push_back(f.x); newVertices->push_back(f.y); newVertices->push_back(f.z); newVertices->push_back(b.w);
            
            if (lod > 0) {
                parseTriangle (a, d, e, newVertices, lod - 1);
                parseTriangle (d, b, f, newVertices, lod - 1);
                parseTriangle (d, e, f, newVertices, lod - 1);
                parseTriangle (e, f, c, newVertices, lod - 1);
            }
        }
    
        static void normalizeOctohedron (std::vector<GLfloat>* vertices, float length) {
            for (int i = 0; i < vertices->size(); i += 4) {
                glm::vec3 a = glm::vec3(0.0, 0.0, 0.0); // center
                glm::vec3 b = glm::vec3(vertices->at(i + 0), vertices->at(i + 1), vertices->at(i + 2));
                
                // get the distance between a and b along the x and y axes
                GLfloat distX = b.x - a.x;
                GLfloat distY = b.y - a.y;
                GLfloat distZ = b.z - a.z;
                
                /** 
                 *  WEIRD SHAPE FIX
                 *
                 *      Previously the sqrt equation was the divisor in the below
                 *      calculations, seen as it changed after every line it caused
                 *      strange shapes to be rendered instead of the sphere
                 */
                GLfloat a_b = sqrt(distX * distX + distY * distY + distZ * distZ);
                
                // right now, sqrt(dx^2 + dy^2) = distance(a,b).
                // we want to modify them so that sqrt(dx^2 + dy^2) = the given length.
                distX = distX * length / a_b;
                distY = distY * length / a_b;
                distZ = distZ * length / a_b;
                
                vertices->at(i + 0) = (a.x + distX);
                vertices->at(i + 1) = (a.y + distY);
                vertices->at(i + 2) = (a.z + distZ);
            }
        }
    
        static void flushVertices (std::vector<GLfloat>* vertices) {
            std::cout << "Vertex Collection: " << std::endl;
           
            for (int i = 1; i < vertices->size(); i++) {
                std::cout << vertices->at(i) << ", ";
                
                if (i % 3 == 0) {
                    std::cout << std::endl;
                }
            }
        }
    
        static void toScreenCoords () {}
    
        static void toNormCoords (float x, float y, int screenWidth, int screenHeight) {}
};

#endif /* MathsToolkit_hpp */

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

#include "../glm/glm.hpp"
#include <iostream>
#include <vector>

static class MathsToolkit {
    public:
        MathsToolkit  () {}
        ~MathsToolkit () {}
    
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
    
        static void parseOctohedron (std::vector<GLfloat>* vertices) {
        
        
            std::vector<glm::vec3> a = parseTriangle(glm::vec3(vertices->at(0),  vertices->at(1),  vertices->at(2)),
                                                     glm::vec3(vertices->at(3),  vertices->at(4),  vertices->at(5)),
                                                     glm::vec3(vertices->at(6),  vertices->at(7),  vertices->at(8)));
            
            
            std::vector<glm::vec3> b = parseTriangle(glm::vec3(vertices->at(9),  vertices->at(10),  vertices->at(11)),
                                                     glm::vec3(vertices->at(12),  vertices->at(13),  vertices->at(14)),
                                                     glm::vec3(vertices->at(15),  vertices->at(16),  vertices->at(17)));
            
            std::vector<glm::vec3> c = parseTriangle(glm::vec3(vertices->at(18),  vertices->at(19),  vertices->at(20)),
                                                     glm::vec3(vertices->at(21),  vertices->at(22),  vertices->at(23)),
                                                     glm::vec3(vertices->at(24),  vertices->at(25),  vertices->at(26)));
            
            // OUT OF RANGE
            std::vector<glm::vec3> d = parseTriangle(glm::vec3(vertices->at(27),  vertices->at(28),  vertices->at(29)),
                                                     glm::vec3(vertices->at(30),  vertices->at(31),  vertices->at(32)),
                                                     glm::vec3(vertices->at(33),  vertices->at(34),  vertices->at(35)));

            std::vector<glm::vec3> e = parseTriangle(glm::vec3(vertices->at(36),  vertices->at(37),  vertices->at(38)),
                                                     glm::vec3(vertices->at(39),  vertices->at(40),  vertices->at(41)),
                                                     glm::vec3(vertices->at(42),  vertices->at(43),  vertices->at(44)));
            
            std::vector<glm::vec3> f = parseTriangle(glm::vec3(vertices->at(45),  vertices->at(46),  vertices->at(47)),
                                                     glm::vec3(vertices->at(48),  vertices->at(49),  vertices->at(50)),
                                                     glm::vec3(vertices->at(51),  vertices->at(52),  vertices->at(53)));
            
            std::vector<glm::vec3> g = parseTriangle(glm::vec3(vertices->at(54),  vertices->at(55),  vertices->at(56)),
                                                     glm::vec3(vertices->at(57),  vertices->at(58),  vertices->at(59)),
                                                     glm::vec3(vertices->at(60),  vertices->at(61),  vertices->at(62)));
            
            std::vector<glm::vec3> h = parseTriangle(glm::vec3(vertices->at(63),  vertices->at(64),  vertices->at(65)),
                                                     glm::vec3(vertices->at(66),  vertices->at(67),  vertices->at(68)),
                                                     glm::vec3(vertices->at(69),  vertices->at(70),  vertices->at(71)));
            
            std::vector<GLfloat> A;
            A.push_back(a.at(0).x);
            A.push_back(a.at(0).y);
            A.push_back(a.at(0).z);
            A.push_back(a.at(1).x);
            A.push_back(a.at(1).y);
            A.push_back(a.at(1).z);
            A.push_back(a.at(2).x);
            A.push_back(a.at(2).y);
            A.push_back(a.at(2).z);
            
            std::vector<GLfloat> B;
            B.push_back(b.at(0).x);
            B.push_back(b.at(0).y);
            B.push_back(b.at(0).z);
            B.push_back(b.at(1).x);
            B.push_back(b.at(1).y);
            B.push_back(b.at(1).z);
            B.push_back(b.at(2).x);
            B.push_back(b.at(2).y);
            B.push_back(b.at(2).z);
        
            std::vector<GLfloat> C;
            C.push_back(c.at(0).x);
            C.push_back(c.at(0).y);
            C.push_back(c.at(0).z);
            C.push_back(c.at(1).x);
            C.push_back(c.at(1).y);
            C.push_back(c.at(1).z);
            C.push_back(c.at(2).x);
            C.push_back(c.at(2).y);
            C.push_back(c.at(2).z);
            
            std::vector<GLfloat> D;
            D.push_back(d.at(0).x);
            D.push_back(d.at(0).y);
            D.push_back(d.at(0).z);
            D.push_back(d.at(1).x);
            D.push_back(d.at(1).y);
            D.push_back(d.at(1).z);
            D.push_back(d.at(2).x);
            D.push_back(d.at(2).y);
            D.push_back(d.at(2).z);
            
            std::vector<GLfloat> E;
            E.push_back(e.at(0).x);
            E.push_back(e.at(0).y);
            E.push_back(e.at(0).z);
            E.push_back(e.at(1).x);
            E.push_back(e.at(1).y);
            E.push_back(e.at(1).z);
            E.push_back(e.at(2).x);
            E.push_back(e.at(2).y);
            E.push_back(e.at(2).z);
            
            std::vector<GLfloat> F;
            F.push_back(f.at(0).x);
            F.push_back(f.at(0).y);
            F.push_back(f.at(0).z);
            F.push_back(f.at(1).x);
            F.push_back(f.at(1).y);
            F.push_back(f.at(1).z);
            F.push_back(f.at(2).x);
            F.push_back(f.at(2).y);
            F.push_back(f.at(2).z);
            
            std::vector<GLfloat> G;
            G.push_back(g.at(0).x);
            G.push_back(g.at(0).y);
            G.push_back(g.at(0).z);
            G.push_back(g.at(1).x);
            G.push_back(g.at(1).y);
            G.push_back(g.at(1).z);
            G.push_back(g.at(2).x);
            G.push_back(g.at(2).y);
            G.push_back(g.at(2).z);
            
            std::vector<GLfloat> H;
            H.push_back(h.at(0).x);
            H.push_back(h.at(0).y);
            H.push_back(h.at(0).z);
            H.push_back(h.at(1).x);
            H.push_back(h.at(1).y);
            H.push_back(h.at(1).z);
            H.push_back(h.at(2).x);
            H.push_back(h.at(2).y);
            H.push_back(h.at(2).z);

            vertices->reserve( A.size() + B.size() + C.size() + D.size() + E.size() + F.size() + G.size() + H.size());
            
            vertices->insert(vertices->end(), A.begin(), A.end());
            vertices->insert(vertices->end(), B.begin(), B.end());
            vertices->insert(vertices->end(), C.begin(), C.end());
            vertices->insert(vertices->end(), D.begin(), D.end());
            vertices->insert(vertices->end(), E.begin(), E.end());
            vertices->insert(vertices->end(), F.begin(), F.end());
            vertices->insert(vertices->end(), G.begin(), G.end());
            vertices->insert(vertices->end(), H.begin(), H.end());
     
        }
    
        // prototype
        static std::vector<glm::vec3> parseTriangle (glm::vec3 a, glm::vec3 b, glm::vec3 c) {

            //      *
            //
            //  *       *
            //
            // figure out all the mid points in this triangle
            glm::vec3 d = getMidPoint (a, b);
            glm::vec3 e = getMidPoint (a, c);
            glm::vec3 f = getMidPoint (b, c);
            
            std::vector<glm::vec3> output = {d, e, f};
            
            return output;
            
            //      *
            //    *   *
            //  *   *   *
            //
            // recursivly parse these triangles
            //parseTriangle (a, d, e);
            //parseTriangle (d, b, f);
            //parseTriangle (d, e, f);
            //parseTriangle (e, f, c);
            
        }
    
        static void normalizeOctohedron (std::vector<GLfloat>* vertices) {
        
            for (int i = 0; i < vertices->size(); i += 3) {
                std::cout << "NYA\n";
                glm::vec3 bucket = glm::normalize(glm::vec3(vertices->at(i), vertices->at(i + 1), vertices->at(i + 2)));
                
                vertices->at(i)     = bucket.x;
                vertices->at(i + 1) = bucket.y;
                vertices->at(i + 2) = bucket.z;
            }
        }
};

#endif /* MathsToolkit_hpp */

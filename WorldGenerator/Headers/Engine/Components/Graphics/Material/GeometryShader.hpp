//
//  GeometryShader.hpp
//  WorldGenerator
//
//  Created by user on 16/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef GeometryShader_hpp
#define GeometryShader_hpp

#include "Shader.hpp"

/**
 * A shader with a vertex -> geometry -> fragment pipeline
 */
class GeometryShader : public Shader {
    public:
        GeometryShader (std::string name);
       ~GeometryShader ();
    
    private:
        GLuint vertexShaderID;
        GLuint geometryShaderID;
        GLuint fragmentShaderID;
};

#endif /* GeometryShader_hpp */

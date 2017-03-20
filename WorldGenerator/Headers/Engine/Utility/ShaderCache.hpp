//
//  ShaderCache.hpp
//  WorldGenerator
//
//  Created by user on 19/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef ShaderCache_hpp
#define ShaderCache_hpp

#include "GeometryShader.hpp"
#include "BasicShader.hpp"
#include <vector>

class ShaderCache {
public:
    static BasicShader* loadBasicShader (std::string path) {
        static std::vector<BasicShader*> cache = std::vector<BasicShader*>();
        
        // check the cache for the shader
        for (BasicShader* s : cache)
            if (s->getTitle() == path) return s;
        
        // shader not in memory, make it
        cache.push_back(new BasicShader(path));
        return cache.back();
    }
    
    static GeometryShader* loadGeometryShader (std::string path) {
        static std::vector<GeometryShader*> cache = std::vector<GeometryShader*>();
        
        for (GeometryShader* s : cache)
            if (s->getTitle() == path) return s;

        cache.push_back(new GeometryShader(path));
        return cache.back();
    }
};

#endif /* ShaderCache_hpp */

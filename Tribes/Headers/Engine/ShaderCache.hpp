/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  ShaderCache.hpp
 *  Tribes
 *
 *  Created by ryan needham on 19/10/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef ShaderCache_hpp
#define ShaderCache_hpp

#include "ShaderComponent.hpp"
#include <vector>

class ShaderCache {
public:
    static ShaderComponent* loadShaderComponent (std::string path) {
        static std::vector<ShaderComponent*> cache = std::vector<ShaderComponent*>();
        
        for (int i = 0; i < cache.size(); i++) {
            if (cache.at(i)->getTitle() == path) {
                // Shader in memory, return reference
                return cache.at(i);
            }
        }
        
        // shader not in memory, make it
        cache.push_back(new ShaderComponent(path));
        return cache.back();
    }
};

#endif

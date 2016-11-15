/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  ShaderCache.hpp
 *  Tribes
 *
 *  Created by ryan needham on 19/10/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "ShaderComponent.hpp"
#include <iostream>
#include <vector>

class ShaderCache {
public:
    static ShaderComponent* loadShaderComponent (std::string path) {
        static std::vector<ShaderComponent*> cache = std::vector<ShaderComponent*>();
        
        for (int i = 0; i < cache.size(); i++) {
            if (cache.at(i)->getTitle() == path) {
                return cache.at(i);
            }
        }
        
        // shader not already in memory
        cache.push_back(new ShaderComponent(path));
        return cache.back();
    }
};

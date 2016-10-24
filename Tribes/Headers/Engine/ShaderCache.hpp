/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  ShaderCache.hpp
 *  Tribes
 *
 *  Created by ryan needham on 19/10/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Shader.hpp"
#include <iostream>
#include <vector>

class ShaderCache {
public:
    static Shader* loadShader (std::string path) {
        static std::vector<Shader*> cache = std::vector<Shader*>();
        
        for (int i = 0; i < cache.size(); i++) {
            if (cache.at(i)->getProgramTitle() == path) {
                return cache.at(i);
            }
        }
        
        // shader not already in memory
        cache.push_back(new Shader(path));
        return cache.back();
        }
};

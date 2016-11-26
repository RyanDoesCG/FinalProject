/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  TextureCache.hpp
 *  Tribes
 *
 *  Created by ryan needham on 19/10/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef TEXTURECACHE_HPP
#define TEXTURECACHE_HPP

#include "Texture.hpp"
#include <iostream>
#include <vector>

class TextureCache {
public:
    static Texture* loadTexture (std::string path) {
        static std::vector<Texture*> cache = std::vector<Texture*>();
        
        for (int i = 0; i < cache.size(); i++) {
            if (cache.at(i)->getTextureTitle() == path) {
                return cache.at(i);
            }
        }
        
        // Texture not already in memory
        cache.push_back(new Texture(path));
        return cache.back();
    }
};

#endif

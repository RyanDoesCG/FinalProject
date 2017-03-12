//
//  ModelGeometry.hpp
//  WorldGenerator
//
//  Created by user on 12/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef ModelGeometry_hpp
#define ModelGeometry_hpp

#include "Geometry.hpp"

// ASSIMP Includes
#include "Importer.hpp"
#include "scene.h"
#include "postprocess.h"

class ModelGeometry: public Geometry {
    public:
        ModelGeometry (const std::string& path);
       ~ModelGeometry ();
    
        void loadModel   (std::string path);
        void processNode (aiNode* node, const aiScene* scene);
        void processMesh (aiMesh* mesh, const aiScene* scene);
    
};

#endif /* ModelGeometry_hpp */

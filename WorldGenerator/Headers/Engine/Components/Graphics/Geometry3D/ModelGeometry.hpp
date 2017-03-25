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
    
        std::string getPath ();
    
    private:
        void loadModel   (std::string path);
    
        std::string filepath;
};

#endif /* ModelGeometry_hpp */

//
//  Water.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 28/01/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "../../Headers/Engine/Actors/Water.hpp"

Water::Water () : Model("sphere/sphereDETAILED") {
    setShader("water", GEOM);
    setScale(2);
    
    for (int i = 0; i < Model::meshes.at(0).vertices.size(); i++) {
        float colourVal = rand() % 4;
        Model::meshes.at(0).vertices.at(i).noise.x = colourVal;
        Model::meshes.at(0).vertices.at(i).noise.y = colourVal;
        Model::meshes.at(0).vertices.at(i).noise.z = colourVal;
    }
    
    Model::meshes.at(0).updateModelMesh();
}

Water::~Water () {
    
}

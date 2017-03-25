//
//  ModelGeometry.cpp
//  WorldGenerator
//
//  Created by user on 12/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "ModelGeometry.hpp"
#include "ModelCache.hpp"
#include <iostream>

ModelGeometry::ModelGeometry (const std::string& path) {
    loadModel("Assets/models/" + path + ".obj");
    filepath = std::string("Assets/models/" + path + ".obj");
    Geometry::setup();
}

ModelGeometry::~ModelGeometry () {}

std::string ModelGeometry::getPath() {
    return filepath;
}

void ModelGeometry::loadModel(std::string path) {
    Model* model = ModelCache::loadModelGeometry(path);

    vertices = model->first;
    indices  = model->second;
}

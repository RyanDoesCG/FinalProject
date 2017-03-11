//
//  GraphicsEngine.cpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "GraphicsEngine.hpp"

GraphicsEngine::GraphicsEngine (float width, float height) {
    camera = new Camera(width / height);
}

GraphicsEngine::~GraphicsEngine () {
    
}

void GraphicsEngine::add(GraphicsObject *object) {
    scene.push_back(object);
}

void GraphicsEngine::render() {
    // draw scene
    for (int i = 0; i < scene.size(); i++)
        scene.at(i)->draw(camera);
}

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

GraphicsEngine::~GraphicsEngine () {}

void GraphicsEngine::add(GraphicsObject *object) {
    scene.push_back(object);
}

void GraphicsEngine::render() {
    std::sort(scene.begin(), scene.end(),
        [] (GraphicsObject* a, GraphicsObject* b) -> bool {
            return a->position.z < b->position.z;
        }
    );
    
    camera->update();
    
    // draw scene
    for (GraphicsObject* object : scene)
        object->draw(camera);
}

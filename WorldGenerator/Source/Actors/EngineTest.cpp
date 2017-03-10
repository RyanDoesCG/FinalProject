//
//  EngineTest.cpp
//  WorldGenerator
//
//  Created by user on 10/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//
#include "QuadGeometry.hpp"
#include "EngineTest.hpp"

EngineTest::EngineTest (GraphicsEngine* g) {
    triangle = new GraphicsObject(QuadGeometry(), Material("object"));
    g->add(triangle);
}

EngineTest::~EngineTest () {
    
}

void EngineTest::update() {
    
}

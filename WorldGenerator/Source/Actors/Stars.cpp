//
//  Stars.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 01/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "../../Headers/Engine/Actors/Stars.hpp"
#include "../../Headers/Engine/Utility/BetterRand.hpp"

Stars::Stars() {
    star = Cube();
    
    starCount = 1000;
    
    star.setShader("unlitObject", BASIC);
    star.setColour(vec3(0.93f, 0.9f, 0.93f));
    star.setScale(0.1);
    for (int i = 0; i < starCount; i++) {
        starFlyweightTransforms.push_back(glm::vec3(betterRand() * 200, betterRand() * 200, betterRand() * 200));
    }
}

Stars::~Stars() {
    
}

void Stars::draw(SceneCamera *camera) {
    for (int i = 0; i < starCount; i++) {
        star.setPosition(starFlyweightTransforms.at(i));
        star.update(RUNNING_FREEMODE);
        star.draw(camera);
    }
}

void Stars::update(GameState state) {
    star.update(state);
}

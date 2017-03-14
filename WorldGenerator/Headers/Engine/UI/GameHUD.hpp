//
//  GameHUD.hpp
//  WorldGenerator
//
//  Created by user on 11/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef GameHUD_hpp
#define GameHUD_hpp

#include "GameObject.hpp"

#include "GraphicsEngine.hpp"
#include "PhysicsEngine.hpp"
#include "InputManager.hpp"

#include "UIBoxBackground.hpp"
#include "UIBox.hpp"

class GameHUD: public GameObject {
    public:
        GameHUD (GraphicsEngine* graph, PhysicsEngine* phys): background(graph), back(graph, phys) {
            // backdrop
            background.scaleTo(glm::vec3(1.5, 3, 0.0));
            background.moveTo(glm::vec3(-2, 0.0, 0.1));
                
            // back button
            items.push_back(&back);
            items.at(0)->scaleTo(glm::vec3(0.5, 0.15, 0));
            items.at(0)->moveTo(glm::vec3(-2.075, -1.25, 0.2));
            items.at(0)->update(MENU);
                
            // input
            gamepad = InputManager::getGamepadHandle();
            mouse = InputManager::getMouseHandle();
        }
    
       ~GameHUD () {}
    
        virtual void update (State state) override = 0;
    
        virtual void hide () = 0;
        virtual void show () = 0;
    
        UIBox back;
    
    protected:
        UIBoxBackground background;
        std::vector<UIBox*> items;
    
        Gamepad* gamepad;
        Mouse* mouse;
};

#endif /* GameHUD_hpp */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  MainMenu.cpp
 *  Tribes
 *
 *  Created by user on 29/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/UI/MainMenu.hpp"
#include "../../Headers/Engine/UI/OptionsMenu.hpp"
#include "../../Headers/Engine/UI/LoadMenu.hpp"
#include "../../Headers/Engine/UI/SeedMenu.hpp"

MainMenu::MainMenu (float width, float height, Game* game):
    Menu(width, height, game) {
    /*
    // QUIT
    quit.label      = "quit";
    quit.index      = items.size();
    items.push_back(quit);
    
    // OPTIONS
    options.label   = "options";
    options.index   = items.size();
    options.menu    = new OptionsMenu(width, height, game);
    children.push_back(options.menu);
    items.push_back(options);

    // LOAD GAME
    loadGame.label  = "load game";
    loadGame.index  = items.size();
    loadGame.menu   = new LoadMenu(width, height, game);
    children.push_back(loadGame.menu);
    items.push_back(loadGame);
    
    // NEW GAME
    newGame.label   = "new game";
    newGame.index   = items.size();
    newGame.menu    = new SeedMenu(width, height, game);
    children.push_back(newGame.menu);
    items.push_back(newGame);

    selectedItem = items.size()-1;
     */
    //qshow();
}

MainMenu::~MainMenu () {
    
}

void MainMenu::handleEvents() {
    /*
    Menu::handleEvents();
    
    if (!isHidden) {
        // select
        if (keyboard->isKeyDown(GLFW_KEY_ENTER) ||
            gamepad->isButtonDown(GAMEPAD_BUTTON_A)) {
            switch (selectedItem) {
                case 0: game->end(); break;
                case 1: options.menu->show(); hide(); break;
                case 2: loadGame.menu->show(); hide(); break;
                case 3: newGame.menu->show(); hide(); break;
            }
            
            keyboard->keyHandled(GLFW_KEY_ENTER);
            gamepad->buttonHandled(GAMEPAD_BUTTON_A);
        }
    }
    
    // back
    if (keyboard->isKeyDown(GLFW_KEY_ESCAPE)    ||
        gamepad->isButtonDown(GAMEPAD_BUTTON_B) ||
        gamepad->isButtonDown(GAMEPAD_SPECIAL_HOME)) {
        for (int i = 0; i < children.size(); i++) { children[i]->hide(); }
        show();
        
        keyboard->keyHandled(GLFW_KEY_ESCAPE);
        gamepad->buttonHandled(GAMEPAD_BUTTON_B);
        gamepad->buttonHandled(GAMEPAD_SPECIAL_HOME);
    }
     */
}

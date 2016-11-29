//
//  MainMenu.cpp
//  Tribes
//
//  Created by user on 29/11/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//

#include "../Headers/Engine/MainMenu.hpp"
#include "../Headers/Engine/OptionsMenu.hpp"
#include "../Headers/Engine/LoadMenu.hpp"
#include "../Headers/Engine/SeedMenu.hpp"

MainMenu::MainMenu (float width, float height, Game* game):
    Menu(width, height, game) {
    
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
    show();
}

MainMenu::~MainMenu () {
    
}

void MainMenu::handleEvents() {
    Menu::handleEvents();
    
    if (!isHidden) {
        // select
        if (keyboard->isKeyDown(GLFW_KEY_ENTER)) {
            switch (selectedItem) {
                case 0: game->end(); break;
                case 1: options.menu->show(); hide(); break;
                case 2: loadGame.menu->show(); hide(); break;
                case 3: newGame.menu->show(); hide(); break;
            }
            
            keyboard->keyHandled(GLFW_KEY_ENTER);
        }
    }
    
    // back
    if (keyboard->isKeyDown(GLFW_KEY_ESCAPE)) {
        for (int i = 0; i < children.size(); i++) { children[i]->hide(); }
        show();
    }
}

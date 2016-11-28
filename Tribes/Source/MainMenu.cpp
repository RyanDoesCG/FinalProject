/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  MainMenu.cpp
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/MainMenu.hpp"

MainMenu::MainMenu (float width, float height) {
    
    // QUIT
    quit.label      = "quit";
    quit.index      = 0;
    items.push_back(quit);
    
    // OPTIONS
    options.label   = "options";
    options.index   = 1;
    items.push_back(options);
    
    optionsSub = SubMenu(width, height);
    children.push_back(optionsSub);

    // LOAD GAME
    loadgame.label  = "load game";
    loadgame.index  = 2;
    items.push_back(loadgame);
    
    loadgameSub = SubMenu(width, height);
    children.push_back(loadgameSub);
    
    // NEW GAME
    newgame.label   = "new game";
    newgame.index   = 3;
    items.push_back(newgame);
    
    newgameSub = SubMenu(width, height);
    children.push_back(newgameSub);
    
    // ADMIN
    windowWidth  = width;
    windowHeight = height;
    bassline     = height * 0.28;
    textPipeline = new TextRenderingComponent();
    isHidden     = true;
    
    selectedItem = newgame.index;
}

MainMenu::~MainMenu () {
    
}

void MainMenu::hide () {isHidden = true;}
void MainMenu::show () {isHidden = false;}

void MainMenu::update () {

    /* *
     *  Unlike sub menus, a main menu must listen to events
     *  even when it isn't shown.
     */
    handleEvents();

    if (!isHidden) {
        for (int i = items.size()-1; i >= 0; i--) {
            glm::vec2 position = glm::vec2(40, bassline + (10 * (12 * items[i].index)));
            
            if (i == selectedItem)
                textPipeline->renderTextAs2D(items[i].label, position, glm::vec3(0.75, 0.75, 0.75), 0.72);
            else
                textPipeline->renderTextAs2D(items[i].label, position, glm::vec3(0.32, 0.32, 0.32), 0.6);
        }
        
        textPipeline->update();
    }
    
    // update sub menus
    for (int i = 0; i < children.size(); i++) {
        children[i].update();
    }
}

void MainMenu::handleEvents () {
    if (!isHidden) {
        // scroll up
        if (keyboard->isKeyDown(GLFW_KEY_W) || keyboard->isKeyDown(GLFW_KEY_UP)) {
            selectedItem = (selectedItem + 1) % items.size();
            
            keyboard->keyHandled(GLFW_KEY_W);
            keyboard->keyHandled(GLFW_KEY_UP);
        }
        
        // scroll down
        if (keyboard->isKeyDown(GLFW_KEY_S) || keyboard->isKeyDown(GLFW_KEY_DOWN)) {
            if (selectedItem == 0) selectedItem = items.size()-1;
            else selectedItem -= 1;
            
            keyboard->keyHandled(GLFW_KEY_S);
            keyboard->keyHandled(GLFW_KEY_DOWN);
        }
        
        // select
        if (keyboard->isKeyDown(GLFW_KEY_ENTER)) {
            switch (selectedItem) {
                case 0:
                    std::cout << "quit" << std::endl;
                    break;
                case 1:
                    optionsSub.show();
                    hide();
                    break;
                case 2:
                    loadgameSub.show();
                    hide();
                    break;
                case 3:
                    newgameSub.show();
                    hide();
                    break;
            }
            
            keyboard->keyHandled(GLFW_KEY_ENTER);
        }
    }
    
    // back
    if (keyboard->isKeyDown(GLFW_KEY_ESCAPE)) {
        //for (int i = 0; i < children.size(); i++) { children[i].hide(); }
    
        show();
        
        keyboard->keyHandled(GLFW_KEY_ESCAPE);
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Menu.cpp
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/UI/Menu.hpp"
#include "../../Headers/Engine/Core/Game.hpp"

Menu::Menu (float width, float height, Game* game) {

    windowWidth  = width;
    windowHeight = height;
    textPipeline = new TextRenderingComponent();
    bassline     = height * 0.16;
    this->game   = game;
    
    hide();
    
    selectedItem = items.size() - 1;
    
}

Menu::~Menu () {
    
}

void Menu::hide () {isHidden = true;}
void Menu::show () {isHidden = false;}

void Menu::update () {

    /* *
     *  Unlike sub menus, a main menu must listen to events
     *  even when it isn't shown.
     */
    handleEvents();
    
    if (!isHidden) {
        for (int i = items.size()-1; i >= 0; i--) {
            glm::vec2 position = glm::vec2(84, bassline + (10 * (12 * items[i].index)));
            
            if (i == selectedItem)
                textPipeline->renderTextAs2D(items[i].label, position, glm::vec3(0.75, 0.75, 0.75), 0.72);
            else
                textPipeline->renderTextAs2D(items[i].label, position, glm::vec3(0.32, 0.32, 0.32), 0.6);
        }
        
        textPipeline->update();
    }
    
    // update sub menus
    for (int i = 0; i < children.size(); i++) {
        children[i]->update();
    }
}

void Menu::handleEvents () {
    if (!isHidden) {
        
        if (keyboard->isKeyDown(GLFW_KEY_W)  ||
            keyboard->isKeyDown(GLFW_KEY_UP) ||
            gamepad->isButtonDown(GAMEPAD_DPAD_UP)) {
            // scroll up
            selectedItem = (selectedItem + 1) % items.size();
            keyboard->keyHandled(GLFW_KEY_W);
            keyboard->keyHandled(GLFW_KEY_UP);
            gamepad->buttonHandled(GAMEPAD_DPAD_UP);
        }
        
        if (keyboard->isKeyDown(GLFW_KEY_S)     ||
            keyboard->isKeyDown(GLFW_KEY_DOWN)  ||
            gamepad->isButtonDown(GAMEPAD_DPAD_DOWN)) {
            // scroll down
            if (selectedItem == 0) selectedItem = items.size()-1;
            else selectedItem -= 1;
            keyboard->keyHandled(GLFW_KEY_S);
            keyboard->keyHandled(GLFW_KEY_DOWN);
            gamepad->buttonHandled(GAMEPAD_DPAD_DOWN);
        }
        
        if (keyboard->isKeyDown(GLFW_KEY_ESCAPE) ||
            gamepad->isButtonDown(GAMEPAD_BUTTON_B)) {
            // back
            for (int i = 0; i < children.size(); i++) { children[i]->hide(); }
            hide();
            keyboard->keyHandled(GLFW_KEY_ESCAPE);
            gamepad->buttonHandled(GAMEPAD_BUTTON_B);
        }
    }
}
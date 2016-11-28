/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  SubMenu.cpp
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Headers/Engine/SubMenu.hpp"

SubMenu::SubMenu (float width, float height) {
    
    windowWidth  = width;
    windowHeight = height;
    bassline     = height * 0.28;
    textPipeline = new TextRenderingComponent();
    isHidden     = true;

    selectedItem = items.size()-1;
}

SubMenu::~SubMenu () {
    
}

void SubMenu::hide () { isHidden = true;}
void SubMenu::show () { isHidden = false;selectedItem = items.size()-1;}

void SubMenu::addItem(std::string item) {
    MenuItem holder;
    holder.label = item;
    holder.index = items.size();
    items.push_back(holder);
}

void SubMenu::removeItem(std::string item) {
    
}

void SubMenu::update () {
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
}

void SubMenu::handleEvents () {
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
                case 0: break;
                case 1: break;
                case 2: break;
                case 3: break;
            }
            
            keyboard->keyHandled(GLFW_KEY_ENTER);
    }
}

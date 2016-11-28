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
    //isHidden     = true;
    
    addItem("test 1");
    addItem("test 2");
    
    selectedItem = items.size()-1;
}

SubMenu::~SubMenu () {
    
}

void SubMenu::hide () { isHidden = true; std::cout << "hide" << std::endl;}
void SubMenu::show () { isHidden = false; std::cout << "show" << std::endl;}

void SubMenu::addItem(std::string label) {
    MenuItem item;
    item.label = label;
    item.index = items.size();
    items.push_back(item);
}

void SubMenu::removeItem(std::string label) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i].label == label) {
            items.erase(items.begin() + i);
            return; // found item, no need to carry on
        }
    }
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
        
        std::cout << "called" << std::endl;
    }
}

void SubMenu::handleEvents () {
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
                case 0: break;
                case 1: break;
                case 2: break;
                case 3: break;
            }
            
            keyboard->keyHandled(GLFW_KEY_ENTER);
        }
    }
}
